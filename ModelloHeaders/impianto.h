#ifndef IMPIANTO_H
#define IMPIANTO_H
#include <vector>
#include "data.h"
#include "bombola.h"
#include "veicolo.h"
#include "funzioni.h"

class Impianto    //classe astratta
{
private:
    std::vector<Bombola*> serbatoi;
public:
   virtual ~Impianto();
   virtual Impianto *clona() const=0;
   virtual std::string getInfo() const =0;
   virtual std::string getNome() const =0;
   virtual bool idoneita(const Veicolo&) const=0;

   Impianto()=default;
   Impianto (const Impianto&);
   Impianto& operator =(const Impianto&);


   Bombola& operator[](unsigned int );
   const Bombola& operator[](unsigned int )const;


   unsigned int nBombole() const;
   double capacita_impianto() const;
   void inserisciBombola(const Bombola&);
   void rimuoviBombola(unsigned int i);


   virtual void Salva(QXmlStreamWriter& x) const;
   static Impianto* LeggiImpiantoInstanziabile(QXmlStreamReader& x);
   bool AlertRevisione() const;

   static std::vector<Bombola*> Leggi(QXmlStreamReader& x);
};

#endif // IMPIANTO_H
