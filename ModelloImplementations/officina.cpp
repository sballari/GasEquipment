#include "ModelloHeaders/officina.h"
#include "ModelloHeaders/veicolo.h"
#include <vector>
#include "ModelloHeaders/err.h"
#include "ModelloHeaders/errchiave.h"
#include "ModelloHeaders/errnovalidindex.h"
#include "ModelloHeaders/errnoiniettore.h"
#include "qfile.h"
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QMessageBox>
#include "ModelloHeaders/omegagpl.h"
#include "ModelloHeaders/nocatgpl.h"
#include "ModelloHeaders/errxml.h"
#include "ModelloHeaders/directgpl.h"
#include "ModelloHeaders/maticgpl.h"

Officina::Officina(){
    Carica();
}

std::string Officina::file="officina.xml";

std::vector<Veicolo*>::const_iterator Officina::trova(std::string tg)const{
    std::vector<Veicolo*>::const_iterator it = autogestite.begin();
    std::vector<Veicolo*>::const_iterator ob;
    bool tr=false;
    for(; it< autogestite.end() && !tr; it++){
        if ((*it)->getTarga() == tg) {tr=true; ob=it;}
    }
    if (tr) return ob;
    else throw ErrNoValidIndex();
}

void Officina::insertVeicolo(const Veicolo& inst){
    //la targa e' chiave primaria
    if (CheckAssenza(inst.getTarga())) {autogestite.push_back(inst.clona()); Salva();}
    else throw ErrChiave();
}

bool Officina::CheckAssenza(std::string tg) const {
    bool assenza=false;
    std::vector<Veicolo*>::const_iterator it;
    try{
        it=trova(tg);
    }
    catch(ErrNoValidIndex e){
        assenza=true;
    };
    return assenza;

}


Officina::Officina(const Officina& c){

    std::vector<Veicolo*>::const_iterator it = c.autogestite.begin();
    for(; it!= c.autogestite.end(); it++)
        autogestite.push_back((*it)->clona());

}

Officina& Officina::operator=(const Officina& c){

    if (this!=&c){
        std::vector<Veicolo*>::const_iterator i = autogestite.begin();
        for (; i!= autogestite.end(); i++) delete (*i);

        autogestite.clear(); // svuoto

        std::vector<Veicolo*>::const_iterator it = c.autogestite.begin();
        for(; it!= c.autogestite.end(); it++)
            autogestite.push_back((*it)->clona()); //riempio
    }
    return *this;
}
Officina::~Officina(){
    Salva();
    std::vector<Veicolo*>::const_iterator i = autogestite.begin();
    for (; i!= autogestite.end(); i++) delete (*i);
}
unsigned int Officina::NAutoGestite() const{
    return autogestite.size();
}
const Veicolo& Officina::operator[] (unsigned int i) const{
    if (i<autogestite.size())
        return *(autogestite[i]);
    else throw ErrNoValidIndex();
}

Veicolo& Officina::operator[] (unsigned int i) {
    if (i<autogestite.size())
        return *(autogestite[i]);
    else throw ErrNoValidIndex();
}

const Veicolo& Officina::operator[] (std::string targa) const{
    bool assenza = true;
    Veicolo * ret;
    std::vector<Veicolo*>::const_iterator i = autogestite.begin();
    for (; i!= autogestite.end() && assenza; i++) {
        if ((*i)->getTarga() == targa){
            assenza = false;
            ret = *i;
        }
    }
    if (assenza) throw ErrNoValidIndex();
    else return *ret;


}
Veicolo& Officina::operator[] (std::string targa) {
    bool assenza = true;
    Veicolo * ret;
    std::vector<Veicolo*>::const_iterator i = autogestite.begin();
    for (; i!= autogestite.end() && assenza; i++) {
        if ((*i)->getTarga() == targa){
            assenza = false;
            ret = *i;
        }
    }
    if (assenza) throw ErrNoValidIndex();
    else return *ret;


}

void Officina::Salva() const{
    QFile* File=new QFile(QString::fromStdString(file));
    QXmlStreamWriter* x= new QXmlStreamWriter(File);

    if(File->open(QIODevice::ReadWrite)) {

        x->setAutoFormatting(true);
        x->writeStartDocument();
        x->writeStartElement("Officina");


        std::vector<Veicolo*>::const_iterator i = autogestite.begin();
        for (; i!= autogestite.end(); i++)
            (*i)->Salva(*x);


        x->writeEndElement();
        x->writeEndDocument();
        File->close();


    }
    delete x;
    delete File;

}

