#ifndef GESTIONEUTENTI_H
#define GESTIONEUTENTI_H

#include <QObject>
#include <QWidget>
#include <GuiHeaders/gestionegui.h>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QFormLayout>
#include <QListWidget>
#include "w_registra.h"
#include <QLineEdit>
#include <QRadioButton>

class GestioneUtenti : public QWidget
{
    Q_OBJECT
public:
     GestioneUtenti(DB_utenti* pDB, GestioneGUI* pM,QWidget *parent = nullptr);
     ~GestioneUtenti();
private:
    GestioneGUI* pManager;
    DB_utenti* db_utenti;




    QListWidget* generaListaUtenti();
    QGroupBox* generaDatiUtenti() ;
    void closeEvent(QCloseEvent *event);
    QFormLayout* creaAlteraUtente(bool nuovo);
    QFormLayout* creaFormDati();


    //elementi di modifica
    QLineEdit* nome;
    QLineEdit* pass;
    QRadioButton* capo;
    QRadioButton* op;
    //____________________
    QListWidget* listaUtenti;
    QWidget* modificaU;

    QLabel* nomeL;
    QLabel* passL;
    QLabel* tipoL;

private slots:
    void setDati(QListWidgetItem *a);
    void on_click_el()const;
    void on_click_mod();
    void on_click_applica();
    void on_click_add();
    void on_click_inserisci() ;

};

#endif // GESTIONEUTENTI_H
