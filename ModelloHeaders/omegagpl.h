#ifndef OMEGAGPL_H
#define OMEGAGPL_H
#include "impiantogpl.h"

class OmegaGPL:public ImpiantoGPL
{
public:
    bool idoneita(const Veicolo&) const;
    virtual OmegaGPL* clona() const;
    virtual std::string getInfo() const;
    virtual std::string getNome() const;
    virtual void Salva(QXmlStreamWriter& x) const;
    static OmegaGPL* Leggi(QXmlStreamReader& x);
};

#endif // OMEGAGPL_H
