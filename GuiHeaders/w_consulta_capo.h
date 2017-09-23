#ifndef W_CONSULTA_CAPO_H
#define W_CONSULTA_CAPO_H
#include "GuiHeaders/w_consulta.h"


class W_Consulta_Capo : public W_Consulta
{
    Q_OBJECT
public:
    W_Consulta_Capo( Officina* p, GestioneGUI* pm);

private slots:
    void on_click_cancella();
private:
    Officina* pOfficina;
    void aggiungi_elimina();
private slots:
    void on_click_mostra();

};

#endif // W_CONSULTA_CAPO_H
