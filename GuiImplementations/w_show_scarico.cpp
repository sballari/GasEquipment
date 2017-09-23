#include "GuiHeaders/w_show_scarico.h"
#include "GuiHeaders/w_show_componente.h"
#include <qlabel.h>


W_Show_Scarico::W_Show_Scarico(const Scarico *pS) : W_Show_Componente(pS), pScarico(pS)
{
    //QLayout* lay = this->layout();
    layComp->addLayout(datiSpecifici());

}

QLayout* W_Show_Scarico::datiSpecifici() const{


    QFormLayout* slay = new QFormLayout();


    QLabel* Catalizzatore = new QLabel();
    QLabel* SondaLambda = new QLabel();

    if (pScarico->hasCatalizzatore()) Catalizzatore->setText("SI");
    else Catalizzatore->setText("NO");
    if (pScarico->hasSondaLambda()) SondaLambda->setText("SI");
    else SondaLambda->setText("NO");

    slay->addRow("catalizzatore:", Catalizzatore);
    slay->addRow("sonda lambda:", SondaLambda);


    return slay;

}
