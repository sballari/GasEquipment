#ifndef W_INSSCARICO_H
#define W_INSSCARICO_H
#include "w_inscomponente.h"
#include "qcheckbox.h"
#include "ModelloHeaders/scarico.h"

class W_insScarico:public W_InsComponente
{
    Q_OBJECT
public:
    W_insScarico();
    Scarico* creaScarico() const;
private:
    QCheckBox* SCatalizzatore;
    QCheckBox* SSondaLambda;
    QFormLayout* datiScarico();
};

#endif // W_INSSCARICO_H
