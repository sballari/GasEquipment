#ifndef W_ALTER_VEICOLO_H
#define W_ALTER_VEICOLO_H

#include <QFormLayout>
#include "ModelloHeaders/officina.h"
#include <QWidget>
#include "ModelloHeaders/veicolo.h"
#include <qlineedit.h>
#include <QDateEdit>
#include "GuiHeaders/gestionegui.h"
class W_alter_veicolo : public QWidget
{
    Q_OBJECT
public:
    explicit W_alter_veicolo(Officina* Pof, std::string targa ,GestioneGUI* p,QWidget *parent = nullptr);
private:
    Officina* pO;
    std::string targa;
    GestioneGUI* pman;

    QFormLayout* creaForm() ;
    QLineEdit* AProprietario;
    QLineEdit* ATarga;
    QDateEdit* AImmatricolazione;
    QDateEdit* AUltimaRevisione;

    void closeEvent(QCloseEvent *event);
private slots:
    void on_click_applica();
signals:
    void targa_alterata(std::string nuova_targa);


};

#endif // W_ALTER_VEICOLO_H
