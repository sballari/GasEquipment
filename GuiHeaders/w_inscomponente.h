#ifndef W_INSCOMPONENTE_H
#define W_INSCOMPONENTE_H
#include <qformlayout.h>
#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>
#include "ModelloHeaders/componente.h"

#include <QWidget>

class W_InsComponente : public QWidget
{
    Q_OBJECT
public:
    explicit W_InsComponente(QWidget *parent = nullptr);
    virtual ~W_InsComponente()=default;
private:
    QFormLayout* creaForm() ;
    Componente* creaComponente() const;
    QDateEdit* dt;
    QLineEdit* prd;
protected:
    std::string daiNomeProd() const;
    Data daiDataProd() const;
    QVBoxLayout* Clay;


};

#endif // W_INSCOMPONENTE_H
