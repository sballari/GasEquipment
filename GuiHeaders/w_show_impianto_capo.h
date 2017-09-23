#ifndef W_SHOW_IMPIANTO_CAPO_H
#define W_SHOW_IMPIANTO_CAPO_H
#include "GuiHeaders/w_show_impianto.h"
#include "ModelloHeaders/officina.h"
#include "GuiHeaders/gestionegui.h"
#include <QGroupBox>
#include <GuiHeaders/w_addbombola.h>


class W_Show_Impianto_Capo : public W_Show_Impianto
{
    Q_OBJECT
public:
    W_Show_Impianto_Capo(Officina* pO, std::string targa);
    ~W_Show_Impianto_Capo();
private:
    Officina* pOf;
    std::string tg;
    QGroupBox* creaBottoni() const;

    W_AddBombola* schermataB;
private slots:
    void on_click_elimina() const;
    void on_click_aggiungi() ;
    void on_signal_bombola_pronta();
};

#endif // W_SHOW_IMPIANTO_CAPO_H
