#ifndef W_INSVEICOLO_H
#define W_INSVEICOLO_H

#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QDateEdit>
#include "ModelloHeaders/veicolo.h"
#include "w_insalimentatore.h"
#include "w_insscarico.h"
#include "w_insmotore.h"
class W_insVeicolo : public QWidget
{
    Q_OBJECT
public:
    explicit W_insVeicolo(QWidget *parent = nullptr);
private:
    QFormLayout* datiAuto();
    QHBoxLayout* datiVeicolo() ;

    //elementi veicolo
    QLineEdit* AProprietario;
    QLineEdit* ATarga;
    QDateEdit* AImmatricolazione;
    QDateEdit* AUltimaRevisione;


    W_insMotore* mot;
    W_insAlimentatore* ali;
    W_insScarico* scar;
protected:
        Veicolo* creaVeicolo() const;
        QVBoxLayout* Clay;
        QHBoxLayout* lay;

};

#endif // W_INSVEICOLO_H
