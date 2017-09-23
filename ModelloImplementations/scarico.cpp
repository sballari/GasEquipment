#include "ModelloHeaders/scarico.h"
#include "ModelloHeaders/funzioni.h"
#include "ModelloHeaders/errxml.h"
using std::cout;
using std::endl;

Scarico::Scarico(bool cat, bool lambda, std::string prod, const Data& dt)
    :Componente(prod, dt), catalizzatore(cat), sonda_lambda(lambda){}


Scarico* Scarico::clona() const{
    return new Scarico(*this);
}

std::string Scarico::getInfo() const{
    std::string Info;
    Info+="SCARICO:\n";
    Info+= Componente::getInfo();

    Info+= (catalizzatore ? "con catalizzatore\n" : "senza catalizzatore\n");
    Info+= (sonda_lambda? "con sonda lambda\n" : "senza sonda lambda\n");
    return Info;
}

bool Scarico::hasCatalizzatore() const {return catalizzatore;}
bool Scarico::hasSondaLambda() const {return sonda_lambda;}

void Scarico::changeCatalizzatore(bool p){ catalizzatore = p;}
void Scarico::changeSondaLambda(bool p) {sonda_lambda = p;}

void Scarico::Salva(QXmlStreamWriter& x) const{
    x.writeStartElement("Scarico");
    Componente::Salva(x);
    x.writeTextElement("catalizzatore",QString::fromStdString(ToString(catalizzatore)));
    x.writeTextElement("sonda_lambda",QString::fromStdString(ToString(sonda_lambda)));
    x.writeEndElement();
}


Scarico* Scarico::Leggi(QXmlStreamReader& x){
    bool cat,sonda;
    bool c=false;
    bool s=false;
    
    std::string* a=nullptr;
    while (!(x.isEndElement() && x.name()=="Scarico"))
    {
        if (x.isStartElement()){
            if (x.name()=="Componente"){
                try{
                    a=Componente::Leggi(x);
                }
                catch (ErrXML E) {throw E;}
            }
            if (x.name()=="catalizzatore")
            {
                cat=(x.readElementText()=="vero")? true:false;
                c=true;
            }
            if(x.name()=="sonda_lambda"){
                sonda=(x.readElementText()=="vero")? true:false;
                s=true;
            }



            x.readNext();
        }
        else x.readNext();
    }
    if (x.isEndElement() && x.name()=="Scarico" && a && s && c){

        Scarico* r= new Scarico(cat,sonda,a[0],a[1]);
        delete[] a;
        return r;
    }
    else throw ErrXML();
}
