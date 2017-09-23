#include "ModelloHeaders/operaio.h"
#include "ModelloHeaders/utente.h"
#include "ModelloHeaders/errxml.h"
#include <iostream>


Operaio::Operaio(std::string nome, std::string pass): Utente(nome, pass){}
Operaio* Operaio::clona() const{return new Operaio(*this);}
std::string Operaio::getTipo() const{
    return "Operaio";
}
void Operaio::SalvaInfoUtente(QXmlStreamWriter &x) const{
    x.writeStartElement("Operaio");
    Utente::SalvaInfoUtente(x);
    x.writeEndElement();

}


Operaio* Operaio::LeggiUtente(QXmlStreamReader &x) {

    std::string* a=nullptr;
    Operaio* m=nullptr;

    while (!(x.isEndElement() && x.name()=="Operaio"))
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
    if (x.isEndElement() && x.name()=="Operaio" && a){

        m= new Operaio(a[0], a[1]);
        delete[] a;

    }
    else throw ErrXML();
    return m;
}
