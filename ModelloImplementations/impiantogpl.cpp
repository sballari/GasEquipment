#include "ModelloHeaders/impiantogpl.h"
#include "ModelloHeaders/err.h"
#include "ModelloHeaders/errxml.h"

ImpiantoGPL::~ImpiantoGPL(){}
bool ImpiantoGPL::idoneita(const Veicolo& vec) const{
    return vec.IdoneitaGPL();
}


void ImpiantoGPL::Salva(QXmlStreamWriter& x) const{
    x.writeStartElement("ImpiantoGPL");
    Impianto::Salva(x);
    x.writeEndElement();
}
std::vector<Bombola*> ImpiantoGPL::Leggi(QXmlStreamReader &x){
    std::vector<Bombola*> v;

    while (!(x.isEndElement() && x.name()=="ImpiantoGPL")) {
        if (x.name()=="Impianto"){
            try {v=Impianto::Leggi(x);}
            catch (ErrXML E) {throw E;}
        }
        x.readNext();
    }

    if (!(x.isEndElement() && x.name()=="ImpiantoGPL"))   throw ErrXML();

    return v;





}
