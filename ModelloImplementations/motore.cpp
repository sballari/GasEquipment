#include "ModelloHeaders/motore.h"
#include "ModelloHeaders/funzioni.h"
#include "ModelloHeaders/componente.h"
#include "ModelloHeaders/errxml.h"

Motore::Motore(int n_c, int cil, double r_d_c, double cop_max, std::string prod, const Data & dt_prod, bool turbo):
    Componente(prod, dt_prod),n_cilindri(n_c), cilindrata(cil), rapporto_di_compressione(r_d_c),
    coppia_massima(cop_max) , sovralimentato(turbo)
{}




int Motore::min_cilindrataGPL_aspirato=890;
int Motore::max_cilindrataGPL_aspirato=5500;
int Motore::min_cilindrataGPL_sovralimentato=1335;
int Motore::max_cilindrataGPL_sovralimentato=2250;

Motore* Motore::clona() const{
    return new Motore(*this);
}

int Motore::getN_cilindri() const {return n_cilindri;}
int Motore::getCilindrata() const {return cilindrata;}
double Motore::getRapporto_compressione() const {return rapporto_di_compressione;}
double Motore::getCoppia_max() const {return coppia_massima;}
bool Motore::isSovralimentato() const {return sovralimentato;}

void Motore::setN_cilindri(int n_c) {n_cilindri=n_c;}
void Motore::setCilindrata(int cc){cilindrata=cc;}
void Motore::setRapporto_compressione(double kW){rapporto_di_compressione=kW;}
void Motore::setCoppia_max(double Nm){coppia_massima=Nm;}
void Motore::setSovralimentato(bool turbo){sovralimentato=turbo;}

bool Motore::idoneitaGPL() const{
    if (isSovralimentato())
        return (cilindrata>=min_cilindrataGPL_sovralimentato &&
                cilindrata<=max_cilindrataGPL_sovralimentato ? true : false);
    else
        return (cilindrata>=min_cilindrataGPL_aspirato &&
                cilindrata<=max_cilindrataGPL_aspirato ? true : false);
}

std::string Motore::getInfo() const{
    std::string Info ;
    Info +="MOTORE:\n";
    Info+= Componente::getInfo();
    Info +="cilindrata = " ;
    Info +=ToString(cilindrata);
    Info+=" cc\n";
    Info +="n cilindri = ";
    Info +=ToString(n_cilindri) + "\n";
    Info +="rapporto di compressione = ";
    Info +=ToString(rapporto_di_compressione);
    Info +=" kW\n";
    Info +="coppia max = ";
    Info +=ToString(coppia_massima);
    Info +=" Nm\n";

    Info += (sovralimentato ? "sovralimentato (turbo)\n" : "aspirato\n");
    return Info;
}

//funzioni esterne
std::ostream& operator << (std::ostream& canale, const Motore& o){
    canale<<"MOTORE:"<<std::endl;
    canale<<"cilindrata = "<<o.cilindrata<<" cc, n cilindri = "<<o.n_cilindri<<std::endl;
    canale<<"rapporto di compressione = "<<o.rapporto_di_compressione<<" kW, coppia max = "<<o.coppia_massima<<" Nm"<<std::endl;
    canale<<(o.sovralimentato ? "sovralimentato (turbo)" : "aspirato");
    return canale;
}

void Motore::Salva(QXmlStreamWriter& x) const{
    x.writeStartElement("Motore");
    Componente::Salva(x);
    x.writeTextElement("n_cilindri",QString::fromStdString(ToString(n_cilindri)));
    x.writeTextElement("cilindrata",QString::fromStdString(ToString(cilindrata)));
    x.writeTextElement("rapporto_di_compressione",QString::fromStdString(ToString(rapporto_di_compressione)));
    x.writeTextElement("coppia_massima",QString::fromStdString(ToString(coppia_massima)));
    x.writeTextElement("sovralimentato",QString::fromStdString(ToString(sovralimentato)));
    x.writeEndElement();
}

Motore* Motore::Leggi(QXmlStreamReader& x){

    QString nc="0";
    QString cil="0";
    QString rdc="0";
    QString cm="0";
    bool turb=false;
    bool a1=false;
    bool a2=false;
    bool a3=false;
    bool a4=false;
    bool a5=false;

    
    std::string* a=nullptr;
    while (!(x.isEndElement() && x.name()=="Motore"))
    {
        if (x.isStartElement()){
            if (x.name()=="Componente"){
                try{
                    a=Componente::Leggi(x);
                }
                catch (ErrXML E) {throw E;}
            }
            if (x.name()=="n_cilindri"){
                nc=x.readElementText();
                a1=true;
            }
            if(x.name()=="cilindrata"){
                cil=x.readElementText();
                a2=true;
            }
            if(x.name()=="rapporto_di_compressione"){
                rdc=x.readElementText();
                a3=true;
            }
            if(x.name()=="coppia_massima"){
                cm=x.readElementText();
                a4=true;
            }
            if(x.name()=="sovralimentato"){
                turb=(x.readElementText()=="vero")? true:false;
                a5=true;
            }

            x.readNext();
        }
        else x.readNext();
    }
    if (x.isEndElement() && x.name()=="Motore" && a && a1 && a2 && a3 && a4 && a5){

        Motore* r= new Motore(nc.toInt(),cil.toInt(),rdc.toInt(),cm.toDouble(),a[0],a[1],turb);
        delete[] a;
        return r;
    }
    else throw ErrXML();

}
