#include "GuiHeaders/w_show_alimentatore.h"
#include <qlabel.h>

W_Show_Alimentatore::W_Show_Alimentatore(const Alimentatore *pA):W_Show_Componente(pA), pAlimentatore(pA)
{

    layComp->addLayout(datiSpecifici());
}


QLayout* W_Show_Alimentatore::datiSpecifici() const{

    QFormLayout* slay = new QFormLayout();
    //nessuna info da visualizzare
    return slay;
}
