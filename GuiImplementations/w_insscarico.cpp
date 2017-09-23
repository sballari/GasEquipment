#include "GuiHeaders/w_insscarico.h"

W_insScarico::W_insScarico():W_InsComponente()
{
    Clay->addLayout(datiScarico());
}
QFormLayout* W_insScarico::datiScarico(){

    QFormLayout* lay = new QFormLayout;


    QCheckBox* cat = new QCheckBox("catalizzatore");
    QCheckBox* sonda = new QCheckBox("sonda lambda");


    SCatalizzatore= cat;
    SSondaLambda= sonda;
    lay->addRow(cat);
    lay->addRow(sonda);

    return lay;
}
Scarico* W_insScarico::creaScarico() const{

    bool cat = SCatalizzatore->isChecked();
    bool sonda = SSondaLambda->isCheckable();
    return new Scarico(cat, sonda, daiNomeProd(), daiDataProd());
}
