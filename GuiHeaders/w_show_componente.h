#ifndef W_SHOW_COMPONENTE_H
#define W_SHOW_COMPONENTE_H

#include <QObject>
#include <QWidget>
#include "ModelloHeaders/officina.h"
#include <QGroupBox>
#include <QFormLayout>

class W_Show_Componente:public QWidget
{
    Q_OBJECT
public:
    W_Show_Componente(const Componente* pC, QWidget* parent =0);
    virtual ~W_Show_Componente()=default;
private:
    const Componente* pComponente;
    QLayout *creaMain() const;
protected:
    QVBoxLayout* layComp;


};

#endif // W_SHOW_COMPONENTE_H
