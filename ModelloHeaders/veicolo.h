#ifndef VEICOLO_H
#define VEICOLO_H

#include <string>
#include "data.h"
#include "motore.h"
#include "alimentatore.h"
#include "scarico.h"
#include "iniettore.h"
#include "carburatore.h"


class Veicolo
{
private:
    std::string proprietario;
    std::string targa;
    Data data_immatricolazione;
    Data data_ultima_revisione;
    //componenti
    Motore* engine;
    Alimentatore* ali;
    Scarico* scar;
public:
    Veicolo( std::string  , std::string, const Data& , const Data& ,const Motore&,const Alimentatore& ,const Scarico&);
    virtual ~Veicolo();
    Veicolo (const Veicolo&);
    Veicolo& operator= (const Veicolo&);
    virtual Veicolo* clona() const;

    const Alimentatore& getAlimentatore() const;
    const Scarico& getScarico() const;
    const Motore& getMotore() const;

    std::string getTarga() const;
    virtual std::string getInfo() const;
    std::string getProprietario() const;
    Data getImmatricolazione() const;
    Data getUltimaRevisione() const;
    bool IdoneitaGPL() const;


    void changeTarga(std::string);
    void changeProprietario(std::string);
    void changeDataImmatricolazione(const Data&);
    void changeDataUltimaRevisione(const Data&);





    //info alimentazione
    std::string getNomeProdAlimentatore() const;
    Data getDataAlimentatore() const;
    bool haIniettore() const;
    bool haCarburatore() const;
    Iniettore::modalita_iniezione getModIN()const;
    Iniettore::tipo_iniezione getTipoIN() const;

    void changeNomeProdAlimentatore(std::string) const;
    void changeDataAlimentatore(const Data&) const;
    void changeTipoAlimentatore() ;
    void changeTipoIniettore(Iniettore::tipo_iniezione)const;
    void changeModIniettore(Iniettore::modalita_iniezione) const;


    //info scarico
    bool haCatalizzatore() const;
    bool haSondaLambda() const;
    std::string getNomeProdScarico() const;
    Data getDataScarico() const;

    void changeNomeProdScarico(std::string ) const;
    void changeDataScarico(const Data&) const;
    void changeCatalizzatore(bool ) const;
    void changeSonda(bool) const;
    //info motore
    std::string getNomeProdMotore() const;
    Data getDataMotore() const;
    int getNumeroCilindri() const;
    int getCilindrata() const;
    double getCoppiaMax() const;
    double getRapportoCompressione() const;
    bool isSovralimentato() const;

    void changeNomeProdMotore(std::string ) const;
    void changeDataProdMotore(const Data& ) const;
    void changeNumeroCilindri (int) const;
    void changeCilindrata (int) const;
    void changeCoppiamax(double) const;
    void changeRapportoCompressione(double) const;
    void changeSovralimentato(bool ) const;
    //-------------------------

    virtual void Salva(QXmlStreamWriter& x) const;
    static Veicolo* Leggi(QXmlStreamReader& x);


};

#endif // VEICOLO_H
