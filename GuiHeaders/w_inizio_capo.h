#ifndef W_INIZIO_CAPO_H
#define W_INIZIO_CAPO_H
#include "w_inizio.h"
#include "gestionegui.h"

class W_Inizio_Capo : public W_Inizio
{
    Q_OBJECT
public:
    W_Inizio_Capo(GestioneGUI* pM, QWidget* =nullptr);

private slots:
    void on_click_Inserisci() const;
    void on_click_gestioneU()const;
    void on_consulta()const;
};

#endif // W_INIZIO_CAPO_H
