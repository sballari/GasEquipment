#include "GuiHeaders/w_show_iniettore.h"
#include <QVBoxLayout>
#include "GuiHeaders/w_show_componente.h"
#include <QLabel>

W_Show_Iniettore::W_Show_Iniettore(const Iniettore* pI) :W_Show_Alimentatore(pI), pIniettore(pI)
{

    layComp->addLayout(datiSpecifici());
}



QLayout* W_Show_Iniettore::datiSpecifici() const{


    QFormLayout* slay = new QFormLayout();


    QLabel* Modalita = new QLabel(QString::fromStdString(Iniettore::ModToString(pIniettore->getModIN())));
    QLabel* Tipo = new QLabel(QString::fromStdString(Iniettore::TipoToString(pIniettore->getTipoIN())));
    QLabel* i = new QLabel("iniettore");

    slay->addRow(i);
    slay->addRow("modalita':", Modalita);
    slay->addRow("tipo:", Tipo);

    return slay;

}
