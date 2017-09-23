#ifndef OFFICINA_H
#define OFFICINA_H
#include <vector>
#include "installazione.h"
#include "veicolo.h"
#include "maticgpl.h"
#include "nocatgpl.h"

class Officina //classe contenitore
{
private:
    std::vector<Veicolo*> autogestite;
    //funzioni di utilita
    std::vector<Veicolo*>::const_iterator trova(std::string targa)const;
    static bool Prefisso(const std::string& a,const std::string& b);
    Veicolo& operator[] (unsigned int) ;
    Veicolo& operator[] (std::string targa) ;

    static std::string file;
public:

    const Veicolo& operator[] (unsigned int) const;
    const Veicolo& operator[] (std::string targa) const;




    void insertVeicolo(const Veicolo&);
    bool CheckAssenza(std::string tg) const ;
    void RimuoviVeicolo(std::string tg);
    std::vector<Veicolo*> RicercaPerProp(std::string prop, bool alert) const;


    Officina();
    Officina(const Officina&);
    Officina& operator=(const Officina&);
    ~Officina();
    unsigned int NAutoGestite() const;
    void Salva() const;
    void Carica();


    std::string getTarga (unsigned int) const;
    std::string getInfo(unsigned int pos) const;
    std::string getInfo(std::string targa) const;

    void changeTarga(std::string targa,std::string) ;
    void changeProprietario(std::string targa, std::string) ;
    void changeDataImmatricolazione(std::string targa,const Data&) ;
    void changeDataUltimaRevisione(std::string targa,const Data&);

    void inserisciBombola(std::string targa,const Bombola& t);
    void rimuoviBombola(std::string targa, int n);



};

#endif // OFFICINA_H
