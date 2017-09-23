#ifndef W_CONSULTA_H
#define W_CONSULTA_H
#include <QWidget>
#include <ModelloHeaders/officina.h>
#include <QGroupBox>
#include <QPushButton>
#include <QLabel>
#include <QPointer>
#include <QScrollArea>
#include <QGridLayout>

#include <qlistwidget.h>
#include <QTextEdit>
#include <QLineEdit>
#include "gestionegui.h"
#include <QErrorMessage>
#include <QCheckBox>
#include <QFormLayout>

class W_Consulta: public QWidget
{
    Q_OBJECT
public:

    W_Consulta(const Officina* p, GestioneGUI* pm, QWidget* parent=nullptr);
    virtual ~W_Consulta();

private:
    const Officina* pOff;




    void closeEvent(QCloseEvent *event);
    //funz di creazione
    QTextEdit* creaInfo(const Veicolo &INST) const;
    QHBoxLayout* Lista_Bottoni() ;
    QListWidget* listaInstallazioni()const;
    QFormLayout* datiRicerca() ;



    //elementi


    QTextEdit* Info;
    QCheckBox* alert;
    QLineEdit* prop;
protected:
    GestioneGUI* pManager;
    QListWidget* lista;
    QErrorMessage* err;
    QVBoxLayout* bottoni;
private slots:

    void on_click_info(QListWidgetItem *item);
    virtual void on_click_mostra() ;
    void on_alterazione_targa(std::string nuova_t);
    void on_click_filtra();

};

#endif // W_CONSULTA_H
