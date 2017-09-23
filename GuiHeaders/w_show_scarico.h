#ifndef W_SHOW_SCARICO_H
#define W_SHOW_SCARICO_H

#include <QObject>
#include <QWidget>
#include "ModelloHeaders/scarico.h"
#include "qformlayout.h"
#include "w_show_componente.h"
#include "qgroupbox.h"

class W_Show_Scarico : public W_Show_Componente
{
    Q_OBJECT
public:
    W_Show_Scarico(const Scarico* pS);


private:
    const Scarico* pScarico;
    QLayout* datiSpecifici() const;

};

#endif // W_SHOW_SCARICO_H
