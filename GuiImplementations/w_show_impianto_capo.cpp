#include "GuiHeaders/w_show_impianto_capo.h"
#include <QLayout>
#include <QPushButton>
#include <GuiHeaders/w_addbombola.h>
W_Show_Impianto_Capo::W_Show_Impianto_Capo(Officina* pO,std::string targa):
    W_Show_Impianto(static_cast<const Installazione*>(&(const_cast<const Officina*>(pO)->operator [](targa)))->getImpianto())
  ,pOf(pO),tg(targa),schermataB(nullptr)
{
    QLayout* schema= layout();
    schema->addWidget(creaBottoni());

}

W_Show_Impianto_Capo::~W_Show_Impianto_Capo(){
    if (schermataB) delete schermataB;
}

QGroupBox* W_Show_Impianto_Capo::creaBottoni() const{
    QPushButton* elimina =new QPushButton("elimina bombola");
    QPushButton* agg =new QPushButton("aggiungi bombola");
    QHBoxLayout* la=new QHBoxLayout();
    QGroupBox* ret= new QGroupBox();
    ret->setLayout(la);
    la->addWidget(elimina);
    la->addWidget(agg);
    connect(elimina,SIGNAL(clicked(bool)),this,SLOT(on_click_elimina()));
    connect(agg,SIGNAL(clicked(bool)),this,SLOT(on_click_aggiungi()));
    return ret;
}

 void W_Show_Impianto_Capo::on_click_elimina()const{
     int i=bombolaSelezionata();
     if (i!=-1){
     pOf->rimuoviBombola(tg,i);
     aggiornaLista();
     }


 }
 void W_Show_Impianto_Capo::on_click_aggiungi(){
     if (schermataB)  delete schermataB;
     schermataB = new W_AddBombola(nullptr,nullptr,true);
     schermataB->show();
     connect(schermataB,SIGNAL(bombolaReady()),SLOT(on_signal_bombola_pronta()));


 }
void W_Show_Impianto_Capo::on_signal_bombola_pronta(){
    Bombola* bo= schermataB->crea_bombola();
    pOf->inserisciBombola(tg,*bo);
    aggiornaLista();
    delete bo;
    delete schermataB;
    schermataB = nullptr;


}
