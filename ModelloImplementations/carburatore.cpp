#include "ModelloHeaders/carburatore.h"
#include "ModelloHeaders/errxml.h"
Carburatore::Carburatore(std::string prod, const Data & dt):Alimentatore(prod, dt){}

Carburatore* Carburatore::clona() const{
    return new Carburatore(*this);
}

std::string Carburatore::getInfo() const{
    std::string Info;

    Info+="CARBURATORE";
    Info+=Componente::getInfo()+"\n";
    return Info;
}

void Carburatore::Salva(QXmlStreamWriter& x) const{
    x.writeStartElement("AlimentatoreInstanziabile");
    x.writeStartElement("Carburatore");
    Alimentatore::Salva(x);
    x.writeEndElement();
    x.writeEndElement();
}

Carburatore* Carburatore::Leggi(QXmlStreamReader &x){
    std::string* a=nullptr;
    while (!(x.isEndElement() && x.name()=="Carburatore"))
    {
        if (x.isStartElement()){
            if (x.name()=="Alimentatore"){
                try{
                    a=Alimentatore::Leggi(x);
                }
                catch (ErrXML E) {throw E;}
            }
            x.readNext();
        }
        else x.readNext();
    }
    if (x.isEndElement() && x.name()=="Carburatore" && a ){

        Carburatore* c=new Carburatore(a[0],a[1]);
        delete[] a;
        return c;
    }
    else throw ErrXML();
}
