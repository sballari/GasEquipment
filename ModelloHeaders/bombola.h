#ifndef BOMBOLA_H
#define BOMBOLA_H
#include "data.h"
#include "componente.h"
#include <string>

class Bombola : public Componente
{
private:
    double capacita;         //espressa in litri
    Data ultima_revisione;
    static int anniRev; //ogni quanto va fatta la revisione della bombola
public:
    Bombola(double,const Data&, std::string ="sconosciuto",const Data& =Data::Oggi());
    virtual std::string getInfo() const;
    virtual Bombola* clona() const;

    float getCapacita() const;
    Data getUltimaRev() const;
    Data getScadenzaRev() const;
    void setCapacita(double);
    void setUltimaRev(const Data&);

    bool AlertRev() const; //indica se la bombola deve fare la revisione entro il mese corrente
    void Salva(QXmlStreamWriter& x) const;
    static Bombola* Leggi(QXmlStreamReader& x);
};

#endif // BOMBOLA_H
