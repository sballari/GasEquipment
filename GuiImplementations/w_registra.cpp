#include "GuiHeaders/w_registra.h"
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>
#include <QApplication>
#include <QLineEdit>
#include <QRadioButton>
#include <QString>
#include <QVBoxLayout>
#include <ModelloHeaders/utente.h>
#include <ModelloHeaders/capo.h>
#include <ModelloHeaders/operaio.h>
#include "ModelloHeaders/err.h"

#include <ModelloHeaders/errchiave.h>
#include <QMessageBox>
#include <QFormLayout>
W_Registra::W_Registra (DB_utenti* p, GestioneGUI* pm,QWidget * parent): QWidget(parent),manager(pm), pDBu(p){
    QGridLayout* griglia = new QGridLayout;

    griglia->addWidget(tipologia(), 0,0);
    griglia->addWidget(dati(), 0,1);


    setLayout(griglia);

    setWindowTitle("nuovo utente");
    resize(480,320);
}
QGroupBox * W_Registra::tipologia(){
    QGroupBox* gruppo = new QGroupBox("tipologia utente");

    QRadioButton* capo = new QRadioButton("utente capo");
    cp=capo;
    QRadioButton* dip = new QRadioButton("utente operaio");
    dip->setChecked(true);
    dp=dip;
    QVBoxLayout* vbox = new QVBoxLayout;
    vbox->addWidget(capo);
    vbox->addWidget(dip);
    vbox->addStretch(1);
    gruppo->setLayout(vbox);


    return gruppo;
}

QGroupBox * W_Registra::dati(){
    QGroupBox* gruppo = new QGroupBox("dati utente");

    QLineEdit* nome = new QLineEdit();
    nome->setEchoMode(QLineEdit::EchoMode::Normal);
    nm=nome;
    QLineEdit* passworld = new QLineEdit();
    passworld->setEchoMode(QLineEdit::EchoMode::Password);
    ps=passworld;
    QPushButton* registra = new QPushButton(tr("registra"));
    registra->setFont(QFont("Times", 18, QFont::Bold));
    registra->setGeometry(10,40,180,20);

    connect (registra,SIGNAL(clicked()), this, SLOT(registra()));



    QFormLayout* vbox = new QFormLayout();
    vbox->addRow("nome ",nome);
    vbox->addRow("passworld",passworld);
    vbox->addWidget(registra);
    gruppo->setLayout(vbox);

    return gruppo;
}
void W_Registra::registra(){
    std::string nome = (nm->text()).toStdString();
    std::string pass = (ps->text()).toStdString();
    bool ok=true;
    if (nome=="") {
         QMessageBox::warning(0, "Errore!", "nome non inserito");;
        return ;
    }
    if (pass==""){
         QMessageBox::warning(0, "Errore!", "passworld non inserita");
        return;
    }
    try{
        if (cp->isChecked()){
            Capo cap (nome,pass);
            pDBu->nuovoUtente(cap);
        }

        if (dp->isChecked()){
            Operaio op (nome, pass);
            pDBu->nuovoUtente(op);
        }
    }
    catch (ErrChiave c){
         QMessageBox::warning(0, "Errore!", "nome gia' in uso ");
        ok=false;
    }
    if(ok)  QMessageBox::information(0, "Sucesso", "registrazione effuttuata");
}

void W_Registra::closeEvent(QCloseEvent *event)
  {

    manager->FineReg();


  }
