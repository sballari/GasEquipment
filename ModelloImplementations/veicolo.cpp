#include "ModelloHeaders/veicolo.h"
#include <iostream>
#include "ModelloHeaders/carburatore.h"
#include "ModelloHeaders/err.h"
#include "ModelloHeaders/errxml.h"
#include "ModelloHeaders/errnoiniettore.h"

Veicolo::Veicolo(std::string prop, std::string tg, const Data& imm, const Data& rev, const Motore &M, const Alimentatore &A, const Scarico &S)
    :proprietario(prop), targa(tg), data_immatricolazione(imm), data_ultima_revisione(rev), engine(M.clona()), ali(A.clona()), scar(S.clona())
{}

Veicolo::~Veicolo(){
    delete ali;
    delete engine;
    delete scar;
}

Veicolo::Veicolo (const Veicolo& cp):
    proprietario(cp.proprietario), targa(cp.targa), data_immatricolazione(cp.data_immatricolazione),
    data_ultima_revisione(cp.data_ultima_revisione), engine ((cp.engine)->clona()),
    ali((cp.ali)->clona()), scar((cp.scar)->clona()){}

Veicolo& Veicolo::operator= (const Veicolo& cp){
    if (this != &cp){
        proprietario=cp.proprietario;
        targa=cp.targa;
        data_immatricolazione=cp.data_immatricolazione;
        data_ultima_revisione=cp.data_ultima_revisione;
        delete ali;
        delete engine;
        delete scar;
        engine =(cp.engine)->clona();
        ali = (cp.ali)->clona();
        scar = (cp.scar)->clona();
    }
    return *this;
}

Veicolo* Veicolo::clona() const {return new Veicolo(*this);}

std::string Veicolo::getInfo() const{
    std::string Info;
    Info+="VEICOLO: \n";
    Info+="proprietario: ";
    Info+=proprietario;
    Info+="\n";
    Info+="targa: ";
    Info+=targa;
    Info+="\n";
    Info+="data immatricolazione: ";
    Info+=data_immatricolazione;
    Info+="\n";
    Info+="data ultima revisione: ";
    Info+=data_ultima_revisione;
    Info+="\n";
    Info+=engine->getInfo();
    Info+=scar->getInfo();
    Info+=ali->getInfo() + "\n";
    return Info;
}

std::string Veicolo::getTarga() const{
    return targa;
}

std::string Veicolo::getProprietario() const{
    return proprietario;
}

Data Veicolo::getImmatricolazione() const{
    return data_immatricolazione;
}
Data Veicolo::getUltimaRevisione() const{
    return data_ultima_revisione;
}
bool Veicolo::IdoneitaGPL() const{
    return engine->idoneitaGPL();
}
void Veicolo::changeTarga(std::string tg){
    targa=tg;
}

void Veicolo::changeProprietario(std::string prod){
    proprietario =prod;
}

void Veicolo::changeDataImmatricolazione(const Data& dt){
    data_immatricolazione = dt;
}

void Veicolo::changeDataUltimaRevisione(const Data& dt){
    data_ultima_revisione = dt;
}

//GET ALIMENTATORE-----------------------------------------------------
std::string Veicolo::getNomeProdAlimentatore() const{
    return ali->getNomeProduttore();

}
Data Veicolo::getDataAlimentatore() const{
    return ali->getDataProduzione();
}

Iniettore::modalita_iniezione Veicolo::getModIN()const {
    Iniettore* in = dynamic_cast<Iniettore*> (ali);
    if (in) return in->getModIN();
    else throw ErrNoIniettore();
}
Iniettore::tipo_iniezione Veicolo::getTipoIN() const{
    Iniettore* in = dynamic_cast<Iniettore*> (ali);
    if (in) return in->getTipoIN();
    else throw ErrNoIniettore();
}

bool Veicolo::haIniettore() const {
    return dynamic_cast<Iniettore*>(ali);
}
bool Veicolo::haCarburatore() const{
    return dynamic_cast<Carburatore*>(ali);
}






void Veicolo::changeNomeProdAlimentatore(std::string nome) const{
    ali->changeNomeProduttore(nome);
}
void Veicolo::changeDataAlimentatore(const Data& dt) const{
    ali->changeDataProduzione(dt);
}

void Veicolo::changeTipoAlimentatore(){
    Iniettore* pI = dynamic_cast<Iniettore*>(ali);
    Carburatore* pC = dynamic_cast<Carburatore*>(ali);
    std::string nomeP = ali->getNomeProduttore();
    Data dataP = ali->getDataProduzione();
    if (pI){
        delete ali;
        ali = new Carburatore(nomeP, dataP);
    }
    if (pC){
        delete ali;
        ali= new Iniettore(Iniettore::elettronica, Iniettore::diretta, nomeP,dataP);
    }
}
void Veicolo::changeTipoIniettore(Iniettore::tipo_iniezione tp)const{
    Iniettore* pI = dynamic_cast<Iniettore*>(ali);
    if (pI) pI->changeTipoIniezione(tp);
    else throw ErrNoIniettore();
}
void Veicolo::changeModIniettore(Iniettore::modalita_iniezione md) const{
    Iniettore* pI = dynamic_cast<Iniettore*>(ali);
    if (pI) pI->changeModalitaIniezione(md);
    else throw ErrNoIniettore();
}
//GET SCARICO-------------------------------------------------
bool Veicolo::haCatalizzatore() const{
    return scar->hasCatalizzatore();
}
bool Veicolo::haSondaLambda() const {
    return scar->hasSondaLambda();
}
std::string Veicolo::getNomeProdScarico() const{
    return scar->getNomeProduttore();
}
Data Veicolo::getDataScarico() const{
    return scar->getDataProduzione();
}




