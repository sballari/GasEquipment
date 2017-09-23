#ifndef W_SHOW_CARBURATORE_H
#define W_SHOW_CARBURATORE_H


#include "ModelloHeaders/carburatore.h"
#include <QGroupBox>
#include "w_show_componente.h"
#include "w_show_alimentatore.h"

class W_Show_Carburatore:public W_Show_Alimentatore
{
    Q_OBJECT
public:
    W_Show_Carburatore(const Carburatore* pC);
private:
    const Carburatore* pCarburatore;
    QLayout* datiSpecifici() const;
};

#endif // W_SHOW_CARBURATORE_H
