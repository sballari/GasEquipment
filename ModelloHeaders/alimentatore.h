#ifndef ALIMENTATORE_H
#define ALIMENTATORE_H
#include "componente.h"
#include <string>
#include <iostream>


class Alimentatore: public Componente
{
public:
    Alimentatore(std::string , const Data&);

    virtual Alimentatore* clona() const=0;
    void Salva(QXmlStreamWriter& x) const;
    static std::string* Leggi(QXmlStreamReader &);
    static Alimentatore* LeggiAlimentatoreInstanziabile(QXmlStreamReader& x);

};
#endif // ALIMENTATORE_H
