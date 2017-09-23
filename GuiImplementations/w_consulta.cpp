#include "GuiHeaders/w_consulta.h"
#include <QVBoxLayout>
#include <QSignalMapper>
#include <QTextEdit>
#include <QScrollArea>
#include <QListWidget>
#include <QSizePolicy>
#include "ModelloHeaders/err.h"
#include <QPushButton>
#include <QMenu>
#include "GuiHeaders/w_show_componente.h"
#include <QErrorMessage>
#include "ModelloHeaders/errnovalidindex.h"
#include <qcheckbox.h>

W_Consulta::W_Consulta(const Officina *p,GestioneGUI* pm, QWidget *parent):QWidget(parent),
    pOff(p),alert(nullptr), pManager(pm), err(nullptr){
    QVBoxLayout* lay = new QVBoxLayout;
    setMinimumSize(700,750);


    Info = new QTextEdit;
    Info->setReadOnly(true);
    Info->setText("Seleziona una riga della lista");
    setLayout(lay);
    QHBoxLayout* H=new QHBoxLayout();
    H->addWidget(Info);
    H->addLayout(datiRicerca());

    lay->addLayout(H);
    lay->addLayout(Lista_Bottoni());
    setWindowTitle("CONSULTA");
}

QListWidget* W_Consulta::listaInstallazioni()const{
    unsigned int N = pOff->NAutoGestite();

    QListWidget* elenco = new QListWidget;
    for (unsigned int i=0; i<N; i++){
        try {
        QListWidgetItem* a = new QListWidgetItem(QString::fromStdString(pOff->getTarga(i)));
        elenco->addItem(a);
        }
        catch (Err E) {Info->setText("\b problema con indice!");}
    }

    connect (elenco, SIGNAL(itemActivated(QListWidgetItem*)), this,SLOT(on_click_info(QListWidgetItem* )));
    return elenco;
}

W_Consulta::~W_Consulta(){if (err) delete err;}

QHBoxLayout* W_Consulta::Lista_Bottoni() {
    QHBoxLayout* lay = new QHBoxLayout;
    lista=listaInstallazioni();
    lay->addWidget(lista);

    bottoni = new QVBoxLayout;
    QPushButton* Mostra = new QPushButton("Mostra");
    connect(Mostra, SIGNAL(clicked(bool)), this, SLOT(on_click_mostra()));

    bottoni->addWidget(Mostra);





    lay->addLayout(bottoni);
    return lay;

}
void W_Consulta::on_click_mostra() {
    QListWidgetItem* a=lista->currentItem();
    if (a) {

        QString targa = a->text();
        pManager->NascondiConsulta();
        pManager->ApriShowVeiIns(&((*pOff)[targa.toStdString()]));


    }
    else {

        if (err) {err->close(); delete err; err=nullptr;}
        err = new QErrorMessage();
        err->showMessage("selezionare una Veicolo prima");
    }

}

QTextEdit* W_Consulta::creaInfo(const Veicolo& INST) const{
        QString a = QString::fromStdString(INST.getInfo());
        QTextEdit* _Info = new QTextEdit;
        _Info->setText(a);
        _Info->setReadOnly(true);
        _Info->setFrameStyle(1);
        return _Info;
}



void W_Consulta::on_click_info(QListWidgetItem* item){

    std::string targa = (item->text()).toStdString();
    QString inf = QString::fromStdString(pOff->getInfo(targa));
    Info->setText(inf);

}

void W_Consulta::closeEvent(QCloseEvent *event __attribute__((unused))){
    pManager->ChiudiConsulta();
    pManager->ApriInizio();
}



QFormLayout*W_Consulta::datiRicerca(){
    QFormLayout* lay=new QFormLayout();
    prop= new QLineEdit();
    lay->addRow("proprietario ", prop);
    QPushButton* filtra = new QPushButton("filtra");
    alert =new QCheckBox("allerta impianto");
    lay->addWidget(alert);
    lay->addWidget(filtra);
    QLabel* a=new QLabel("se allerta impianto attivo non verranno visualizzati i veicoli");
    lay->addWidget(a);
    connect(filtra, SIGNAL(clicked(bool)), this,SLOT(on_click_filtra()));
    return lay;
}

void W_Consulta::on_click_filtra(){
    QString nome =prop->text();
    std::vector<Veicolo*> ric = pOff->RicercaPerProp(nome.toStdString(),alert->isChecked());
    std::vector<Veicolo*>::const_iterator it=ric.begin();




    while (lista->count())
        delete lista->item(0);



    for (; it<ric.end(); it++){
        QListWidgetItem* a = new QListWidgetItem(QString::fromStdString((*it)->getTarga()));
        lista->addItem(a);
    }



}

void W_Consulta::on_alterazione_targa(std::string nuova_t){
    QListWidgetItem* a=lista->currentItem();
    if (a) {

        a->setText(QString::fromStdString( nuova_t));
    }
    else {

        if (err) {err->close(); delete err; err=nullptr;}
        err = new QErrorMessage();
        err->showMessage("selezionare una Veicolo prima");
    }
}
