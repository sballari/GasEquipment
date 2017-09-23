#include "GuiHeaders/w_show_impianto.h"
#include "ModelloHeaders/funzioni.h"
#include "QFormLayout"
#include <QLabel>
#include <QString>
W_Show_Impianto::W_Show_Impianto(const Impianto* pI, QWidget *parent) : QWidget(parent), pImpianto(pI)
{
    QVBoxLayout* lay = new QVBoxLayout();
    setLayout(lay);
    lay->addLayout(datiImpianto());
    ptTabella=datiBombole();
    lay->addWidget(ptTabella);
    aggiornaLista();



}

void W_Show_Impianto::aggiornaLista() const{
    ptTabella->clear();
    ptTabella->setRowCount(pImpianto->nBombole());
    popolaTabella(ptTabella,pImpianto);

}

QLayout* W_Show_Impianto::datiImpianto() const{

    QFormLayout* lay = new QFormLayout();
    QLabel* Nome = new QLabel(QString::fromStdString(pImpianto->getNome()));
    QLabel * cap = new QLabel(QString::fromStdString(ToString(pImpianto->capacita_impianto())));
    QLabel* nB=new QLabel(QString::fromStdString(ToString(pImpianto->nBombole())));
    lay->addRow("modello impianto:", Nome);
    lay->addRow("capacita' totale:", cap);
    lay->addRow("numero bombole:", nB);
    return lay;
}

void W_Show_Impianto::popolaTabella(QTableWidget* tab,const Impianto* pImpi){
    QStringList a;
    a.push_back("n");
    a.push_back("capacita'");
    a.push_back("produttore");
    a.push_back("data produzione");
    a.push_back("ultima revisione");
    tab->setHorizontalHeaderLabels(a);
    for (unsigned int i=0; i<pImpi->nBombole(); i++){

        QString a1 = QString::fromStdString(ToString((*pImpi)[i].getCapacita()));
        QString a2 = QString::fromStdString((*pImpi)[i].getNomeProduttore());
        QString a3 = (*pImpi)[i].getDataProduzione();
        QString a4 = (*pImpi)[i].getUltimaRev();

        std::string INDICE = ToString(i);
        QTableWidgetItem* I = new QTableWidgetItem(QString::fromStdString(INDICE));
        QTableWidgetItem* A = new QTableWidgetItem(a1);
        QTableWidgetItem* B = new QTableWidgetItem(a2);
        QTableWidgetItem* C = new QTableWidgetItem(a3);
        QTableWidgetItem* D = new QTableWidgetItem(a4);

        I->setFlags(I->flags() ^ Qt::ItemIsEditable);
        A->setFlags(A->flags() ^ Qt::ItemIsEditable);
        B->setFlags(B->flags() ^ Qt::ItemIsEditable);
        C->setFlags(C->flags() ^ Qt::ItemIsEditable);
        D->setFlags(D->flags() ^ Qt::ItemIsEditable);


        tab->setItem(i,0,I);
        tab->setItem(i,1,A);
        tab->setItem(i,2,B);
        tab->setItem(i,3,C);
        tab->setItem(i,4,D);




    }
}
int W_Show_Impianto::bombolaSelezionata()const{
    if (ptTabella->currentRow()>=0){
        int riga =ptTabella->currentRow();
        QTableWidgetItem* cellaIndice =ptTabella->item(riga,0);
        return cellaIndice->text().toInt();
    }
    else return -1;
}
QTableWidget* W_Show_Impianto::datiBombole() const {
    QTableWidget* Tabella = new QTableWidget(pImpianto->nBombole(),5, nullptr);
    popolaTabella(Tabella,pImpianto);
    return Tabella;

}

