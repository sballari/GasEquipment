#ifndef W_SHOW_VEICOLO_CAPO_H
#define W_SHOW_VEICOLO_CAPO_H
#include "GuiHeaders/w_show_veicolo.h"


class W_Show_Veicolo_Capo : public W_Show_Veicolo
{
    Q_OBJECT
public:
    W_Show_Veicolo_Capo(const Officina* pO,std::string tg,GestioneGUI* pg);
private:
    void aggiungi_Modifica_dati();
    std::string targa;
private slots:
    void on_click_modifica_dati_auto();
protected:
    std::string mostra_targa() const;

};

#endif // W_SHOW_VEICOLO_CAPO_H
