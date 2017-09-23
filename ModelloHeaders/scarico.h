#ifndef SCARICO_H
#define SCARICO_H
#include "componente.h"
#include "string.h"


class Scarico: public Componente
{
private:
    bool catalizzatore;
    bool sonda_lambda;
public:
    Scarico(bool, bool, std::string, const Data&);

    std::string getInfo() const;

    bool hasCatalizzatore() const;
    bool hasSondaLambda() const;
    void changeCatalizzatore(bool);
    void changeSondaLambda(bool);

    Scarico* clona() const;
    virtual void Salva(QXmlStreamWriter& x) const;
    static Scarico* Leggi(QXmlStreamReader& x);

};

#endif // SCARICO_H
