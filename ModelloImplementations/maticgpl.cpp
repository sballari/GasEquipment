#include "ModelloHeaders/maticgpl.h"
#include "ModelloHeaders/errxml.h"


bool MaticGPL::idoneita(const Veicolo& vec)const{
    //motori a carburatore
    if (ImpiantoGPL::idoneita(vec) && vec.haCarburatore()) return true;
    else return false;
}
MaticGPL* MaticGPL::clona() const{
    return new MaticGPL(*this);
}
std::string MaticGPL::getInfo() const{
    std::string Info;
    Info+=Impianto::getInfo();
    Info+="Impianto Matic GPL";
    return Info;

}

std::string MaticGPL::getNome() const{
    return std::string("MaticGPL");
}
void MaticGPL::Salva(QXmlStreamWriter& x) const{
    x.writeStartElement("ImpiantoInstanziabile");
    x.writeStartElement("MaticGPL");
    ImpiantoGPL::Salva(x);
    x.writeEndElement();
    x.writeEndElement();

}
MaticGPL* MaticGPL::Leggi(QXmlStreamReader& x){
        std::vector<Bombola*> v;
        MaticGPL* m=nullptr;

        while (!(x.isEndElement() && x.name()=="MaticGPL")) {
            if (x.name()=="ImpiantoGPL") {
                try {
                    v=ImpiantoGPL::Leggi(x);
                }
                catch (ErrXML E) {throw E;}
            }
            x.readNext();
        }
        if (x.isEndElement() && x.name()=="MaticGPL"){

            m= new MaticGPL();
            for (std::vector<Bombola*>::const_iterator it=v.begin();
                 it<v.end();it++){
                m->inserisciBombola(**it);
                delete (*it);
            }

        }
        else throw ErrXML();
    return m;
}
    

