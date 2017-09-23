#include "GuiHeaders/w_insimpianto.h"
#include "qgroupbox.h"
W_insImpianto::W_insImpianto(QWidget *parent) : QWidget(parent),IMaticGPL(nullptr),
    IDirectGPL(nullptr),INoCatGPL(nullptr),IOmegaGPL(nullptr),aggiunta(nullptr), tmp(nullptr)
{
    setLayout(datiImpianto());
}

W_insImpianto::~W_insImpianto(){
    if (tmp) delete tmp;
}

QFormLayout* W_insImpianto::datiImpianto(){

    QFormLayout* lay = new QFormLayout;




    QRadioButton* MaticGPL = new QRadioButton("MaticGPL");
    QRadioButton* DirectGPL = new QRadioButton("DirectGPL");
    QRadioButton* NoCatGPL = new QRadioButton("NoCatGPL");
    QRadioButton* OmegaGPL = new QRadioButton("OmegaGPL");
    QPushButton* AddBomb = new QPushButton("Add Bombola");
    MaticGPL->setChecked(true);

    connect(MaticGPL, SIGNAL(clicked()), this, SLOT(on_click_Matic()));
    connect(DirectGPL, SIGNAL(clicked()), this, SLOT(on_click_Direct()));
    connect(NoCatGPL, SIGNAL(clicked()), this, SLOT(on_click_NoCat()));
    connect(OmegaGPL, SIGNAL(clicked()), this, SLOT(on_click_Omega()));
    connect(AddBomb, SIGNAL(clicked()), this, SLOT(on_click_Aggiunta()));

    QGroupBox* impiantoGPL = new QGroupBox("impianto GPL");

    QVBoxLayout* A = new QVBoxLayout();
    impiantoGPL->setLayout(A);

    A->addWidget(MaticGPL);
    A->addWidget(DirectGPL);
    A->addWidget(NoCatGPL);
    A->addWidget(OmegaGPL);

    //QDateEdit* dataInstallazione = new QDateEdit;
    //IDataInstallazione = dataInstallazione;
    IMaticGPL = MaticGPL;
    IDirectGPL = DirectGPL;
    INoCatGPL = NoCatGPL;
    IOmegaGPL = OmegaGPL;

    //lay->addRow("data di installazione", dataInstallazione);
    lay->addRow(impiantoGPL);
    lay->addRow(AddBomb);



    return lay;
}
void W_insImpianto::on_click_Matic(){
    if (tmp) delete tmp;
    tmp = new MaticGPL;
}

void W_insImpianto::on_click_Omega(){
    if (tmp) delete tmp;
    tmp = new OmegaGPL;

}

void W_insImpianto::on_click_NoCat(){
    if (tmp) delete tmp;
    tmp = new NoCatGPL;

}

void W_insImpianto::on_click_Direct(){
    if (tmp) delete tmp;
    tmp = new DirectGPL;

}

void W_insImpianto::on_click_Aggiunta(){
    if (aggiunta){
        aggiunta->close();
        delete aggiunta;
    }
    if (!tmp) tmp = creaImpianto();
    aggiunta = new W_AddBombola(tmp);
    aggiunta->show();
}
Impianto* W_insImpianto::creaImpianto() const{
    Impianto* imp=nullptr;
    if (tmp) imp=tmp;
    else {
        if (IOmegaGPL->isChecked()) imp= new OmegaGPL();
        if (IMaticGPL->isChecked()) imp= new MaticGPL();
        if (INoCatGPL->isChecked()) imp= new NoCatGPL();
        if (IDirectGPL->isChecked()) imp= new DirectGPL();
    }

    return imp;
}

//void W_insImpianto::ResetDatiImpianto(){
//    tmp=nullptr;
//}
