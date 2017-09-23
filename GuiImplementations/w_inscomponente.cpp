#include "GuiHeaders/w_inscomponente.h"
#include "ModelloHeaders/data.h"

W_InsComponente::W_InsComponente(QWidget *parent) : QWidget(parent)
{
        Clay= new QVBoxLayout();
        setLayout(Clay);
        Clay->addLayout(creaForm());
}
QFormLayout* W_InsComponente::creaForm(){

    QFormLayout* lay = new QFormLayout;
    QLineEdit* produttore = new QLineEdit;
    QDateEdit* dataProd = new QDateEdit;
    prd=produttore;
    dt=dataProd;
    lay->addRow("Produttore: ",produttore);
    lay->addRow("data di produzione: ",dataProd);



    return lay;
}

std::string W_InsComponente:: daiNomeProd() const{
    return prd->text().toStdString();
}
Data W_InsComponente::daiDataProd() const{
    return dt->date();
}
