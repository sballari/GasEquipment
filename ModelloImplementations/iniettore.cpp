#include "ModelloHeaders/iniettore.h"
#include "ModelloHeaders/errxml.h"

Iniettore::Iniettore(modalita_iniezione mod, tipo_iniezione tp, std::string prod, const Data& dt):
    Alimentatore(prod, dt), mod_iniettore(mod), tipo_iniettore(tp){}

std::string Iniettore::getInfo() const {
    std::string Info;
    Info+="INIETTORE:\n";
    Info+= Componente::getInfo();

    if (mod_iniettore==elettronica) Info += "elettronico\n";
    if (mod_iniettore==meccanica) Info +="meccanico\n";
    if (mod_iniettore==mista) Info +="misto\n";
    if (tipo_iniettore==tipo_iniezione::diretta) Info +="iniezione diretta";
    if (tipo_iniettore==tipo_iniezione::indiretta) Info +="iniezione indiretta";
    return Info;
}

Iniettore* Iniettore::clona() const{
    return new Iniettore(*this);
}

Iniettore::modalita_iniezione Iniettore::getModIN() const{
    return mod_iniettore;
}

Iniettore::tipo_iniezione Iniettore::getTipoIN() const{
    return tipo_iniettore;
}

std::string Iniettore::ModToString(const Iniettore::modalita_iniezione& a){
    std::string r;
    if (a == Iniettore::elettronica) r= std::string("elettronica") ;
    if (a == Iniettore::meccanica)r= std::string("meccanica");
    if (a == Iniettore::mista )r= std::string("mista");
    return r;
}

std::string Iniettore::TipoToString(const Iniettore::tipo_iniezione& b){
    std::string r;
    if (b == Iniettore::diretta)r= std::string("diretta");
    if (b == Iniettore::indiretta)r= std::string("indiretta");
    return r;
}


void Iniettore::changeTipoIniezione(const Iniettore::tipo_iniezione& N){
    tipo_iniettore=N;
}

void Iniettore::changeModalitaIniezione(const Iniettore::modalita_iniezione& N){
    mod_iniettore=N;
}

void Iniettore::Salva(QXmlStreamWriter& x) const{
    x.writeStartElement("AlimentatoreInstanziabile");
    x.writeStartElement("Iniettore");
    Alimentatore::Salva(x);
    x.writeTextElement("modalita_iniezione",QString::fromStdString(ModToString(mod_iniettore)));
    x.writeTextElement("tipo_iniezione", QString::fromStdString(TipoToString(tipo_iniettore)));
    x.writeEndElement();
    x.writeEndElement();
}

Iniettore* Iniettore::Leggi(QXmlStreamReader& x){

    QString mod,tip;
    std::string* a=nullptr;
    bool m=false;
    bool t=false;
    while (!(x.isEndElement() && x.name()=="Iniettore"))
    {
        if (x.isStartElement()){
            if (x.name()=="Componente"){
                try{
                a=Componente::Leggi(x);
                }
                catch (ErrXML E) {throw E;}
            }
            if (x.name()=="modalita_iniezione"){

                mod=x.readElementText();
                m=true;
            }
              
            if(x.name()=="tipo_iniezione"){
                tip=x.readElementText();
                t=true;
            }

            x.readNext();
        }
        else x.readNext();
    }
    if (x.isEndElement() && x.name()=="Iniettore" && m && t){

        Iniettore* r= new Iniettore(String2Mod(mod.toStdString()),String2Tipo(tip.toStdString()),a[0],a[1]);
        delete[] a;
        return r;
    }
    else throw ErrXML();
}


Iniettore::modalita_iniezione Iniettore::String2Mod(std::string a) {
    Iniettore::modalita_iniezione r=Iniettore::elettronica; //default
    if (a == "elettronica" ) r= Iniettore::elettronica ;
    if (a == "meccanica")r= Iniettore::meccanica;
    if (a == "mista")r= Iniettore::mista;
    return r;
}
Iniettore::tipo_iniezione Iniettore::String2Tipo(std::string b) {
    Iniettore::tipo_iniezione r=Iniettore::diretta; //default
    if (b == "diretta")r= Iniettore::diretta;
    if (b == "indiretta")r= Iniettore::indiretta;
    return r;
    
}
