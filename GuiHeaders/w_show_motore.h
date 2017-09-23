#ifndef W_SHOW_MOTORE_H
#define W_SHOW_MOTORE_H
#include "ModelloHeaders/motore.h"
#include "w_show_componente.h"

class W_show_Motore: public W_Show_Componente
{
public:
    W_show_Motore(const Motore* pM);
private:
    const Motore* pMotore;
    QLayout* datiSpecifici() const;

};

#endif // W_SHOW_MOTORE_H
