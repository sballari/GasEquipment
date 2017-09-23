#ifndef INIETTORE_H
#define INIETTORE_H
#include "alimentatore.h"
#include <iostream>



class Iniettore: public Alimentatore
{
public:
    enum modalita_iniezione {elettronica, meccanica, mista};
    enum tipo_iniezione {diretta, indiretta};


    Iniettore(modalita_iniezione ,tipo_iniezione, std::string, const Data&);

    virtual std::string getInfo() const;
    virtual Iniettore* clona() const;

    modalita_iniezione getModIN() const;
    tipo_iniezione getTipoIN() const;

    static std::string TipoToString(const tipo_iniezione&);
    static std::string ModToString(const modalita_iniezione&);
    
    

    void changeTipoIniezione(const tipo_iniezione&);
    void changeModalitaIniezione(const modalita_iniezione&);
    

    void Salva(QXmlStreamWriter& x) const;
    static Iniettore* Leggi(QXmlStreamReader& x);
private:
    modalita_iniezione mod_iniettore;
    tipo_iniezione tipo_iniettore;
    
    static modalita_iniezione String2Mod(std::string) ;
    static tipo_iniezione String2Tipo(std::string) ;

};

#endif // INIETTORE_H
