#ifndef W_ADDBOMBOLA_H
#define W_ADDBOMBOLA_H
#include <QWidget>
#include "ModelloHeaders/impianto.h"
#include <QGroupBox>
#include <QLineEdit>
#include <QDateEdit>
#include <QSpinBox>
#include <QPushButton>

class W_AddBombola: public QWidget
{
    Q_OBJECT
private:
    Impianto* imp;
    QGroupBox* datiBomb();
    bool no_inserimento;

    //elementi da lay
    QLineEdit* AProduttore;
    QDateEdit* ADataProd ;
    QDoubleSpinBox* ACapacita;
    QDateEdit* AUltimaRevisione;
    QPushButton* AAggiungiButton;



public:
    W_AddBombola(Impianto*, QWidget* =nullptr, bool noIns=false);
    Bombola* crea_bombola() const;
private slots:
    void on_click_add() ;
    void bombola_pronta();
signals:
    void bombolaReady();

};

#endif // W_ADDBOMBOLA_H
