#ifndef MATICGPL_H
#define MATICGPL_H
#include "impiantogpl.h"
#include "data.h"

class MaticGPL: public ImpiantoGPL
{
public:
    bool idoneita(const Veicolo&) const;
    virtual MaticGPL* clona() const;
    virtual std::string getInfo() const;
    virtual std::string getNome() const;
    void Salva(QXmlStreamWriter& x) const;
    static MaticGPL* Leggi(QXmlStreamReader& x);
};

#endif // MATICGPL_H
