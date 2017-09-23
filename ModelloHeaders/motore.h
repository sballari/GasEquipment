#ifndef MOTORE_H
#define MOTORE_H
#include <iostream>
#include "componente.h"

class Motore: public Componente
{
friend std::ostream& operator<< (std::ostream&, const Motore&);

private:
    int n_cilindri;
    int cilindrata;                     //espresso in cc
    double rapporto_di_compressione;    // espressa in kW
    double coppia_massima;              // espressa in Nm
    bool sovralimentato;                // true indica se il motore lo è, se false è ASPIRATO


    //requisiti legali di conversione a GPL
    static int min_cilindrataGPL_aspirato;
    static int max_cilindrataGPL_aspirato;
    static int min_cilindrataGPL_sovralimentato;
    static int max_cilindrataGPL_sovralimentato;
public:

    Motore(int , int, double, double, std::string, const Data&, bool);


    int getN_cilindri() const;
    int getCilindrata() const;
    double getRapporto_compressione() const;
    double getCoppia_max() const;
    bool isSovralimentato() const;

    void setN_cilindri(int);
    void setCilindrata(int);
    void setRapporto_compressione(double);
    void setCoppia_max(double);
    void setSovralimentato(bool);

    bool idoneitaGPL() const;
    std::string getInfo() const;
    Motore* clona() const;
    void Salva(QXmlStreamWriter& x) const;
    static Motore* Leggi(QXmlStreamReader& x);
};

//std::ostream& operator<< (std::ostream&, const Motore&); da togliere
#endif // MOTORE_H
