#include "ModelloHeaders/bombola.h"
#include <iostream>
#include "ModelloHeaders/data.h"
#include "ModelloHeaders/funzioni.h"
#include "ModelloHeaders/errxml.h"
using std::cout;
using std::endl;

int Bombola::anniRev = 2;

Bombola::Bombola(double cp,const Data& rev, std::string prod, const Data& dProd)
    :Componente(prod, dProd),capacita(cp), ultima_revisione(rev) {}
std::string Bombola::getInfo() const{

    std::string Info;
    Info+= Componente::getInfo()+"\n";
    Info+="BOMBOLA:\n";
    Info+="capacita' = ";
    Info+= ToString(capacita);
    Info+="L\n";
    Info+="ultima revisione fatta in data ";
    Info+= ultima_revisione;
    Info+="\n";
    return Info;
}
Bombola* Bombola::clona() const{
    return new Bombola(*this);
}

float Bombola::getCapacita() const {return capacita;}
Data Bombola::getUltimaRev() const {return ultima_revisione;}
Data Bombola::getScadenzaRev() const{
//la bombola va revisionata entro la fine del mese in cui è stata fatta la revisione di due anni dopo
    int a = ultima_revisione.getAnno() + anniRev;
    int g = Data::GiorniMese(ultima_revisione.getMese(),a);
    return Data(g,ultima_revisione.getMese(),a);
}


void Bombola::setCapacita(double c) {capacita=c;}
void Bombola::setUltimaRev(const Data& nd) {ultima_revisione=nd;}

bool Bombola::AlertRev() const{
    //return true sse sono nel mese della revisione o peggio
    Data limite = getScadenzaRev();
    Data oggi = Data::Oggi();

    if ((limite.getAnno()==oggi.getAnno() && limite.getMese() == oggi.getMese()) || (oggi>=limite)) return true;
    else return false;

}

void Bombola::Salva(QXmlStreamWriter& x) const{
    x.writeStartElement("Bombola");
    Componente::Salva(x);
    x.writeTextElement("capacita",QString::fromStdString(ToString(capacita)));
    x.writeTextElement("ultima_revisione",QString::fromStdString(ultima_revisione));

    x.writeEndElement();
}

Bombola* Bombola::Leggi(QXmlStreamReader &x){
    std::string* a=nullptr;
    QString cap, ultimaR;
    bool c=false;
    bool uR=false;
    while (!(x.isEndElement() && x.name()=="Bombola"))
    {
        if (x.isStartElement()){

            if (x.name()=="Componente"){
                try{
                    a=Componente::Leggi(x);
                }
                catch (ErrXML E) {throw E;}
            }
            if (x.name()=="capacita"){
                cap=x.readElementText();
                c=true;
            }

            if(x.name()=="ultima_revisione"){
                ultimaR=x.readElementText();
                uR=true;
            }

            x.readNext();
        }

        else x.readNext();
    }
    if (x.isEndElement() && x.name()=="Bombola" && a && uR && c){
        Bombola* r= new Bombola(cap.toDouble(),ultimaR.toStdString(),a[0],a[1]);
        delete[] a;
        return r;
    }
    else throw ErrXML();
}
