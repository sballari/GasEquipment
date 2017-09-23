#include "GuiHeaders/w_alter_veicolo.h"
#include <QLineEdit>
#include <QDateEdit>
#include <QPushButton>
#include "ModelloHeaders/err.h"
#include "ModelloHeaders/errchiave.h"
#include "ModelloHeaders/errnovalidindex.h"
#include <qmessagebox.h>


W_alter_veicolo::W_alter_veicolo(Officina* Pof,std::string tga,GestioneGUI* p ,QWidget *parent) : QWidget(parent),pO(Pof)
  ,targa(tga),pman(p)
{
    setLayout(creaForm());
}


QFormLayout* W_alter_veicolo::creaForm(){
    QFormLayout* lay = new QFormLayout;

    QLineEdit* proprietario = new QLineEdit;
    QLineEdit* targaW = new QLineEdit;
    QDateEdit* immatricolazione = new QDateEdit;
    QDateEdit* ultimaRev = new QDateEdit;

    AProprietario = proprietario;
    ATarga= targaW;
    AImmatricolazione= immatricolazione;
    AUltimaRevisione = ultimaRev;

    const Officina * p=pO;
    proprietario->setText(QString::fromStdString(((p->operator[](targa)).getProprietario())));
    targaW->setText(QString::fromStdString( (p->operator[](targa)).getTarga()));
    immatricolazione->setDate((p->operator[](targa)).getImmatricolazione());
    ultimaRev->setDate((p->operator[](targa)).getUltimaRevisione());

    lay->addRow("proprietario: ",proprietario);
    lay->addRow("targa: ",targaW);
    lay->addRow("data di immatricolazione: ",immatricolazione);
    lay->addRow("data ultima revisione: ",ultimaRev);

    QPushButton* applica=new QPushButton("Altera");
    connect(applica, SIGNAL(clicked(bool)), this,SLOT(on_click_applica()));
    lay->addRow(applica);
    return lay;
}

void W_alter_veicolo::on_click_applica(){
    try{
        pO->changeTarga(targa,ATarga->text().toStdString());
        targa=ATarga->text().toStdString();
        emit targa_alterata(targa);
        pO->changeProprietario(targa,AProprietario->text().toStdString());
        pO->changeDataImmatricolazione(targa, AImmatricolazione->date());
        pO->changeDataUltimaRevisione(targa,AUltimaRevisione->date());
        emit closeEvent(nullptr);

    }
    catch (ErrChiave E) {
        QMessageBox::warning(0, "Attenzione!", "Vincolo di chiave non rispettato");
    }
    catch (ErrNoValidIndex E){
        QMessageBox::warning(0, "Errore!", "errore inaspettato");
    }

}

void W_alter_veicolo::closeEvent(QCloseEvent *event __attribute__((unused))){
    pman->ChiudiAlteraVeicolo();
    pman->ApriShowVeiIns_Capo(targa);
}
