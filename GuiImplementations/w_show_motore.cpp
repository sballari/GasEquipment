#include "GuiHeaders/w_show_motore.h"
#include "qlabel.h"
#include "qspinbox.h"




W_show_Motore::W_show_Motore(const Motore *pM): W_Show_Componente(pM), pMotore(pM)
{
    layComp->addLayout(datiSpecifici());
}


QLayout* W_show_Motore::datiSpecifici() const{


    QFormLayout* slay = new QFormLayout();

    QLabel* sovralimentato = (pMotore->isSovralimentato())? new QLabel("SI") : new QLabel("NO");

    QSpinBox* cilindrata = new QSpinBox();
    QSpinBox* nCilindri = new QSpinBox();
    QDoubleSpinBox* rapporto = new QDoubleSpinBox();
    QDoubleSpinBox* coppiaMax = new QDoubleSpinBox();

    cilindrata->setReadOnly(true);
    cilindrata->setMaximum(9999);
    nCilindri->setReadOnly(true);
    rapporto->setReadOnly(true);
    coppiaMax->setReadOnly(true);

    cilindrata->setValue(pMotore->getCilindrata());
    nCilindri->setValue(pMotore->getN_cilindri());
    rapporto->setValue(pMotore->getRapporto_compressione());
    coppiaMax->setValue(pMotore->getCoppia_max());

    slay->addRow("cilindrata:", cilindrata);
    slay->addRow("n cilindri:", nCilindri);
    slay->addRow("rapporto di compressione:", rapporto);
    slay->addRow("coppia massima:", coppiaMax);
    slay->addRow("sovralimentato:", sovralimentato);

    return slay;
}
