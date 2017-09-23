#include "GuiHeaders/w_show_installazzione_capo.h"
#include "GuiHeaders/w_show_impianto_capo.h"


W_Show_Installazzione_Capo::W_Show_Installazzione_Capo(Officina *pO, std::string tgs,GestioneGUI* pg)
    :W_Show_Veicolo_Capo(pO,tgs,pg),pOf(pO)

{
    QLayout* lay = layout();
    lay->addWidget(creaBoxDatiImpianto());
    setWindowTitle("modalita' capo");
}
QGroupBox* W_Show_Installazzione_Capo::creaBoxDatiImpianto() const{
    QGroupBox* box = new QGroupBox("IMPIANTO");
    QVBoxLayout* lay = new QVBoxLayout();
    box->setLayout(lay);

    lay->addWidget(new W_Show_Impianto_Capo(pOf,mostra_targa()));
    return box;


}
 void W_Show_Installazzione_Capo::closeEvent(QCloseEvent *event __attribute__((unused))){
    pManager->ChiudiShowInstallazione();
    pManager->MostraConsulta();
 }
