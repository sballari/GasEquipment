#ifndef IMPIANTOGPL_H
#define IMPIANTOGPL_H
#include "data.h"
#include "impianto.h"


class ImpiantoGPL: public Impianto  //astratta
{
public:
    
    ImpiantoGPL()=default;
    virtual ~ImpiantoGPL();
    virtual ImpiantoGPL* clona() const=0;

    virtual bool idoneita(const Veicolo&) const;
    virtual void Salva(QXmlStreamWriter& x) const;
    static std::vector<Bombola*> Leggi(QXmlStreamReader&);

};

#endif // IMPIANTOGPL_H
