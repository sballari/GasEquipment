#include "ModelloHeaders/impianto.h"
#include <vector>
#include "ModelloHeaders/bombola.h"
#include <sstream>
#include <iostream>
#include "ModelloHeaders/directgpl.h"
#include "ModelloHeaders/maticgpl.h"
#include "ModelloHeaders/nocatgpl.h"
#include "ModelloHeaders/omegagpl.h"
#include "ModelloHeaders/errnovalidindex.h"
#include "ModelloHeaders/errxml.h"



Impianto::Impianto (const Impianto& og){
    std::vector<Bombola*>::const_iterator it = og.serbatoi.begin();
    for (; it<og.serbatoi.end(); it++){
        serbatoi.push_back((*it)->clona());
    }
}


Impianto& Impianto::operator =(const Impianto& og){
    if (this!=&og){
        //svuoto il vector
        std::vector<Bombola*>::const_iterator it = serbatoi.begin();
        for (; it<serbatoi.end(); it++){
            if (*it) delete *it;
        }
        serbatoi.clear();
        //riempio il vector
        it = og.serbatoi.begin();
        for (; it<og.serbatoi.end(); it++){
            serbatoi.push_back((*it)->clona());
        }
    }
    return *this;
}

Impianto::~Impianto(){
    std::vector<Bombola*>::const_iterator it = serbatoi.begin();
    for (; it<serbatoi.end(); it++){
        if (*it) delete *it;
    }
}
Bombola& Impianto::operator[](unsigned int n){
    if (n<serbatoi.size()) return *(serbatoi[n]);
    else  throw ErrNoValidIndex();
}

const Bombola& Impianto::operator[](unsigned int n)const{
    if (n<serbatoi.size()) return *(serbatoi[n]);
    else  throw ErrNoValidIndex();
}

unsigned int Impianto::nBombole() const {
    return serbatoi.size();
}
double Impianto::capacita_impianto() const{
    double somma = 0;
    std::vector<Bombola*>::const_iterator it = serbatoi.begin();
    for (; it<serbatoi.end(); it++){
        somma += (*it)->getCapacita();
    }
    return somma;
}

void Impianto::inserisciBombola(const Bombola & bm){
    serbatoi.push_back(bm.clona());
}



std::string Impianto::getInfo() const{
    std::string Info;
    Info+="IMPIANTO: \n";
    Info+= ToString(nBombole());
    Info+= " bombole\n";
    Info+="capacita  = ";
    Info+=ToString(capacita_impianto());
    Info+=" L\n";
    return Info;
}

void Impianto::Salva(QXmlStreamWriter& x) const{
    x.writeStartElement("Impianto");

    std::vector<Bombola*>::const_iterator it = serbatoi.begin();
    for (;it<serbatoi.end();it++) (*it)->Salva(x);

    x.writeEndElement();
}

std::vector<Bombola*> Impianto::Leggi(QXmlStreamReader& x){

    std::vector<Bombola*> v;
    while (!(x.isEndElement() && x.name()=="Impianto"))
    {
        if (x.isStartElement()){
            if (x.name()=="Bombola"){
                try {
                    Bombola* a=Bombola::Leggi(x);
                    v.push_back(a);
                }
                catch (ErrXML E){throw E;}

            }

            x.readNext();
        }
        else x.readNext();
    }
    if (x.isEndElement() && x.name()=="Impianto"){

        return v;
    }
    else throw ErrXML();



}

void Impianto::rimuoviBombola(unsigned int i){
    if (i< nBombole()){
        std::vector<Bombola*>::const_iterator it = serbatoi.begin();
        unsigned int bombola_puntata=0;
        while (bombola_puntata!=i)
        {
            it++;
            bombola_puntata++;

        }
        delete *it;
        serbatoi.erase(it);
    }
}

Impianto* Impianto::LeggiImpiantoInstanziabile(QXmlStreamReader& x){
    //x punta ad un text element ImpiantoInstanziabile
    Impianto* i=nullptr;
    x.readNextStartElement();
    try {
        if (x.name()=="DirectGPL")  i= DirectGPL::Leggi(x);
        if(x.name()=="MaticGPL")  i= MaticGPL::Leggi(x);
        if(x.name()=="OmegaGPL")  i= OmegaGPL::Leggi(x);
        if(x.name()=="NoCatGPL")  i= NoCatGPL::Leggi(x);
    }
    catch (ErrXML E) {throw E;}

    if (!i) throw ErrXML();
    return i;

}

bool Impianto::AlertRevisione() const{
    std::vector<Bombola*>::const_iterator it=serbatoi.begin();
    bool alert=false;
    for (; it!=serbatoi.end() && !alert; it++)
        if ((*it)->AlertRev()) alert=true;
    return alert;
}
