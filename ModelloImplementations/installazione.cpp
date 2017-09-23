#include "ModelloHeaders/installazione.h"
#include <iostream>
#include "ModelloHeaders/data.h"
#include "QXmlStreamWriter"
#include "QXmlStreamReader"
#include "ModelloHeaders/errxml.h"

Installazione::Installazione(const Veicolo &v, const Impianto& i, const Data& dt)
    :Veicolo(v), impianto(i.clona()), data_installazzione(dt){

}

Installazione::Installazione(const Installazione& cp):Veicolo(cp),impianto(cp.impianto->clona()), data_installazzione(cp.data_installazzione){}

Installazione::~Installazione(){
    if (impianto) delete impianto;
}

Installazione& Installazione::operator =(const Installazione& cp){
    //assegno il sottooggetto veicolo
    if (this!=&cp){
        this->Veicolo::operator =(cp);
        delete impianto;
        impianto = cp.impianto->clona();
        data_installazzione = cp.data_installazzione;
    }
    return *this;
}
std::string Installazione::getInfo() const{
    std::string Info;
    Info+="INSTALLAZIONE:\n";

    Info+="data installazione = ";
    Info+=data_installazzione;
    Info+="\n";
    Info+=impianto->getInfo();
    Info+="\n";
    Info+=Veicolo::getInfo();

    return Info;
}
std::string Installazione::getNomeImpianto() const{
    return impianto->getNome();
}
double Installazione::getCapacitaImpianto() const{

    return impianto->capacita_impianto();
}
int Installazione::getNBomboleImpianto() const{
    return impianto->nBombole();
}
Data Installazione::getDataInstallazioneImpianto() const{
    return data_installazzione;
}

Installazione* Installazione::clona() const{
    return new Installazione(*this);
}
const Impianto* Installazione::getImpianto() const{
    return impianto;
}
void Installazione::add_bombola(const Bombola& b){
    impianto->inserisciBombola(b);
}

void Installazione::rimuovi_bombola(int n){
    impianto->rimuoviBombola(n);
}

void Installazione::Salva(QXmlStreamWriter& x) const{
    x.writeStartElement("Installazione");
    Veicolo::Salva(x);
    impianto->Salva(x);
    x.writeTextElement("data_installazione", QString::fromStdString(data_installazzione));
    x.writeEndElement();
}



Installazione* Installazione::Leggi(QXmlStreamReader& x){
    Installazione* r=nullptr;
    Impianto* pImp=nullptr;
    Veicolo* pVei=nullptr;
    std::string dt;
    bool d=false;

    while (!((x.isEndElement() && x.name()=="Installazione")))
    {

        if (x.isStartElement()){
            if (x.name()=="Veicolo"){
                try{
                    pVei=Veicolo::Leggi(x);
                }
                catch (ErrXML E) {throw E;}
            }

            if (x.name()=="ImpiantoInstanziabile"){
                //try{

                    pImp=Impianto::LeggiImpiantoInstanziabile(x);
                //}
                //catch (ErrXML E) {throw E;}
            }
            if(x.name()=="data_installazione"){
                dt=x.readElementText().toStdString();
                d=true;
            }


            x.readNext();
        }
        else x.readNext();
    }
    if (x.isEndElement() && x.name()=="Installazione" && d && pVei && pImp){

        r= new Installazione(*pVei,*pImp,dt);

    }
    else throw ErrXML();
    delete pImp;
    delete pVei;
    return r;


}

bool Installazione::alertImpianto() const {

    return impianto->AlertRevisione();
}
