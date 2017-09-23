#ifndef W_INIZIO_H
#define W_INIZIO_H
#include <ModelloHeaders/officina.h>
#include "w_accesso.h"
#include <QWidget>
#include <QGroupBox>
#include "ModelloHeaders/db_utenti.h"
#include "w_consulta.h"



class W_Inizio: public QWidget
{
    Q_OBJECT
private:
    QGroupBox* Operazioni();
protected:
    QVBoxLayout* lay;
    GestioneGUI* pManager;

private slots:
    void on_cambia()const;
    virtual void on_consulta()const;
    void closeEvent(QCloseEvent *event);

public:
    W_Inizio(GestioneGUI *pm, QWidget* =nullptr);
    virtual ~W_Inizio()=default;


};

#endif // W_INIZIO_H
