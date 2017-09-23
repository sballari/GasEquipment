#include "GuiHeaders/w_show_carburatore.h"
#include <QLabel>

W_Show_Carburatore::W_Show_Carburatore(const Carburatore* pC) :W_Show_Alimentatore(pC),pCarburatore(pC)

{

    layComp->addLayout(datiSpecifici());
}

QLayout* W_Show_Carburatore::datiSpecifici() const{


    QVBoxLayout* slay = new QVBoxLayout();
    QLabel* i = new QLabel("Carburatore");
    slay->addWidget(i);

    return slay;

}
