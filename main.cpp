#include <iostream>
#include <QApplication>
#include "GuiHeaders/gestionegui.h"

using std::cout;
using std::endl;

int main(int argc,char* argv[])
{

   QApplication app(argc, argv);

   GestioneGUI* pMan=new GestioneGUI();
   pMan->avvioGUI();


   return QApplication::exec();

}
