#include "GuiHeaders/w_accesso.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QApplication>
#include <QLineEdit>
#include <QMessageBox>

W_accesso::W_accesso(DB_utenti* nomi, GestioneGUI* Pmanager, QWidget* parent):
    QWidget(parent), db(nomi), pManager(Pmanager)
{
    setWindowTitle("SCHERMATA DI ACCESSO");
    QVBoxLayout* box = new QVBoxLayout();
    box->addWidget(principale());
    setLayout(box);
}


QGroupBox* W_accesso::principale(){

    QGroupBox* box = new QGroupBox(nullptr);

    QPushButton* accedi = new QPushButton("Accedi");
    accedi->setAutoDefault(true);


    QLabel* askNome = new QLabel("Nome Utente");
    user = new QLineEdit();

    QLabel* askPass = new QLabel("Passworld");


    key = new QLineEdit();

    key->setEchoMode(QLineEdit::EchoMode::Password);


    QVBoxLayout* schema = new QVBoxLayout();


    schema->addWidget(askNome);
    schema->addWidget(user);
    schema->addWidget(askPass);
    schema->addWidget(key);
    schema->addWidget(accedi);




    box->setLayout(schema);


    connect(accedi, SIGNAL(clicked()), this, SLOT(ProvaLogin()));
    return box;
}



void W_accesso::ProvaLogin() const {
    std::string nome = (user->text()).toStdString();
    std::string pass = (key->text()).toStdString();
    const Utente* log = db->verifica(nome, pass);
    if (log) pManager->LoginEffettuato(log);
    else {
         QMessageBox::warning(0, "Errore!", "autenticazione fallita");
    }
}

