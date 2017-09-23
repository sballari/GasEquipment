#ifndef COMPONENTE_H
#define COMPONENTE_H
#include "data.h"
#include <string>
#include "qxmlstream.h"


class Componente{ //classe astratta
private:
    std::string produttore;
    Data data_produzione;

public:
    Componente(std::string ="sconosciuto", const Data& =Data(1,12,2000));
    virtual ~Componente();
    virtual std::string getInfo() const =0;
    virtual Componente* clona() const =0;

    //metodi propi
    std::string getNomeProduttore() const;
    Data getDataProduzione() const;
    void changeNomeProduttore(std::string );
    void changeDataProduzione(const Data&);
    virtual void Salva(QXmlStreamWriter& x) const;
    static std::string* Leggi(QXmlStreamReader& x) ;

};

#endif // COMPONENTE_H
