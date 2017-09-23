#ifndef CAPO_H
#define CAPO_H
#include <string>
#include "utente.h"

class Capo: public Utente
{

public:
    Capo(std::string, std::string);
    Capo* clona() const;
    virtual std::string getTipo() const;
    virtual void SalvaInfoUtente(QXmlStreamWriter& x) const;
    static Capo* LeggiUtente(QXmlStreamReader &x) ;
};

#endif // CAPO_H
