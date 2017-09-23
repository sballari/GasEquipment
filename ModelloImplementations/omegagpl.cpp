#include "ModelloHeaders/omegagpl.h"
#include "ModelloHeaders/veicolo.h"
#include <iostream>
#include "ModelloHeaders/errxml.h"



bool OmegaGPL::idoneita(const Veicolo& mac)const{ //funzione statica
    //iniezione di tipo elettronica
    //presenza di catalizzatore
    //presenza di sonda lambda
    if (ImpiantoGPL::idoneita(mac) ){
        if (mac.haIniettore()){
            if (mac.getModIN()== Iniettore::modalita_iniezione::elettronica
                    && mac.haCatalizzatore() && mac.haSondaLambda())
                return true;
            else return false;
        }
        else return false;
    }
    else return false;

}

OmegaGPL* OmegaGPL::clona() const{
    return new OmegaGPL(*this);
}

std::string OmegaGPL::getInfo() const{
    std::string Info;
    Info+=Impianto::getInfo();
    Info+="Impianto Omega GPL";
    return Info;
}


std::string OmegaGPL::getNome() const{
    return std::string("OmegaGPL");
}
void OmegaGPL::Salva(QXmlStreamWriter& x) const{
    x.writeStartElement("ImpiantoInstanziabile");
    x.writeStartElement("OmegaGPL");
    ImpiantoGPL::Salva(x);
    x.writeEndElement();
    x.writeEndElement();
}

OmegaGPL* OmegaGPL::Leggi(QXmlStreamReader& x){
    std::vector<Bombola*> v;
    OmegaGPL* m=nullptr;

    while (!(x.isEndElement() && x.name()=="OmegaGPL")) {
        if (x.name()=="ImpiantoGPL") {
            try {
                v=ImpiantoGPL::Leggi(x);
            }
            catch (ErrXML E) {throw E;}
        }
        x.readNext();
    }

    if (x.isEndElement() && x.name()=="OmegaGPL"){

        m= new OmegaGPL();
        for (std::vector<Bombola*>::const_iterator it=v.begin();
             it<v.end();it++){
            m->inserisciBombola(**it);
            delete (*it);
        }

    }
    else throw ErrXML();

    return m;

}

