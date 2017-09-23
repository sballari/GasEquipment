#ifndef W_INSALIMENTATORE_H
#define W_INSALIMENTATORE_H
#include "w_inscomponente.h"
#include <QGroupBox>
#include <QRadioButton>
#include <ModelloHeaders/alimentatore.h>
#include "ModelloHeaders/iniettore.h"
#include "ModelloHeaders/carburatore.h"

class W_insAlimentatore: public W_InsComponente
{
    Q_OBJECT
public:
    W_insAlimentatore();
    Alimentatore* creaAlimentatore() const;
private:
    QFormLayout* DatiALI() ;
    QGroupBox* TipMod() ;
    //elementi // dell'alimentatore associati tutti a lay

    QGroupBox* datiIniettore;
    QRadioButton* ACarbRB;
    QRadioButton* AInietRB;
    //elementi di datiiniettore
    QRadioButton* AEletRB;
    QRadioButton* AMistoRB;
    QRadioButton* AMeccanicoRB;
    QRadioButton* ADiretto;
    QRadioButton* AIndiretto;

private slots:


    void on_click_Iniettore_RadioB();
    void on_click_Carburatore_RadioB();
};


#endif // W_INSALIMENTATORE_H
