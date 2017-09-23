#include "GuiHeaders/w_insmotore.h"

W_insMotore::W_insMotore():W_InsComponente()
{
     Clay->addLayout(datiMotore());
}
QFormLayout* W_insMotore::datiMotore(){

    QFormLayout* lay = new QFormLayout;
    QSpinBox* nCil = new QSpinBox;
    QSpinBox* cil = new QSpinBox;
    QDoubleSpinBox* cpM = new QDoubleSpinBox;
    QDoubleSpinBox* rapporto = new QDoubleSpinBox;
    QCheckBox* turbo = new QCheckBox("sovralimentato");

    cil->setMaximum(10000);
    cpM->setMaximum(100000);
    cil->setSuffix(" cc");
    cpM->setSuffix(" Nm");
    rapporto->setSuffix(" kW");


    lay->addRow("n. cilindri:", nCil);
    lay->addRow("cilindrata:", cil);
    lay->addRow("coppia massima:", cpM);
    lay->addRow("rapporto di compressione:", rapporto);
    lay->addRow(turbo);


    //assegnazione ad elementi
    MNcil=nCil;
    MCilindrata=cil;
    MCopMax=cpM;
    MRappCompr=rapporto;
    MTurbo=turbo;
    //fine--------------------

    return lay;
}
Motore* W_insMotore::creaMotore() const{
    int n_cil = MNcil->value();
    int cilindrata = MCilindrata->value();
    double Rapporto = MRappCompr->value();
    double coppiaMax= MCopMax->value();

    bool turbo = MTurbo->isChecked();

    return new Motore(n_cil, cilindrata, Rapporto, coppiaMax,daiNomeProd(),daiDataProd(),turbo);
    //questo return chiama il costruttore di copia per ritornare l'oggetto anonino di ritorno
}
