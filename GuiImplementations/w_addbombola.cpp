#include "GuiHeaders/w_addbombola.h"
#include <QLineEdit>
#include <QDateEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QFormLayout>
#include <QGridLayout>
W_AddBombola::W_AddBombola(Impianto* i, QWidget* parent, bool noIns):QWidget(parent), imp(i),no_inserimento(noIns)
{
    QGridLayout* griglia= new QGridLayout;
    griglia->addWidget(datiBomb(),0,0);
    this->setLayout(griglia);
    setWindowTitle("AGGIUNGI BOMBOLA");
}
//se no_inserimento e' a true allora il puntatore ad impianto sara' ignorato e non sara' alla pressione di aggiungi
//verra' inviato un segnale che indica che la bombola e' pronta e si chiudera' la schermata.
QGroupBox* W_AddBombola::datiBomb(){

    QGroupBox* gruppo= new QGroupBox;
    QFormLayout* lay = new QFormLayout;

    QLineEdit* produttore = new QLineEdit;
    QDateEdit* data_prod = new QDateEdit;
    QDoubleSpinBox* cap = new QDoubleSpinBox;
    QDateEdit* ultimaRev = new QDateEdit;
    AProduttore = produttore;
    ADataProd = data_prod;
    ACapacita= cap;
    AUltimaRevisione= ultimaRev;


    lay->addRow("produttore:", produttore);
    lay->addRow("data di produzione:", data_prod);
    lay->addRow("capacita':", cap);
    lay->addRow("ultima revisione:", ultimaRev);

    QPushButton* aggiungi = new QPushButton("Aggiungi");
    AAggiungiButton = aggiungi;
    if (!no_inserimento)connect (aggiungi, SIGNAL(clicked()), this, SLOT(on_click_add()));
    else {
        connect (aggiungi, SIGNAL(clicked()), this, SLOT(bombola_pronta()));
    }
    lay->addRow(aggiungi);


    gruppo->setLayout(lay);
    return gruppo;
}

void W_AddBombola::on_click_add(){
    Bombola* a = crea_bombola();
    imp->inserisciBombola(*a);
    delete a;
    hide();

}

Bombola* W_AddBombola::crea_bombola() const {
    double cap = ACapacita->value();
    std::string prod = (AProduttore->text()).toStdString();
    Data UR = AUltimaRevisione->date();
    Data DProd = ADataProd->date();

    return new Bombola(cap,UR,prod, DProd);

}
void W_AddBombola::bombola_pronta() {
    this->hide();
    emit bombolaReady();
}
