#include "ModelloHeaders/utente.h"
#include <QXmlStreamWriter>
#include "ModelloHeaders/errxml.h"
#include <QFile>
#include <qmessagebox.h>
Utente::Utente(std::string n, std::string p):nome(n),passworld(p){}

std::string Utente::getNome() const{
    return nome;
}
std::string Utente::getPass() const{
    return passworld;
}

void Utente::changeNome(std::string n){nome=n;}
void Utente::changePass(std::string p){passworld=p;}
Utente::~Utente(){}


void Utente::SalvaInfoUtente(QXmlStreamWriter& x) const{
    x.writeStartElement("Utente");
    x.writeTextElement("Nome",QString::fromStdString( getNome()));
    x.writeTextElement("pass",QString::fromStdString(getPass()));
    x.writeEndElement();

}

std::string* Utente::LeggiUtente(QXmlStreamReader &x) {
    QString nome,pass;
    std::string* m= new std::string[2];
    bool n=false;
    bool p=false;
    while (!(x.isEndElement() && x.name()=="Utente"))
    {

        if (x.isStartElement()){
            if (x.name()=="Nome"){
                nome=x.readElementText();
                n=true;
            }
            if(x.name()=="pass"){
                pass=x.readElementText();
                p=true;
            }

            x.readNext();
        }
        else x.readNext();
    }
    if (x.isEndElement() && x.name()=="Utente" && n && p){

        m[0]=nome.toStdString();
        m[1]=pass.toStdString();

    }
    else throw ErrXML();
    return m;

}