std::string Officina::getTarga(unsigned int pos) const{
    std::string targa;
    try {
        targa =  (operator[](pos)).getTarga();
    }
    catch (ErrNoValidIndex E) {throw E;}

    return targa;
}

std::string Officina::getInfo(unsigned int pos) const{
    std::string info;
    try {
        info= (operator[](pos)).getInfo();
    }
    catch (ErrNoValidIndex E) {throw E;}
    return info;
}

std::string Officina::getInfo(std::string targa) const{
    std::string info;
    try {
        info= (operator[](targa)).getInfo();
    }
    catch (ErrNoValidIndex E) {throw E;}
    return info;
}

void Officina::Carica() {
    QFile* File=new QFile(QString::fromStdString(file));
    if (!File->exists()){
        Salva();
    }
    else {

        if(File->open(QIODevice::ReadWrite)){
            QXmlStreamReader* lett= new QXmlStreamReader(File);

            while (!lett->atEnd()){
                if (lett->isStartElement()){



                    if (lett->name()=="Installazione")  {
                        try{
                            Installazione* a=Installazione::Leggi(*lett);
                            insertVeicolo(*a);
                            delete a;
                        }
                        catch (ErrXML E) {};
                    }
                    if (lett->name()=="Veicolo")  {
                        try{
                            Veicolo* a=Veicolo::Leggi(*lett);
                            insertVeicolo(*a);
                            delete a;
                        }
                        catch (ErrXML E) {};
                    }

                    lett->readNext();
                }
                else lett->readNext();

            }
            File->close();

            delete lett;
        }
    }
    delete File;
}

void Officina::RimuoviVeicolo(std::string tg){
    try{
        auto i=trova(tg);
        delete *i;
        autogestite.erase(i);
        Salva();
    }
    catch (ErrNoValidIndex e){throw e;}
}

std::vector<Veicolo*> Officina::RicercaPerProp(std::string prop, bool alert) const{
    std::vector<Veicolo*> selezione;
    std::vector<Veicolo*>::const_iterator it=autogestite.begin();
    for (;it<autogestite.end();it++)
        if (Prefisso(Minuscolo((*it)->getProprietario()), Minuscolo(prop))) {
            if (alert){
                Installazione* pI=dynamic_cast<Installazione*>(*it);
                if (pI && pI->alertImpianto()) selezione.push_back(*it);
            }
            else selezione.push_back(*it);

        }

    return selezione;
}





bool Officina::Prefisso(const std::string& a,const std::string& b){
    std::string::const_iterator it_a=a.begin();
    std::string::const_iterator it_b=b.begin();
    bool identico=true;
    if (b.size() && a.size()==0) identico=false;
    while (it_a<a.end() && it_b<b.end() && identico){
        if (*it_a != *it_b) identico=false;
        it_a++;
        it_b++;
    }
    return identico;
}


void Officina::changeTarga(std::string targa, std::string tg) {
    //cambiare targa rompe il vincolo
    //esiste quel indice ???
    if (targa!=tg){
        if (CheckAssenza(tg)){
            try {
                (operator[](targa)).changeTarga(tg);
                Salva();
            }
            catch (ErrNoValidIndex E) {throw E;}
        }
        else throw ErrChiave();
    }
}

void Officina::changeProprietario(std::string targa , std::string nome) {
    try {
        (operator[](targa)).changeProprietario(nome);
        Salva();
    }
    catch (ErrNoValidIndex E) {throw E;}
}
void Officina::changeDataImmatricolazione(std::string targa, const Data& dt) {
    try{
        (operator[](targa)).changeDataImmatricolazione(dt);
    }
    catch (ErrNoValidIndex E) {throw E;}
}

void Officina::changeDataUltimaRevisione(std::string targa, const Data& dt){
    try{
        (operator[](targa)).changeDataUltimaRevisione(dt);
        Salva();
    }
    catch (ErrNoValidIndex E) {throw E;}
}

void Officina::inserisciBombola(std::string targa, const Bombola& t){
    try{
        Installazione* pIN=dynamic_cast<Installazione*>(&(operator[](targa)));
        if (pIN) pIN->add_bombola(t);
        Salva();
    }
    catch (ErrNoValidIndex E) {throw E;}
}

void Officina::rimuoviBombola(std::string targa, int n){
    try{
        Installazione* pIN=dynamic_cast<Installazione*>(&(operator[](targa)));
        if (pIN) pIN->rimuovi_bombola(n);
        Salva();
    }
    catch (ErrNoValidIndex E) {throw E;}
}

