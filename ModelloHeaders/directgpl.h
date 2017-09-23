#ifndef DIRECTGPL_H
#define DIRECTGPL_H
#include "impiantogpl.h"

class DirectGPL: public ImpiantoGPL
{
public:
    virtual bool idoneita(const Veicolo&) const;
    virtual DirectGPL* clona() const;
    virtual std::string getInfo()const;
    virtual std::string getNome() const;
    virtual void Salva(QXmlStreamWriter& x) const;
    static DirectGPL *Leggi(QXmlStreamReader& x);
};

#endif // DIRECTGPL_H
