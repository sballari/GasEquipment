#include "GuiHeaders/w_consulta_capo.h"
#include "ModelloHeaders/errnovalidindex.h"

W_Consulta_Capo::W_Consulta_Capo( Officina* p, GestioneGUI* pm):W_Consulta(p,pm),pOfficina(p)
{
    setWindowTitle("modalita' capo");
    aggiungi_elimina();
}

void W_Consulta_Capo::on_click_cancella(){
    QListWidgetItem* a=lista->currentItem();
    int b=lista->currentRow();
    if (a) {

        QString targa = a->text();
        try{
            pOfficina->RimuoviVeicolo(targa.toStdString());
            delete lista->takeItem(b);
        }
        catch (ErrNoValidIndex e){
            if (err) {err->close(); delete err; err=nullptr;}
            err = new QErrorMessage();
            err->showMessage("Errore nella cancellazzione");
        };
    }
    else {
        if (err) {err->close(); delete err; err=nullptr;}
        err = new QErrorMessage();
        err->showMessage("selezionare un Veicolo prima");
    }
}


void W_Consulta_Capo::aggiungi_elimina(){
    QPushButton* Elimina = new QPushButton("Elimina");
    bottoni->addWidget(Elimina);
    connect(Elimina, SIGNAL(clicked(bool)), this, SLOT(on_click_cancella()));
}

void W_Consulta_Capo::on_click_mostra() {
    QListWidgetItem* a=lista->currentItem();
    if (a) {


        QString targa = a->text();
        pManager->NascondiConsulta();
        pManager->ApriShowVeiIns_Capo(targa.toStdString());


    }
    else {

        if (err) {err->close(); delete err; err=nullptr;}
        err = new QErrorMessage();
        err->showMessage("selezionare una Veicolo prima");
    }

}
