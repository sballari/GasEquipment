#include "GuiHeaders/w_show_veicolo.h"
#include "QFormLayout"
#include "QLabel"
#include "QDateEdit"
#include "GuiHeaders/w_show_alimentatore.h"
#include "GuiHeaders/w_show_iniettore.h"
#include "GuiHeaders/w_show_carburatore.h"
#include "GuiHeaders/w_show_scarico.h"
#include "GuiHeaders/w_show_motore.h"

W_Show_Veicolo::W_Show_Veicolo(const Veicolo* pV, GestioneGUI *pg, QWidget *parent) :QWidget(parent),pManager(pg), pVeicolo(pV)
{
    QVBoxLayout* SuperLay = new QVBoxLayout();
    setLayout(SuperLay);
    QGridLayout* mainLay = new QGridLayout();
    SuperLay->addLayout(mainLay);
    mainLay->addWidget(datiVeicolo(),0,0);
    mainLay->addWidget(datiScarico(),0,1);
    mainLay->addWidget(datiMotore(),1,0);
    mainLay->addWidget(datiAlimentatore(),1,1);
}



QGroupBox* W_Show_Veicolo::datiVeicolo() {
    QGroupBox* box = new QGroupBox();
    QFormLayout* lay = new QFormLayout();
    box->setLayout(lay);
    layerD=lay;

    QLabel* proprietario = new QLabel(QString::fromStdString(pVeicolo->getProprietario()));
    QLabel* targa = new QLabel(QString::fromStdString(pVeicolo->getTarga()));
    QDateEdit* imm = new QDateEdit(pVeicolo->getImmatricolazione());
    QDateEdit* rev = new QDateEdit(pVeicolo->getUltimaRevisione());
    imm->setReadOnly(true);
    rev->setReadOnly(true);

    lay->addRow("Proprietario:", proprietario);
    lay->addRow("Targa:", targa);
    lay->addRow("Data Immatricolazione:", imm);
    lay->addRow("Ultima Revisione:", rev);
    return box;
}
QGroupBox* W_Show_Veicolo::datiScarico() const{
    QGroupBox* box = new QGroupBox("SCARICO");
    QVBoxLayout* lay = new QVBoxLayout();
    box->setLayout(lay);
    lay->addWidget(new W_Show_Scarico(&(pVeicolo->getScarico())));
    return box;


}
 QGroupBox* W_Show_Veicolo::datiAlimentatore() const{
     QGroupBox* box = new QGroupBox("ALIMENTATORE");
     QVBoxLayout* lay = new QVBoxLayout();
     box->setLayout(lay);
     const Alimentatore* pAli = &(pVeicolo->getAlimentatore());
     const Iniettore* pI = dynamic_cast<const Iniettore *>(pAli);
     const Carburatore* pC = dynamic_cast<const Carburatore *>(pAli);
     if (pI) lay->addWidget(new W_Show_Iniettore(pI));
     if (pC) lay->addWidget(new W_Show_Carburatore(pC));
     return box;
 }
  QGroupBox* W_Show_Veicolo::datiMotore() const{
      QGroupBox* box = new QGroupBox("MOTORE");
      QVBoxLayout* lay = new QVBoxLayout();
      box->setLayout(lay);
      lay->addWidget(new W_show_Motore(&(pVeicolo->getMotore())));
      return box;

  }
  void W_Show_Veicolo::closeEvent(QCloseEvent *event __attribute__((unused))){
      pManager->ChiudiShowVeicolo();
      pManager->MostraConsulta();

  }
