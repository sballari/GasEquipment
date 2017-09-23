#include "ModelloHeaders/directgpl.h"
#include "ModelloHeaders/errxml.h"


bool DirectGPL::idoneita(const Veicolo& vec)const{
    //iniezione diretta
    if (ImpiantoGPL::idoneita(vec)
            && vec.haIniettore()
            && vec.getTipoIN()==Iniettore::tipo_iniezione::diretta)
        return true;
    else return false;
}
DirectGPL* DirectGPL::clona() const{
    return new DirectGPL(*this);
}
std::string DirectGPL::getInfo() const{
    std::string Info;
    Info+=Impianto::getInfo();
    Info+="Impianto Direct GPL";
    return Info;
}

std::string DirectGPL::getNome() const{
    return std::string("DirectGPL");
}
void DirectGPL::Salva(QXmlStreamWriter& x) const{
    x.writeStartElement("ImpiantoInstanziabile");
    x.writeStartElement("DirectGPL");
    ImpiantoGPL::Salva(x);
    x.writeEndElement();
    x.writeEndElement();
}


DirectGPL* DirectGPL::Leggi(QXmlStreamReader& x){
    std::vector<Bombola*> v;
    DirectGPL* m=nullptr;
    while (!(x.isEndElement() && x.name()=="DirectGPL")) {
        if (x.name()=="ImpiantoGPL"){
            try {
            v=ImpiantoGPL::Leggi(x);
            }
            catch (ErrXML E) {throw E;}
        }
        x.readNext();
    }
    if (x.isEndElement() && x.name()=="DirectGPL"){

        m= new DirectGPL();
        for (std::vector<Bombola*>::const_iterator it=v.begin();
             it<v.end();it++){
            m->inserisciBombola(**it);
            delete (*it);
        }

    }
    else throw ErrXML();

    return m;
}
