#ifndef W_INSMOTORE_H
#define W_INSMOTORE_H
#include "w_inscomponente.h"
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QCheckBox>
#include "ModelloHeaders/motore.h"

class W_insMotore:public W_InsComponente
{
    Q_OBJECT
public:
    W_insMotore();
    Motore* creaMotore () const;

private:

    QFormLayout* datiMotore();
    QSpinBox* MNcil;
    QSpinBox* MCilindrata; //cilindrata e' discreto
    QDoubleSpinBox* MCopMax;
    QDoubleSpinBox* MRappCompr;
    QCheckBox* MTurbo;
};

#endif // W_INSMOTORE_H
