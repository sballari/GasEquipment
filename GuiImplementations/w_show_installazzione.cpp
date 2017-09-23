#include "GuiHeaders/w_show_installazzione.h"
#include "QHBoxLayout"
#include "GuiHeaders/w_show_impianto.h"

W_Show_Installazzione::W_Show_Installazzione(const Installazione* pI,GestioneGUI*ph)
    :W_Show_Veicolo(pI,ph), pInstallazione(pI)
{
    QLayout* lay = layout();
    lay->addWidget(creaBoxDatiImpianto());
    setWindowTitle("SHOW INSTALLAZIONE");
}

QGroupBox* W_Show_Installazzione::creaBoxDatiImpianto() const{
    QGroupBox* box = new QGroupBox("IMPIANTO");
    QVBoxLayout* lay = new QVBoxLayout();
    box->setLayout(lay);
    lay->addWidget(new W_Show_Impianto(pInstallazione->getImpianto()));
    return box;


}
 void W_Show_Installazzione::closeEvent(QCloseEvent *event __attribute__((unused))){
    pManager->ChiudiShowInstallazione();
    pManager->MostraConsulta();
 }
