#ifndef W_SHOW_IMPIANTO_H
#define W_SHOW_IMPIANTO_H

#include <QWidget>
#include "ModelloHeaders/impianto.h"
#include <qtablewidget.h>
#include "qgroupbox.h"

class W_Show_Impianto : public QWidget
{
    Q_OBJECT
public:
    W_Show_Impianto(const Impianto* pI,QWidget *parent = nullptr);
    virtual ~W_Show_Impianto() =default;
    void aggiornaLista()const;
    int bombolaSelezionata()const;
private:
    const Impianto* pImpianto;
    QTableWidget* datiBombole() const;
    QLayout* datiImpianto() const;

    QTableWidget* ptTabella;
    static void popolaTabella(QTableWidget*tab, const Impianto* pImpi);


};

#endif // W_SHOW_IMPIANTO_H
