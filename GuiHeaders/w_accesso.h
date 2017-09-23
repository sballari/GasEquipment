#ifndef W_ACCESSO_H
#define W_ACCESSO_H
#include <QWidget>
#include "ModelloHeaders/db_utenti.h"
#include <QGroupBox>
#include "GuiHeaders/gestionegui.h"
#include "qlineedit.h"
#include "qlabel.h"


class W_accesso: public QWidget
{
    Q_OBJECT

public:
    W_accesso(DB_utenti*, GestioneGUI* pM, QWidget* =nullptr);
private:

    DB_utenti* db;
    GestioneGUI* pManager;


    //elementi associta a lay
    QLineEdit* user;
    QLineEdit* key;


    //funzioni
    QGroupBox* principale();
private slots:

    void ProvaLogin()const;
};

#endif // W_ACCESSO_H
