#ifndef GESTIONEGUI_H
#define GESTIONEGUI_H
#include "ModelloHeaders/db_utenti.h"




#include "ModelloHeaders/officina.h"


class GestioneGUI: public QObject
{
    Q_OBJECT
public:
    GestioneGUI();
    ~GestioneGUI();

    void avvioGUI(); //apre login
    void LoginEffettuato(const Utente*);
    void FineReg();
    void CambiaUtenteDaInizio();
    void ApriConsulta();
    void ChiudiConsulta();
    void ApriConsultaCapo();
    void ApriInizio();
    void ChiudiInizio();
    void ApriInserisci();
    void ChiudiShowInstallazione();
    void ChiudiInsInstallazione();
    void ChiudiShowVeicolo();
    void ApriGestioneUtenti();
    void ChiudiGestioneUtenti();
    void NascondiConsulta();
    void MostraConsulta();
    void ApriShowVeiIns(const Veicolo*);
    void ApriShowVeiIns_Capo(std::string targa);



    void ApriShowVeicolo(const Veicolo&);
    void ApriShowInstallazione(const Installazione&);
    void ApriShowVeicolo_Capo( std::string targa);
    void ApriShowInstallazione_Capo(std::string targa);
    void ApriAlteraVeicolo(std::string targa);
    void ChiudiAlteraVeicolo();


private:
    Officina* pO;
    DB_utenti* pDB_U;
    const Utente* UtenteAttivo;

    //finestre
    QWidget* pLogin;
    QWidget* pInizio;
    QWidget* pConsulta;
    QWidget* pInserisci;

    QWidget* pShowVeicoloInstallazzione;
    QWidget* pGestioneUtenti;
    QWidget* pAlteraVeicolo;
};

#endif // GESTIONEGUI_H
