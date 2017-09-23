#include "GuiHeaders/gestionegui.h"
#include <iostream>
#include "ModelloHeaders/err.h"
#include "GuiHeaders/w_accesso.h"
#include "GuiHeaders/w_consulta.h"
#include "GuiHeaders/w_inizio_capo.h"
#include "GuiHeaders/w_inizio.h"
#include "GuiHeaders/gestioneutenti.h"
#include "GuiHeaders/w_show_installazzione.h"
#include "GuiHeaders/w_show_installazzione_capo.h"
#include "GuiHeaders/w_insinstallazzione.h"
#include "GuiHeaders/w_consulta_capo.h"
#include "GuiHeaders/w_show_veicolo_capo.h"
#include "GuiHeaders/w_alter_veicolo.h"


GestioneGUI::GestioneGUI()
    :QObject(nullptr), pO(new Officina()), pDB_U(nullptr),UtenteAttivo(nullptr), pLogin(nullptr),
      pInizio(nullptr), pConsulta(nullptr), pInserisci(nullptr),
      pShowVeicoloInstallazzione(nullptr),pGestioneUtenti(nullptr),pAlteraVeicolo(nullptr)
{

}

GestioneGUI::~GestioneGUI(){
    if (pLogin) delete pLogin;
    if (pInizio) delete pInizio;
    if (pConsulta) delete pConsulta;
    if (pInserisci) delete pInserisci;

    if (pShowVeicoloInstallazzione) delete pShowVeicoloInstallazzione;
    if (pGestioneUtenti) delete pGestioneUtenti;
    if (UtenteAttivo) delete UtenteAttivo;
    if (pO) delete pO;
    if (pAlteraVeicolo) delete pAlteraVeicolo;
}

void GestioneGUI::avvioGUI(){

    if (pLogin) throw Err("LOGIN gia' avviata");
    else {
        if (!pDB_U){
            pDB_U=new DB_utenti();

        }
        pLogin = new W_accesso(pDB_U, this);
        pLogin->show();
    }
}

void GestioneGUI::CambiaUtenteDaInizio(){
    ChiudiInizio();
    avvioGUI();
}
void GestioneGUI::ChiudiInizio(){
    if (!pInizio) throw Err("pInizio e' gia' nullo");
    pInizio->hide();
    delete pInizio;
    pInizio=nullptr;
}

void GestioneGUI::LoginEffettuato(const Utente* UA){


    if (UtenteAttivo) {delete UtenteAttivo; UtenteAttivo=UA->clona();}
    else UtenteAttivo=UA->clona();
    pLogin->hide(); //solo un login
    delete pLogin;
    pLogin = nullptr;
    delete pDB_U;
    pDB_U=nullptr;


    ApriInizio();


}
void GestioneGUI::ApriInizio(){
    if(pInizio) throw Err("pInizio deve essere nullo");
    if (dynamic_cast<const Operaio*>(UtenteAttivo)) {pInizio= new W_Inizio(this); pInizio->show();}
    if (dynamic_cast<const Capo*>(UtenteAttivo)) {pInizio= new W_Inizio_Capo(this); pInizio->show();}
}




void GestioneGUI::ApriConsulta() {


    if(pConsulta) throw Err("pConsulta deve essere NULLO");
    pConsulta = new W_Consulta(pO, this);
    pConsulta->show();

}

void GestioneGUI::ApriConsultaCapo() {


    if(pConsulta) throw Err("pConsulta deve essere NULLO");
    pConsulta = new W_Consulta_Capo(pO, this);
    pConsulta->show();

}
void GestioneGUI::MostraConsulta(){
    if (pConsulta) pConsulta->show();

}

void GestioneGUI::NascondiConsulta(){
    if (pConsulta) pConsulta->hide();
}

void GestioneGUI::ChiudiConsulta(){
    if (!pConsulta) throw Err("pConsulta non puo' essere nullo");
    pConsulta->hide();
    delete pConsulta;
    pConsulta= nullptr;
}


void GestioneGUI::ApriInserisci(){
    ChiudiInizio();
    if (pInserisci) throw Err("pInserisci gia' aperto");
    pInserisci = new W_insInstallazzione(pO,this);
    pInserisci->show();
}