void Veicolo::changeNomeProdScarico(std::string s ) const{
    scar->changeNomeProduttore(s);
}
void Veicolo::changeDataScarico(const Data& dt) const{
    scar->changeDataProduzione(dt);
}
void Veicolo::changeCatalizzatore(bool p) const{
    scar->changeCatalizzatore(p);
}
void Veicolo::changeSonda(bool p) const{
    scar->changeSondaLambda(p);
}
//--------------------------------------------------------------------






//get motore////////////////////////////////////////////////////
std::string Veicolo::getNomeProdMotore() const{
    return engine->getNomeProduttore();
}
Data Veicolo::getDataMotore() const{
    return engine->getDataProduzione();
}
int Veicolo::getNumeroCilindri() const{
    return engine->getN_cilindri();
}
int Veicolo::getCilindrata() const{
    return engine->getCilindrata();
}
double Veicolo::getCoppiaMax() const{
    return engine->getCoppia_max();
}
double Veicolo::getRapportoCompressione() const{
    return engine->getRapporto_compressione();
}
bool Veicolo::isSovralimentato() const{
    return engine->isSovralimentato();
}
void Veicolo::changeNomeProdMotore(std::string nome) const{
    engine->changeNomeProduttore(nome);
}
void Veicolo::changeDataProdMotore(const Data& dt) const{
    engine->changeDataProduzione( dt);
}
void Veicolo::changeNumeroCilindri (int n) const{
    engine->setN_cilindri(n);
}
void Veicolo::changeCilindrata (int n) const{
    engine->setCilindrata(n);
}
void Veicolo::changeCoppiamax(double d) const{
    engine->setCoppia_max(d);
}
void Veicolo::changeRapportoCompressione(double d) const{
    engine->setRapporto_compressione(d);
}
void Veicolo::changeSovralimentato(bool b) const{
    engine->setSovralimentato(b);
}

//-------------------------------


const Alimentatore& Veicolo::getAlimentatore() const { return *ali;}
const Scarico& Veicolo::getScarico() const {return *scar;}
const Motore& Veicolo::getMotore() const {return *engine;}

void Veicolo::Salva(QXmlStreamWriter& x) const{
    x.writeStartElement("Veicolo");

    x.writeTextElement("proprietario",QString::fromStdString(proprietario));
    x.writeTextElement("targa",QString::fromStdString(targa));
    x.writeTextElement("data_immatricolazione",QString::fromStdString(data_immatricolazione));
    x.writeTextElement("data_ultima_revisione",QString::fromStdString(data_ultima_revisione));
    engine->Salva(x);
    ali->Salva(x);
    scar->Salva(x);

    x.writeEndElement();
}


Veicolo* Veicolo::Leggi(QXmlStreamReader& x){

    Alimentatore* pAL=nullptr;
    Scarico* pSc=nullptr;
    Motore* pMot=nullptr;
    QString targ,prop,dI,dU;
    Veicolo* r=nullptr;
    bool a1=false;
    bool a2=false;
    bool a3=false;
    bool a4=false;


    while (!(x.isEndElement() && x.name()=="Veicolo"))

    {

        if (x.isStartElement()){
            if (x.name()=="AlimentatoreInstanziabile"){
                try{
                    pAL=Alimentatore::LeggiAlimentatoreInstanziabile(x);
                }
                catch (ErrXML E) {throw E;}
            }
            if(x.name()=="Scarico"){
                try {
                    pSc=Scarico::Leggi(x);
                }
                catch (ErrXML E) {throw E;}
            }
            if(x.name()=="Motore"){
                try {
                pMot=Motore::Leggi(x);
                }
                catch (ErrXML E) {throw E;}
            }
            if(x.name()=="targa"){
                targ=x.readElementText();
                a1=true;
            }
            if(x.name()=="proprietario"){
                prop=x.readElementText();
                a2=true;
            }
            if(x.name()=="data_immatricolazione")
            {
                dI=x.readElementText();
                a3=true;
            }
            if(x.name()=="data_ultima_revisione"){
                dU=x.readElementText();
                a4=true;
            }

            x.readNext();
        }
        else x.readNext();
    }
    if ((x.isEndElement()) && (x.name()=="Veicolo") && pAL && pSc && pMot && a1 && a2 && a3 && a4){

        r= new Veicolo(prop.toStdString(),targ.toStdString(),dI.toStdString(),dU.toStdString(),*pMot,*pAL,*pSc);
        delete pAL;
        delete pMot;
        delete pSc;
        return r;
    }
    else throw ErrXML();

    return r;
}
