#ifndef W_SHOW_INSTALLAZZIONE_CAPO_H
#define W_SHOW_INSTALLAZZIONE_CAPO_H
#include "GuiHeaders/w_show_veicolo_capo.h"



class W_Show_Installazzione_Capo : public W_Show_Veicolo_Capo
{
    Q_OBJECT
public:
    W_Show_Installazzione_Capo(Officina* pO, std::string tgs, GestioneGUI *pg);
private:
    Officina* pOf;
    const Installazione* pInstallazione;
    QGroupBox* creaBoxDatiImpianto() const;
    void closeEvent(QCloseEvent *event);
};

#endif // W_SHOW_INSTALLAZZIONE_CAPO_H
