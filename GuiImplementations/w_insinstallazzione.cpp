#include "GuiHeaders/w_insinstallazzione.h"
#include "GuiHeaders/w_insinstallazzione.h"
#include "GuiHeaders/w_insimpianto.h"
#include "qerrormessage.h"
#include "ModelloHeaders/err.h"
#include "ModelloHeaders/errchiave.h"
W_insInstallazzione::W_insInstallazzione(Officina * p, GestioneGUI *pM):W_insVeicolo(),pOfficina(p),pManager(pM),err(nullptr),datiINST(nullptr)
{


    QVBoxLayout*  layImp=new QVBoxLayout;
    QGroupBox* impianto=new QGroupBox("Impianto");
    QPushButton* Ins_Vei=new QPushButton("Veicolo/Installazzione");
    impianto->setLayout(layImp);
    layImp->addWidget(Ins_Vei);
    datiINST=creaBOX();
    layImp->addWidget(datiINST);
    layImp->addStretch();
    connect(Ins_Vei, SIGNAL(clicked(bool)), this , SLOT(on_click_VeiInst()));
    QPushButton* proc=new QPushButton("inserisci");
    lay->addWidget(impianto);

    Clay->addWidget(proc);

    connect(proc,SIGNAL(clicked(bool)), this, SLOT(inserisci()));


}

W_insInstallazzione::~W_insInstallazzione(){
    if (err) delete err;
}

QGroupBox* W_insInstallazzione::creaBOX() {

    QVBoxLayout* lay=new QVBoxLayout();




    QFormLayout* dt=new QFormLayout();
    data=new QDateEdit();
    dt->addRow("data installazzione",data);
    insti=new W_insImpianto();

    lay->addLayout(dt);
    lay->addWidget(insti);



    QGroupBox* c=new QGroupBox();
    c->setLayout(lay);
    return c;
}

Veicolo* W_insInstallazzione::crea() {
    Veicolo* VEI=creaVeicolo();
    if (datiINST->isEnabled()){
        Impianto* IMP = insti->creaImpianto();

        if (IMP->idoneita(*VEI)){
            Data dt=data->date();
            Installazione*p= new Installazione(*VEI, *IMP,dt );
            return p;
        }
        else {
            if (err) {err->close(); delete err; err=nullptr;}
            err = new QErrorMessage();
            err->showMessage("impianto non idoneo al tipo di veicolo");
            return nullptr;
        }
    }
    else return VEI;

}
void W_insInstallazzione::inserisci(){
    Veicolo* V=crea();
    if (V){
        bool ok=true;
        try{
            pOfficina->insertVeicolo(*V);
        }
        catch (ErrChiave E){

            if (err) {err->close(); delete err; err=nullptr;}
            err = new QErrorMessage();
            err->showMessage("inserimento non consentito");
            ok=false;
        }
        if (ok) {
            if (err) {err->close(); delete err; err=nullptr;}
            err = new QErrorMessage();
            err->showMessage("inserimento avvenuto");
        }
        delete V;
    }


}
void W_insInstallazzione::closeEvent(QCloseEvent *event __attribute__((unused))){
    pManager->ChiudiInsInstallazione();
    pManager->ApriInizio();
}
void W_insInstallazzione::on_click_VeiInst(){
    if (datiINST->isEnabled()) datiINST->setDisabled(true);
    else datiINST->setEnabled(true);
}
