#include "GuiHeaders/w_insveicolo.h"
#include <QLineEdit>
#include <QDateEdit>

W_insVeicolo::W_insVeicolo(QWidget *parent) : QWidget(parent)
{
    Clay = new QVBoxLayout();
    Clay->addLayout(datiAuto());
    Clay->addSpacing(5);
    Clay->addLayout(datiVeicolo());
    setLayout(Clay);


}

QFormLayout* W_insVeicolo::datiAuto(){
    QFormLayout* lay = new QFormLayout;

    QLineEdit* proprietario = new QLineEdit;
    QLineEdit* targa = new QLineEdit;
    QDateEdit* immatricolazione = new QDateEdit;
    QDateEdit* ultimaRev = new QDateEdit;

    AProprietario = proprietario;
    ATarga= targa;
    AImmatricolazione= immatricolazione;
    AUltimaRevisione = ultimaRev;

    lay->addRow("proprietario: ",proprietario);
    lay->addRow("targa: ",targa);
    lay->addRow("data di immatricolazione: ",immatricolazione);
    lay->addRow("data ultima revisione: ",ultimaRev);


    return lay;

}
QHBoxLayout* W_insVeicolo::datiVeicolo(){
    QGroupBox* Gmot=new QGroupBox("Motore");
    QVBoxLayout* A=new QVBoxLayout();
    Gmot->setLayout(A);
    QGroupBox* Gali=new QGroupBox("Alimentatore");
    QVBoxLayout* B=new QVBoxLayout();
    Gali->setLayout(B);
    QGroupBox* Gscar=new QGroupBox("Scarico");
    QVBoxLayout* C=new QVBoxLayout();
    Gscar->setLayout(C);

    mot=new W_insMotore();
    A->addWidget(mot);
    A->addStretch();
    ali=new W_insAlimentatore();
    B->addWidget(ali);
    B->addStretch();
    scar=new W_insScarico();
    C->addWidget(scar);
    C->addStretch();


    lay= new QHBoxLayout();

    lay->addWidget(Gmot);
    lay->addWidget(Gali);
    lay->addWidget(Gscar);

    return lay;

}

Veicolo* W_insVeicolo::creaVeicolo() const{
    std::string proprietario = (AProprietario->text()).toStdString();
    std::string targa = (ATarga->text()).toStdString();
    Data immatricolazione = AImmatricolazione->date();
    Data ultimaRev = AUltimaRevisione->date();

    Motore* OGGmot = mot->creaMotore();
    Alimentatore* OGGali = ali->creaAlimentatore();
    Scarico* OGGscar = scar->creaScarico();

    Veicolo* VEC=new Veicolo(proprietario,targa,immatricolazione, ultimaRev, *OGGmot, *OGGali , *OGGscar);
    delete OGGmot;
    delete OGGscar;
    delete OGGali;
    return VEC;
}
