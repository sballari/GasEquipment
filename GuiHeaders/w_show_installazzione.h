#ifndef W_SHOW_INSTALLAZZIONE_H
#define W_SHOW_INSTALLAZZIONE_H

#include <QObject>
#include <QWidget>
#include "w_show_veicolo.h"
#include "ModelloHeaders/installazione.h"

class W_Show_Installazzione: public W_Show_Veicolo
{
public:
    W_Show_Installazzione(const Installazione* pI, GestioneGUI* ph);

private:
    const Installazione* pInstallazione;
    QGroupBox* creaBoxDatiImpianto() const;
    void closeEvent(QCloseEvent *event);


};

#endif // W_SHOW_INSTALLAZZIONE_H
