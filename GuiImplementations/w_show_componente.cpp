#include "GuiHeaders/w_show_componente.h"
#include <QFormLayout>
#include <QLabel>
#include <QDateEdit>

W_Show_Componente::W_Show_Componente(const Componente *pC, QWidget *parent)
    :QWidget(parent), pComponente(pC)

{
    QVBoxLayout* lay = new QVBoxLayout();
    setLayout(lay);
    layComp=lay;
    lay->addLayout(creaMain());

}


QLayout* W_Show_Componente::creaMain() const{


    QFormLayout* lay = new QFormLayout();
    QLabel* NomeProduttore = new QLabel();
    QDateEdit* DataProduzione = new QDateEdit(pComponente->getDataProduzione());
    NomeProduttore->setText( QString::fromStdString(pComponente->getNomeProduttore()));
    DataProduzione->setReadOnly(true);
    lay->addRow("produttore:", NomeProduttore);
    lay->addRow("data produzione:", DataProduzione);
    return lay;

}

