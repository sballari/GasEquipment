#include "GuiHeaders/w_insalimentatore.h"
#include "qgroupbox.h"
W_insAlimentatore::W_insAlimentatore():W_InsComponente()
{
   Clay->addLayout(DatiALI());
}
QFormLayout* W_insAlimentatore::DatiALI() {

    QFormLayout* lay = new QFormLayout;



    QRadioButton* Carb = new QRadioButton("carburatore");
    QRadioButton* Iniettore = new QRadioButton("iniettore");
    ACarbRB=Carb;
    AInietRB=Iniettore;
    Carb->setChecked(true);

    QGroupBox* bottoni = new QGroupBox;
    QVBoxLayout* B = new QVBoxLayout;
    B->addWidget(Carb);
    B->addWidget(Iniettore);
    bottoni->setLayout(B);
    bottoni->setFlat(true);

    lay->addRow(bottoni);
    datiIniettore = TipMod();
    lay->addRow(datiIniettore);

    connect(Iniettore, SIGNAL(clicked()),this, SLOT(on_click_Iniettore_RadioB()));
    connect(Carb, SIGNAL(clicked()), this, SLOT(on_click_Carburatore_RadioB()));

    return lay;
}

QGroupBox* W_insAlimentatore::TipMod(){


    QGroupBox* Tipo = new QGroupBox("modalita' di iniezione");
    QGroupBox* Mod =new QGroupBox("tipo di iniezione");

    QVBoxLayout* A = new QVBoxLayout();
    Tipo->setLayout(A);
    QVBoxLayout* B = new QVBoxLayout();
    Mod->setLayout(B);

    QRadioButton* elett = new QRadioButton("elettrico");
    QRadioButton* misto = new QRadioButton("misto");
    QRadioButton* mecc = new QRadioButton("meccanico");
    A->addWidget(elett);
    A->addWidget(misto);
    A->addWidget(mecc);

    QRadioButton* diretto = new QRadioButton("diretto");
    QRadioButton* indiretto = new QRadioButton("indiretto");
    B->addWidget(diretto);
    B->addWidget(indiretto);

    QGroupBox* TipMod = new QGroupBox("dati iniettore");
    QVBoxLayout* lay = new QVBoxLayout;
    TipMod->setLayout(lay);
    lay->addWidget(Tipo);
    lay->addWidget(Mod);

    AEletRB=elett;
    AMistoRB=misto;
    AMeccanicoRB=mecc;

    ADiretto=diretto;
    AIndiretto=indiretto;


    TipMod->setFlat(true);
    TipMod->setEnabled(false);


    return TipMod;
}


void W_insAlimentatore::on_click_Iniettore_RadioB(){
    datiIniettore->setEnabled(true);
    AEletRB->setChecked(true);
    ADiretto->setChecked(true);
}

void W_insAlimentatore::on_click_Carburatore_RadioB(){
    datiIniettore->setEnabled(false);
}
Alimentatore* W_insAlimentatore::creaAlimentatore()const{
    //devo creare un alimentore
    //di che tipo?
    if (AInietRB->isChecked()){
        //creo iniettore. come lo vuoi?
        Iniettore::modalita_iniezione mod;
        if (AEletRB->isChecked()) mod = Iniettore::modalita_iniezione::elettronica;
        if (AMistoRB->isChecked()) mod= Iniettore::modalita_iniezione::mista;
        if (AMeccanicoRB->isChecked()) mod = Iniettore::modalita_iniezione::meccanica;
        Iniettore::tipo_iniezione tip;
        if (ADiretto->isChecked()) tip= Iniettore::tipo_iniezione::diretta;
        if (AIndiretto->isChecked()) tip = Iniettore::tipo_iniezione::indiretta;

        return new Iniettore(mod, tip, daiNomeProd(),daiDataProd() );
    }
    else {//creo carburatore
        return new Carburatore(daiNomeProd(),daiDataProd());
    }
}
