#ifndef NOCATGPL_H
#define NOCATGPL_H
#include "impiantogpl.h"

class NoCatGPL: public ImpiantoGPL
{
public:
    bool idoneita(const Veicolo&)const ;
    virtual NoCatGPL* clona() const;
    virtual std::string getInfo() const;
    virtual std::string getNome() const;
    void Salva(QXmlStreamWriter& x) const;
    static NoCatGPL* Leggi(QXmlStreamReader& x);
};

#endif // NOCATGPL_H
