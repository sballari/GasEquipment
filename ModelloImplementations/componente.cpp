#include "ModelloHeaders/componente.h"
#include "ModelloHeaders/errxml.h"
#include <iostream>
#include <sstream>
Componente::Componente(std::string pr, const Data& dt): produttore(pr) , data_produzione(dt){}
Componente::~Componente(){}
std::string Componente::getInfo() const {
    std::string info;
    info+="produttore = ";
    info+=produttore;
    info+="\ndata di produzione = ";
    info+=data_produzione ;
    info+= "\n";
    return info;

}
std::string Componente::getNomeProduttore() const{
    return produttore;
}
Data Componente::getDataProduzione() const{
    return data_produzione;
}
void Componente::changeNomeProduttore(std::string nome){
    produttore=nome;
}

void Componente::changeDataProduzione(const Data& dt){
    data_produzione=dt;
}

void Componente::Salva(QXmlStreamWriter& x) const{
    x.writeStartElement("Componente");
    x.writeTextElement("produttore",QString::fromStdString(produttore));
    x.writeTextElement("data",QString::fromStdString(data_produzione));
    x.writeEndElement();
}


std::string* Componente::Leggi(QXmlStreamReader &x){
    std::string* a= new std::string[2];
    bool p=false;
    bool d=false;

    while (!(x.isEndElement() && x.name()=="Componente"))
    {
        if (x.isStartElement()){
            if (x.name()=="produttore"){
                a[0]=x.readElementText().toStdString();
                p=true;
            }
            if(x.name()=="data"){
                a[1]=x.readElementText().toStdString();
                d=true;
            }
            x.readNext();
        }
        else x.readNext();
    }
    if (x.isEndElement() && x.name()=="Componente" && p && d){

        return a;
    }
    else {
        throw ErrXML();
    }
}
