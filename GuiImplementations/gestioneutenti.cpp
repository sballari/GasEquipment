#include "GuiHeaders/gestioneutenti.h"
#include <QVBoxLayout>
#include "ModelloHeaders/errnovalidindex.h"
#include <QFormLayout>
#include <QLabel>
#include <QMessageBox>
#include "ModelloHeaders/errchiave.h"
#include <QPushButton>
#include "GuiHeaders/w_registra.h"
GestioneUtenti::GestioneUtenti(DB_utenti* pDB,GestioneGUI *pM, QWidget *parent) :QWidget(parent),
    pManager(pM),db_utenti(pDB),nome(nullptr),pass(nullptr), modificaU(nullptr)
{
    QHBoxLayout* lay=new QHBoxLayout();
    setLayout(lay);
    lay->addWidget(generaListaUtenti());
    lay->addWidget(generaDatiUtenti());


}
GestioneUtenti::~GestioneUtenti(){
    if (modificaU) {
        modificaU->close();
        delete modificaU;
    }
}

QListWidget* GestioneUtenti::generaListaUtenti(){
    unsigned int N = db_utenti->NumeroUtenti();

    listaUtenti = new QListWidget();
    for (unsigned int i=0; i<N; i++){

        QListWidgetItem* a = new QListWidgetItem(QString::fromStdString(db_utenti->getNome(i)));
        listaUtenti->addItem(a);

    }
    connect(listaUtenti,SIGNAL(itemChanged(QListWidgetItem*)),this,SLOT(setDati(QListWidgetItem*)));
    connect (listaUtenti, SIGNAL(itemActivated(QListWidgetItem*)), this,SLOT(setDati(QListWidgetItem*)));
    return listaUtenti;
}


void GestioneUtenti::closeEvent(QCloseEvent *event __attribute__((unused)) ){
    pManager->ChiudiGestioneUtenti();

}

QFormLayout*  GestioneUtenti::creaFormDati(){
    QFormLayout* f = new QFormLayout();
    nomeL= new QLabel( "--");
    passL= new QLabel("--");
    tipoL= new QLabel("--");
    f->addRow("NOME: ",nomeL);
    f->addRow("PASS: ", passL);
    f->addRow("TIPO",tipoL);
    return f;
}

QGroupBox* GestioneUtenti::generaDatiUtenti() {
    QVBoxLayout* v=new QVBoxLayout();
    v->addLayout(creaFormDati());
    QGroupBox* g= new QGroupBox();
    g->setLayout(v);



    QPushButton* elimina = new QPushButton("elimina");
    QPushButton* mod=new QPushButton("modifica");
    QPushButton* add= new QPushButton("aggiungi");


    connect(elimina,SIGNAL(clicked(bool)),this,SLOT(on_click_el()));
    connect(mod,SIGNAL(clicked(bool)),this,SLOT(on_click_mod()));
    connect (add,SIGNAL(clicked(bool)), this ,SLOT(on_click_add()));
    v->addWidget(elimina,1,0);
    v->addWidget(mod,2,0);
    v->addWidget(add,3,0);

    return g;

}

void GestioneUtenti::setDati(QListWidgetItem* a){

    QString nome = a->text();
    nomeL->setText(nome);
    passL->setText(QString::fromStdString(db_utenti->getPass(nome.toStdString())));
    tipoL->setText(QString::fromStdString(db_utenti->getTipo(nome.toStdString())));

}

void GestioneUtenti::on_click_el() const  {
    QListWidgetItem* a= listaUtenti->currentItem();
    if (a){

        QString nome = a->text();
        try{
            db_utenti->eliminaUtente(nome.toStdString());
            delete a;
            QString t="Eliminazione account "+nome+" effettuata";
            QMessageBox::information(0,"Dialogo",t);
        }
        catch (ErrNoValidIndex e){
            QMessageBox::warning(0, "Errore!", "Errore eliminazione utente");
        }
    }
    else QMessageBox::warning(0, "Errore!", "selezionare prima un utente");

}

