#ifndef W_SHOW_ALIMENTATORE_H
#define W_SHOW_ALIMENTATORE_H
#include "w_show_componente.h"
#include "ModelloHeaders/alimentatore.h"


class W_Show_Alimentatore : public W_Show_Componente
{
public:
    W_Show_Alimentatore(const Alimentatore* pA);
private:
    const Alimentatore* pAlimentatore;
    QLayout* datiSpecifici() const;
};

#endif // W_SHOW_ALIMENTATORE_H
