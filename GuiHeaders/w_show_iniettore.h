#ifndef W_SHOW_INIETTORE_H
#define W_SHOW_INIETTORE_H

#include <QObject>
#include <QWidget>
#include "ModelloHeaders/iniettore.h"
#include <QGroupBox>
#include "w_show_componente.h"
#include "w_show_alimentatore.h"

class W_Show_Iniettore : public W_Show_Alimentatore
{
    Q_OBJECT
public:
    W_Show_Iniettore(const Iniettore* pI);

private:
    const Iniettore* pIniettore;
    QLayout* datiSpecifici() const;
};

#endif // W_SHOW_INIETTORE_H


