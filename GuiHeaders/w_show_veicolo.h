#ifndef W_SHOW_VEICOLO_H
#define W_SHOW_VEICOLO_H

#include <QObject>
#include <QWidget>
#include "ModelloHeaders/veicolo.h"
#include "gestionegui.h"
#include <QGroupBox>
#include <QFormLayout>
#include "gestionegui.h"

class W_Show_Veicolo : public QWidget
{
    Q_OBJECT
public:
    W_Show_Veicolo(const Veicolo* pV,GestioneGUI* pg,QWidget *parent = 0);
    virtual ~W_Show_Veicolo()=default;
protected:
    GestioneGUI* pManager;
    QFormLayout* layerD;
private:
    const Veicolo* pVeicolo;





    QGroupBox* datiVeicolo();
    QGroupBox* datiScarico() const;
    QGroupBox* datiAlimentatore() const;
    QGroupBox* datiMotore() const;
    void closeEvent(QCloseEvent *event);

};

#endif // W_SHOW_VEICOLO_H
