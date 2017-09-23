#include "GuiHeaders/w_show_veicolo_capo.h"
#include "qpushbutton.h"

W_Show_Veicolo_Capo::W_Show_Veicolo_Capo(const Officina *pO, std::string tg, GestioneGUI* pg):
    W_Show_Veicolo(&((*pO)[tg]),pg),targa(tg)
{
    setWindowTitle("modalita' capo");
    aggiungi_Modifica_dati();


}

void W_Show_Veicolo_Capo::aggiungi_Modifica_dati(){
    QPushButton* alter=new QPushButton("Modifica");
    layerD->addRow(alter);
    connect(alter,SIGNAL(clicked(bool)),this,SLOT(on_click_modifica_dati_auto()));
}

void W_Show_Veicolo_Capo::on_click_modifica_dati_auto(){
    pManager->ApriAlteraVeicolo(targa);
    pManager->ChiudiShowVeicolo();
}
std::string W_Show_Veicolo_Capo::mostra_targa() const
{return targa;}
