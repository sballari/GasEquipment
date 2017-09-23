#include "ModelloHeaders/nocatgpl.h"
#include "ModelloHeaders/errxml.h"

bool NoCatGPL::idoneita(const Veicolo& vec) const {
    //iniezione elettronica
    //senza catalizzatore
    if (ImpiantoGPL::idoneita(vec)
            && vec.haIniettore()
            && vec.getModIN()== Iniettore::modalita_iniezione::elettronica
            && !(vec.haCatalizzatore()) ) return true;
    else return false;
}
NoCatGPL* NoCatGPL::clona() const{
    return new NoCatGPL(*this);
}

std::string NoCatGPL::getInfo() const{
    std::string Info;
    Info+=Impianto::getInfo();
    Info+="Impianto NoCat GPL";
    return Info;
}


std::string NoCatGPL::getNome() const{
    return std::string("NoCatGPL");
}

void NoCatGPL::Salva(QXmlStreamWriter& x) const{
    x.writeStartElement("ImpiantoInstanziabile");
    x.writeStartElement("NoCatGPL");
    ImpiantoGPL::Salva(x);
    x.writeEndElement();
    x.writeEndElement();
}

NoCatGPL* NoCatGPL::Leggi(QXmlStreamReader& x){
    std::vector<Bombola*> v;
    NoCatGPL* m=nullptr;
    while (!(x.isEndElement() && x.name()=="NoCatGPL")) {
        if (x.name()=="ImpiantoGPL"){
            try {
                v=ImpiantoGPL::Leggi(x);
            }
            catch (ErrXML E) {throw E;}
        }
        x.readNext();
    }
    if (x.isEndElement() && x.name()=="NoCatGPL"){

        m= new NoCatGPL();
        for (std::vector<Bombola*>::const_iterator it=v.begin(); it<v.end();it++){

            m->inserisciBombola(**it);
            delete (*it);
        }

    }
    else throw ErrXML();

    return m;
}

