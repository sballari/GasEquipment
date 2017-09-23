#ifndef DB_UTENTI_H
#define DB_UTENTI_H
#include <vector>
#include "utente.h"
#include "capo.h"
#include <QString>
#include "operaio.h"

class DB_utenti
{
private:
    std::vector<Utente*> account;

    static std::string file;
public:
    //GESTIONE MEMORIA
    DB_utenti();
    ~DB_utenti();
    DB_utenti (const DB_utenti&);
    DB_utenti& operator= (const DB_utenti&);



    int NumeroUtenti() const;
    void nuovoUtente(const Utente &);
    void eliminaUtente(std::string nome);
    const Utente* verifica(std::string, std::string) const;
    void cambiaNome(std::string nome,std::string nuovo) const;
    void cambiaPass(std::string nome,std::string nuovo) const;
    std::string getPass(std::string nome)const;
    std::string getTipo(std::string nome) const;
    std::string getNome(unsigned int i) const;
    void changeTipo (std::string nome);

    void SaveDB() const;
    void LoadDB();
private:
    const Utente& operator[] (unsigned int i) const;
    Utente& operator[] (unsigned int i);
    const Utente& operator[] (std::string nome) const;
    Utente& operator[] (std::string nome);
    void presenzaAdmin();


    Utente* NomeToPunt(std::string nome) const;
};

#endif // DB_UTENTI_H
