#ifndef W_REGISTRA_H
#define W_REGISTRA_H
#include <QWidget>
#include <QGroupBox>
#include <QRadioButton>
#include <QLineEdit>
#include <ModelloHeaders/db_utenti.h>
#include "GuiHeaders/gestionegui.h"
#include <QLabel>

class W_Registra: public QWidget
{
    Q_OBJECT

private:
    GestioneGUI* manager;
    DB_utenti* pDBu;
    QRadioButton* cp;
    QRadioButton* dp;
    QLineEdit* nm;
    QLineEdit* ps;


    QGroupBox * tipologia();
    QGroupBox * dati();
    void closeEvent(QCloseEvent *event);


public:
    W_Registra(DB_utenti*, GestioneGUI*,QWidget* =0);
private slots:
    void registra();



};

#endif // W_REGISTRA_H
