#ifndef W_INSINSTALLAZZIONE_H
#define W_INSINSTALLAZZIONE_H
#include <GuiHeaders/w_insveicolo.h>
#include "QPushButton"
#include "ModelloHeaders/installazione.h"
#include "w_insimpianto.h"
#include "ModelloHeaders/officina.h"
#include <QErrorMessage>
#include "gestionegui.h"
class W_insInstallazzione:public W_insVeicolo
{
    Q_OBJECT
public:
    W_insInstallazzione(Officina* ,GestioneGUI* );
    ~W_insInstallazzione();
private:
    Officina* pOfficina;
    QGroupBox *creaBOX() ;
    Veicolo* crea() ;
    W_insImpianto* insti;
    GestioneGUI* pManager;


    QErrorMessage* err;
    QDateEdit* data;
    QGroupBox* datiINST;
private slots:
    void closeEvent(QCloseEvent *event);
    void inserisci();
    void on_click_VeiInst();
};

#endif // W_INSINSTALLAZZIONE_H
