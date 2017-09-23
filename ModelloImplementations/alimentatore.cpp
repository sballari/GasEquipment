#include "ModelloHeaders/alimentatore.h"
#include "ModelloHeaders/iniettore.h"
#include "ModelloHeaders/carburatore.h"
#include "ModelloHeaders/errxml.h"

Alimentatore::Alimentatore(std::string prod, const Data& dt): Componente(prod, dt) {}
void Alimentatore::Salva(QXmlStreamWriter& x) const{
    x.writeStartElement("Alimentatore");
    Componente::Salva(x);
    x.writeEndElement();
}

std::string* Alimentatore::Leggi(QXmlStreamReader &x){
    std::string* a=nullptr;
    while (!(x.isEndElement() && x.name()=="Alimentatore"))
    {
        if (x.isStartElement()){
            if (x.name()=="Componente"){
                try{
                    a=Componente::Leggi(x);
                }
                catch (ErrXML E) {throw E;}
            }
            x.readNext();
        }
        else x.readNext();
    }
    if (x.isEndElement() && x.name()=="Alimentatore" && a){

        return a;
    }
    else throw ErrXML();
}
Alimentatore* Alimentatore::LeggiAlimentatoreInstanziabile(QXmlStreamReader& x){
    //PRE: x punta ad un text element AliInstanziabile
    x.readNextStartElement();
    Alimentatore* r=nullptr;
    if (x.name()=="Iniettore") r= Iniettore::Leggi(x);
    if(x.name()=="Carburatore") r=  Carburatore::Leggi(x);
    return r;


}
