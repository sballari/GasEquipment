#include "ModelloHeaders/capo.h"
#include "ModelloHeaders/utente.h"
#include <iostream>
#include "ModelloHeaders/errxml.h"

Capo::Capo(std::string n, std::string p): Utente(n,p){}

Capo* Capo::clona() const{return new Capo(*this);}

std::string Capo::getTipo() const{
    return "Capo";
}

void Capo::SalvaInfoUtente(QXmlStreamWriter& x) const{
    x.writeStartElement("Capo");
    Utente::SalvaInfoUtente(x);
    x.writeEndElement();

}

Capo* Capo::LeggiUtente(QXmlStreamReader &x) {

    std::string* a=nullptr;
    Capo* m=nullptr;

    while (!(x.isEndElement() && x.name()=="Capo"))
    {

        if (x.isStartElement()){
            if (x.name()=="Utente"){
                try{
                  a=Utente::LeggiUtente(x);
                }
                catch (ErrXML e) {throw e;}
            }


            x.readNext();
        }
        else x.readNext();
    }
    if (x.isEndElement() && x.name()=="Capo" && a){

        m= new Capo(a[0], a[1]);
        delete[] a;

    }
    else throw ErrXML();
    return m;

}
