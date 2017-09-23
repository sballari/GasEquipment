#include "GuiHeaders/w_inizio.h"
#include <QVBoxLayout>
#include "GuiHeaders/w_consulta.h"
#include <QPushButton>
#include <QGridLayout>

W_Inizio::W_Inizio(GestioneGUI* pm,QWidget * parent):QWidget(parent), pManager(pm)
{
    QVBoxLayout* lay = new QVBoxLayout();
    setLayout(lay);
    setWindowTitle("OPERAZIONI SUL DB");
    resize(500,500);

    //creazione finestra di inserimento
    lay->addWidget(Operazioni());

}



QGroupBox* W_Inizio::Operazioni(){
    QGroupBox* gruppo = new QGroupBox("operazioni sul DB dell'Officina");
    lay = new QVBoxLayout;
    gruppo->setLayout(lay);

    QPushButton* Cambia = new QPushButton ("Cambia Utente");
    QPushButton* Consulta_DB = new QPushButton("Consulta DB dell'Officina");
    lay->addWidget(Consulta_DB);
    lay->addWidget(Cambia);

    connect(Consulta_DB, SIGNAL(clicked()), this, SLOT(on_consulta()));
    connect(Cambia, SIGNAL(clicked()), this, SLOT(on_cambia()));

    return  gruppo;
}


void W_Inizio::on_cambia()const{
    pManager->CambiaUtenteDaInizio();
}
void W_Inizio::on_consulta()const{
    pManager->ChiudiInizio();
    pManager->ApriConsulta();
}

void W_Inizio::closeEvent(QCloseEvent *event __attribute__((unused))){
    pManager->CambiaUtenteDaInizio();
}

