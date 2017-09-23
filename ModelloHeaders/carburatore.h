#ifndef CARBURATORE_H
#define CARBURATORE_H
#include "alimentatore.h"
#include <iostream>

class Carburatore: public Alimentatore
{

public:
    Carburatore(std::string, const Data&);

    virtual std::string getInfo() const;
    virtual Carburatore* clona() const;
    virtual void Salva(QXmlStreamWriter& x) const;
    static Carburatore* Leggi(QXmlStreamReader&);
};

#endif // CARBURATORE_H
