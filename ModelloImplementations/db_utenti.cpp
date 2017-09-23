#include "ModelloHeaders/db_utenti.h"
#include <vector>
#include "ModelloHeaders/utente.h"
#include <QXmlStreamWriter>
#include <QFile>
#include "ModelloHeaders/errnovalidindex.h"
#include <qmessagebox.h>
#include "ModelloHeaders/err.h"
#include <iostream>
#include "ModelloHeaders/errxml.h"
#include "ModelloHeaders/errchiave.h"

DB_utenti::DB_utenti(){
    LoadDB();
    presenzaAdmin();
}

DB_utenti::~DB_utenti(){
    SaveDB();
    std::vector<Utente*>::const_iterator it = account.begin();
    for(;it!= account.end(); it++) delete (*it);

}

std::string DB_utenti::file="listaUtenti.xml";

void DB_utenti::presenzaAdmin(){
    //controlla se admin e' presente
    //in caso non lo sia lo inserisce.
    Utente* ut = NomeToPunt("admin");
    if (!ut) {
        Capo admin = Capo("admin","pass");
        nuovoUtente(admin);
        SaveDB();
    }
}

DB_utenti::DB_utenti (const DB_utenti& cp){
    std::vector<Utente*>::const_iterator it = cp.account.begin();
    for (;it!= cp.account.end(); it++){
        Utente* clone = (*it)->clona();
        account.push_back(clone);
    }
}

const Utente& DB_utenti::operator[] (unsigned int i) const{
    return *(account[i]);
}
Utente& DB_utenti::operator[] (unsigned int i){
    return *(account[i]);
}

DB_utenti& DB_utenti::operator= (const DB_utenti& cp){
    if (this != &cp){
        std::vector<Utente*>::const_iterator i = account.begin();
        for (;i!= account.end(); i++) delete *i;
        account.clear();


        std::vector<Utente*>::const_iterator it = cp.account.begin();
        for (;it!= cp.account.end(); it++){
            Utente* clone = (*it)->clona();
            account.push_back(clone);
        }

    }
    return *this;
}
int DB_utenti::NumeroUtenti() const{ return account.size();}

void DB_utenti::nuovoUtente( const Utente& ut){
    Utente * p= NomeToPunt(ut.getNome());
    if (p) throw ErrChiave();
    else account.push_back((&ut)->clona());
}
void DB_utenti::changeTipo (std::string nome){
    Utente * p= NomeToPunt(nome);
    if (!p) throw ErrNoValidIndex();
    std::string tipo = p->getTipo();
    std::string pass= p->getPass();

    eliminaUtente(nome);

    if (tipo=="Capo")nuovoUtente(Operaio(nome,pass));
    else nuovoUtente(Capo(nome,pass));
}


const Utente* DB_utenti::verifica(std::string name, std::string key) const{

    bool verificato = false;

    Utente* p = NomeToPunt(name);
    if (p) {
        if (p->getPass()==key) verificato =true;
    }

    if(verificato) return p ;
    else return nullptr;
}

Utente* DB_utenti::NomeToPunt(std::string nome) const{
    //ritorna il puntatore nullo se il nome non c'e' fra gli account
    Utente* c = nullptr;
    std::vector<Utente*>::const_iterator it=account.begin();
    for (; it!= account.end() && !c; it++){
        if ((*it)->getNome() == nome)
            c = *it;
    }
    return c;
}
void DB_utenti::cambiaNome(std::string nome,std::string nuovo) const{
    Utente* p = NomeToPunt(nome);
    Utente* n= NomeToPunt(nuovo);
    if (n && n->getNome()!=nome) throw ErrChiave();
    if (p) p->changeNome(nuovo);
    else throw ErrNoValidIndex();
}
void DB_utenti::cambiaPass(std::string nome,std::string nuovo) const{
    Utente* p = NomeToPunt(nome);
    if (p) p->changePass(nuovo);
    else throw ErrNoValidIndex();
}
std::string DB_utenti::getPass(std::string nome)const{
    Utente* p = NomeToPunt(nome);
    if (p) return p->getPass();
    else throw ErrNoValidIndex();
}
std::string DB_utenti::getTipo(std::string nome) const{
    Utente* p = NomeToPunt(nome);
    if (p) return p->getTipo();
    else throw ErrNoValidIndex();
}

void DB_utenti::SaveDB() const{
    QFile* File=new QFile(QString::fromStdString(file));
    QXmlStreamWriter* ScriviUtente= new QXmlStreamWriter(File);

    if(File->open(QIODevice::ReadWrite)){

        ScriviUtente->setAutoFormatting(true);
        ScriviUtente->writeStartDocument();
        ScriviUtente->writeStartElement(QString::fromStdString(file));

        std::vector<Utente*>::const_iterator it=account.begin();
        for (; it!= account.end() ; it++){

            (*it)->SalvaInfoUtente(*ScriviUtente);

        }

        ScriviUtente->writeEndElement();
        ScriviUtente->writeEndDocument();
        File->close();


    }
    delete ScriviUtente;
    delete File;
}


void DB_utenti::LoadDB() {
    QFile* File=new QFile(QString::fromStdString(file));

    if(File->open(QIODevice::ReadWrite))
     {
        QXmlStreamReader* lett= new QXmlStreamReader(File);
        while (!lett->atEnd()){
            if (lett->isStartElement()){

                try{
                    if (lett->name()=="Operaio") nuovoUtente( *Operaio::LeggiUtente(*lett));
                    if (lett->name()=="Capo")  nuovoUtente( *Capo::LeggiUtente(*lett));
                }
                catch (ErrXML E) {} //ignora e vai avanti
                lett->readNext();
            }
            else lett->readNext();

        }
        File->close();

        delete lett;
    }
    delete File;
}
const Utente& DB_utenti::operator[] (std::string i) const{
    Utente* p= NomeToPunt(i);
    if (p) return *p;
    else throw ErrNoValidIndex();
}
Utente& DB_utenti::operator[] (std::string i){
    Utente* p= NomeToPunt(i);
    if (p) return *p;
    else throw ErrNoValidIndex();
}
void DB_utenti::eliminaUtente(std::string nome){
    bool eliminazione=false;
    std::vector<Utente*>::const_iterator it=account.begin();
    for (; it!= account.end() && !eliminazione; it++){
        if ((*it)->getNome() == nome){
            eliminazione=true;
            delete *it;
            account.erase(it);
        }
    }
    if (!eliminazione) throw ErrNoValidIndex();

}
std::string DB_utenti::getNome(unsigned int i) const{
    if (i>= account.size()) throw ErrNoValidIndex();
    return account[i]->getNome();
}