void GestioneGUI::ApriShowInstallazione(const Installazione& i){

    if (pShowVeicoloInstallazzione) throw Err( "finestra gia' aperta");
    pShowVeicoloInstallazzione= new W_Show_Installazzione(&i,this);
    pShowVeicoloInstallazzione->show();
}

void GestioneGUI::ApriShowInstallazione_Capo(std::string targa){

    if ( pShowVeicoloInstallazzione) throw Err( "finestra gia' aperta");
    pShowVeicoloInstallazzione= new W_Show_Installazzione_Capo(pO,targa,this);
    pShowVeicoloInstallazzione->show();
}

void GestioneGUI::ApriShowVeicolo(const Veicolo& i){

    if (pShowVeicoloInstallazzione) throw Err( "finestra gia' aperta");
    pShowVeicoloInstallazzione= new W_Show_Veicolo(&i,this);
    pShowVeicoloInstallazzione->show();
}

void GestioneGUI::ApriShowVeicolo_Capo(std::string targa){

    if (pShowVeicoloInstallazzione ) throw Err( "finestra gia' aperta");
    pShowVeicoloInstallazzione= new W_Show_Veicolo_Capo(pO,targa,this);
    pShowVeicoloInstallazzione->show();
}
void GestioneGUI::ApriAlteraVeicolo(std::string targa){
    if (pAlteraVeicolo ) throw Err( "finestra gia' aperta");
    pAlteraVeicolo= new W_alter_veicolo(pO,targa,this);
    if (pConsulta){
        W_alter_veicolo* p= static_cast<W_alter_veicolo*>(pAlteraVeicolo);
        W_Consulta* c= static_cast<W_Consulta*>(pConsulta);
        QObject::connect(p,SIGNAL(targa_alterata(std::string )),c,SLOT(on_alterazione_targa(std::string)));
    }
    pAlteraVeicolo->show();
}

void GestioneGUI::ChiudiAlteraVeicolo(){
    if(!pAlteraVeicolo) throw Err("pInstallazzopne gia chiuso");
    pAlteraVeicolo->hide();
    delete pAlteraVeicolo;
    pAlteraVeicolo=nullptr;

}


void GestioneGUI::ChiudiShowInstallazione(){
    if(!pShowVeicoloInstallazzione) throw Err("pInstallazzopne gia chiuso");
    pShowVeicoloInstallazzione->hide();
    delete pShowVeicoloInstallazzione;
    pShowVeicoloInstallazzione=nullptr;

}

void GestioneGUI::ChiudiShowVeicolo(){
    if(!pShowVeicoloInstallazzione) throw Err("pveicolo gia chiuso");
    pShowVeicoloInstallazzione->hide();
    delete pShowVeicoloInstallazzione;
    pShowVeicoloInstallazzione=nullptr;

}

void GestioneGUI::ChiudiInsInstallazione(){

    if(!pInserisci) throw Err("pInstallazzopne gia chiuso");
    pInserisci->hide();
    delete pInserisci;
    pInserisci=nullptr;
}

void GestioneGUI::ApriGestioneUtenti(){

    ChiudiInizio();
    if (pGestioneUtenti) throw Err( "finestra gia' aperta");
    pDB_U= new DB_utenti();
    pGestioneUtenti= new GestioneUtenti(pDB_U,this);
    pGestioneUtenti->show();

}

void GestioneGUI::ChiudiGestioneUtenti(){
    if(!pGestioneUtenti) throw Err("pgestioneutenti gia chiuso");
    pGestioneUtenti->hide();
    delete pGestioneUtenti;
    pGestioneUtenti=nullptr;
    delete pDB_U;
    pDB_U=nullptr;
    ApriInizio();
}
void GestioneGUI::ApriShowVeiIns(const Veicolo* p){
    const Installazione* pI=dynamic_cast<const Installazione*>(p);
    if (pI) ApriShowInstallazione(*pI);
    else ApriShowVeicolo(*p);
}

void GestioneGUI::ApriShowVeiIns_Capo(std::string targa){
    const Veicolo* p=&(const_cast<const Officina*>(pO)->operator [](targa));
    const Installazione* pI=dynamic_cast<const Installazione*>(p);
    if (pI) ApriShowInstallazione_Capo(targa);
    else ApriShowVeicolo_Capo(targa);
}
