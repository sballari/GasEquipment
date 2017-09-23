#include "GuiHeaders/w_inizio_capo.h"

W_Inizio_Capo::W_Inizio_Capo(GestioneGUI *pM, QWidget *parent):
    W_Inizio(pM,parent)
{
    QPushButton* Inserisci = new QPushButton("inserisci veicolo/installazione (utente capo)");
    QPushButton* GestUtenti= new QPushButton("gestione utenti (utente capo)");
    lay->addWidget(GestUtenti);
    lay->addWidget(Inserisci);

    connect(Inserisci, SIGNAL(clicked()), this, SLOT(on_click_Inserisci()));
    connect(GestUtenti, SIGNAL(clicked(bool)), this, SLOT(on_click_gestioneU()));
}

void W_Inizio_Capo::on_click_Inserisci() const{
    pManager->ApriInserisci();
}
void W_Inizio_Capo::on_click_gestioneU()const{

    pManager->ApriGestioneUtenti();
}

void W_Inizio_Capo::on_consulta()const{
    pManager->ChiudiInizio();
    pManager->ApriConsultaCapo();
}