QFormLayout* GestioneUtenti::creaAlteraUtente(bool nuovo) {
    QFormLayout* f= new QFormLayout();
    nome=new QLineEdit();
    pass=new QLineEdit();
    QLabel* d = new QLabel();
    capo=new QRadioButton("capo");
    op=new QRadioButton("operaio");
    if (nuovo) {d->setText("inserimento nuovo utente"); capo->setChecked(true);}
    else {
        d->setText("modifica utente");
        QString n = listaUtenti->currentItem()->text();
        nome->setText(n);
        pass->setText(QString::fromStdString(db_utenti->getPass(n.toStdString())));
        if (db_utenti->getTipo(n.toStdString())=="Capo") capo->setChecked(true);
        else op->setChecked(true);
    }
    f->addRow(d);
    f->addRow("nome ",nome);
    f->addRow("pass ",pass);

    QPushButton* ok= new QPushButton("OK");
    QHBoxLayout* bot=new QHBoxLayout();
    bot->addWidget(capo);
    bot->addWidget(op);
    QGroupBox* bottoni= new QGroupBox("tipo account");
    bottoni->setLayout(bot);
    f->addWidget(bottoni);

    if (nuovo) connect(ok,SIGNAL(clicked(bool)),this,SLOT(on_click_inserisci()));
    else connect(ok,SIGNAL(clicked(bool)),this,SLOT(on_click_applica()));

    f->addRow(ok);
    return f;

}
void GestioneUtenti::on_click_mod() {
    QListWidgetItem* a =listaUtenti->currentItem();
    if (a){
        modificaU=new QWidget();
        modificaU->setLayout(creaAlteraUtente(false));
        modificaU->show();

    }
    else QMessageBox::warning(0, "Errore!", "selezionare prima un utente");
}

void GestioneUtenti::on_click_applica() {
    QListWidgetItem* a=listaUtenti->currentItem();
    if (a){
        std::string ut =a->text().toStdString();
        std::string n = nome->text().toStdString();
        std::string p = pass->text().toStdString();



        try{
            db_utenti->cambiaPass(ut,p);
            if (capo->isChecked() && db_utenti->getTipo(ut)!="Capo") db_utenti->changeTipo(ut);
            if (op->isChecked() && db_utenti->getTipo(ut)!="Operaio") db_utenti->changeTipo(ut);
            db_utenti->cambiaNome(ut,n);
            listaUtenti->currentItem()->setText(QString::fromStdString(n));
            setDati(listaUtenti->currentItem());


        }
        catch (ErrNoValidIndex c){
            QMessageBox::warning(0, "Errore!", "problema nella modifica\nutente "+QString::fromStdString(ut)+" non trovato");
        }
        catch (ErrChiave c){
            QMessageBox::warning(0, "Errore!", "il nome inserito e' gia' in uso.");

        }
    }
    else QMessageBox::warning(0, "Errore!", "selezionare un utente prima");

    modificaU->close();
    delete modificaU;
    modificaU=nullptr;
}

void GestioneUtenti::on_click_add()  {
    if (modificaU) delete modificaU;
    modificaU= new QWidget();
    modificaU->setLayout(creaAlteraUtente(true));
    modificaU->show();
}
void GestioneUtenti::on_click_inserisci()  {
    std::string n= nome->text().toStdString();
    std::string p=pass->text().toStdString();
    bool c = capo->isChecked();
    Utente* ut;
    if (c) ut=new Capo(n,p);
    else ut=new Operaio(n,p);
    try{
        db_utenti->nuovoUtente(*ut);
        listaUtenti->addItem(new QListWidgetItem(QString::fromStdString( n)));
    }
    catch (ErrChiave c){
        QMessageBox::warning(0, "Errore!", "nome utente gia' presente");
    }
    delete ut;
    delete modificaU;
    modificaU=nullptr;
}
