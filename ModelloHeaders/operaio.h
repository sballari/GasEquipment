#ifndef OPERAIO_H
#define OPERAIO_H
#include <string>
#include "ModelloHeaders/utente.h"

class Operaio: public Utente
{
public:
    Operaio(std::string, std::string);
    Operaio* clona() const;
    std::string getTipo() const;
    virtual void SalvaInfoUtente(QXmlStreamWriter& x) const;
    static Operaio* LeggiUtente(QXmlStreamReader &x) ;
};

#endif // OPERAIO_H
