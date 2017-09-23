#include <qxmlstream.h>
#ifndef UTENTE_H
#define UTENTE_H
#include <string>


class Utente
{
private:
    std::string nome;
    std::string passworld;
public:
    virtual void SalvaInfoUtente(QXmlStreamWriter& x) const;
    static std::string* LeggiUtente(QXmlStreamReader& x);
    virtual ~Utente() =0;
    Utente(std::string , std::string);
    std::string getNome() const;
    std::string getPass() const;
    void changeNome(std::string n);
    void changePass(std::string p);

    virtual std::string getTipo() const=0;
    virtual  Utente* clona() const =0;
};

#endif // UTENTE_H
