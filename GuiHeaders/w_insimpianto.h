#ifndef W_INSIMPIANTO_H
#define W_INSIMPIANTO_H

#include <QWidget>
#include <QFormLayout>
#include <QRadioButton>
#include <QDateEdit>
#include <QPushButton>
#include "ModelloHeaders/impianto.h"


#include "ModelloHeaders/omegagpl.h"
#include "ModelloHeaders/directgpl.h"
#include "ModelloHeaders/nocatgpl.h"
#include "ModelloHeaders/maticgpl.h"
#include "w_addbombola.h"

class W_insImpianto : public QWidget
{
    Q_OBJECT
public:
    explicit W_insImpianto(QWidget *parent = nullptr);
    virtual ~W_insImpianto();
    Impianto* creaImpianto() const;
    //void ResetDatiImpianto(); //imposta a null non pulisce l'heap.
private:
    QDateEdit* IDataInstallazione;
    QRadioButton* IMaticGPL;
    QRadioButton* IDirectGPL;
    QRadioButton* INoCatGPL;
    QRadioButton* IOmegaGPL;
    QFormLayout* datiImpianto();
    W_AddBombola* aggiunta;
    Impianto* tmp;

signals:

private slots:
    void on_click_Matic();
    void on_click_Omega();
    void on_click_NoCat();
    void on_click_Direct();
    void on_click_Aggiunta();
};

#endif // W_INSIMPIANTO_H
