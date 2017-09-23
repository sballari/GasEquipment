#ifndef INSTALLAZIONE_H
#define INSTALLAZIONE_H
#include "veicolo.h"
#include "impianto.h"
#include "data.h"
#include <QObject>
#include "nocatgpl.h"

class Installazione: public Veicolo
{
private:
    Impianto* impianto;
    Data data_installazzione;
public:
    Installazione(const Veicolo&,const Impianto& , const Data& =Data::Oggi());
    Installazione(const Installazione&);
    ~Installazione();
    Installazione& operator =(const Installazione&);
    std::string getInfo() const;
    virtual Installazione* clona() const;
    const Impianto* getImpianto() const;



    //GET RIGUARDO IMPIANTO
    std::string getNomeImpianto() const;
    double getCapacitaImpianto() const;
    int getNBomboleImpianto() const;
    Data getDataInstallazioneImpianto() const;
    bool alertImpianto() const;

    void add_bombola(const Bombola &b);
    void rimuovi_bombola(int n);

    void Salva(QXmlStreamWriter& x) const;
    static Installazione* Leggi(QXmlStreamReader & x);

};

#endif // INSTALLAZIONE_H
