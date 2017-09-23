QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = GasEquipment




TEMPLATE = app
CONFIG += c++11
CONFIG -= app_bundle
CONFIG += qt
QMAKE_CXXFLAGS += -std=c++11


SOURCES += main.cpp \
    ModelloImplementations/data.cpp \
    ModelloImplementations/motore.cpp \
    ModelloImplementations/iniettore.cpp \
    ModelloImplementations/componente.cpp \
    ModelloImplementations/alimentatore.cpp \
    ModelloImplementations/scarico.cpp \
    ModelloImplementations/carburatore.cpp \
    ModelloImplementations/veicolo.cpp \
    ModelloImplementations/impianto.cpp \
    ModelloImplementations/bombola.cpp \
    ModelloImplementations/impiantogpl.cpp \
    ModelloImplementations/omegagpl.cpp \
    ModelloImplementations/nocatgpl.cpp \
    ModelloImplementations/maticgpl.cpp \
    ModelloImplementations/directgpl.cpp \
    ModelloImplementations/installazione.cpp \
    ModelloImplementations/officina.cpp \
    ModelloImplementations/utente.cpp \
    ModelloImplementations/capo.cpp \
    ModelloImplementations/db_utenti.cpp \
    GuiImplementations/w_accesso.cpp \
    ModelloImplementations/operaio.cpp \
    GuiImplementations/w_addbombola.cpp \
    GuiImplementations/w_inizio.cpp \
    GuiImplementations/w_consulta.cpp \
    ModelloImplementations/err.cpp \
    ModelloImplementations/funzioni.cpp \
    ModelloImplementations/errnoiniettore.cpp \
    ModelloImplementations/errnovalidindex.cpp \
    ModelloImplementations/errchiave.cpp \
    GuiImplementations/gestionegui.cpp \
    GuiImplementations/w_inizio_capo.cpp \
    GuiImplementations/w_show_componente.cpp \
    GuiImplementations/w_show_scarico.cpp \
    GuiImplementations/w_show_iniettore.cpp \
    GuiImplementations/w_show_motore.cpp \
    GuiImplementations/w_show_alimentatore.cpp \
    GuiImplementations/w_show_veicolo.cpp \
    GuiImplementations/w_show_carburatore.cpp \
    GuiImplementations/w_show_installazzione.cpp \
    GuiImplementations/w_show_impianto.cpp \
    GuiImplementations/w_inscomponente.cpp \
    GuiImplementations/w_insalimentatore.cpp \
    GuiImplementations/w_insscarico.cpp \
    GuiImplementations/w_insmotore.cpp \
    GuiImplementations/w_alter_veicolo.cpp \
    GuiImplementations/w_insveicolo.cpp \
    GuiImplementations/w_insinstallazzione.cpp \
    GuiImplementations/w_insimpianto.cpp \
    GuiImplementations/gestioneutenti.cpp \
    ModelloImplementations/errxml.cpp \
    GuiImplementations/w_consulta_capo.cpp \
    GuiImplementations/w_show_veicolo_capo.cpp \
    GuiImplementations/w_show_installazzione_capo.cpp \
    GuiImplementations/w_show_impianto_capo.cpp

HEADERS += ModelloHeaders/data.h \
    ModelloHeaders/motore.h \
    ModelloHeaders/iniettore.h \
    ModelloHeaders/componente.h \
    ModelloHeaders/alimentatore.h \
    ModelloHeaders/scarico.h \
    ModelloHeaders/carburatore.h \
    ModelloHeaders/veicolo.h \
    GuiHeaders/w_alter_veicolo.h \
    ModelloHeaders/impianto.h \
    ModelloHeaders/bombola.h \
    ModelloHeaders/impiantogpl.h \
    ModelloHeaders/omegagpl.h \
    ModelloHeaders/nocatgpl.h \
    ModelloHeaders/maticgpl.h \
    ModelloHeaders/directgpl.h \
    ModelloHeaders/installazione.h \
    ModelloHeaders/officina.h \
    ModelloHeaders/utente.h \
    ModelloHeaders/capo.h \
    ModelloHeaders/db_utenti.h \
    GuiHeaders/w_accesso.h \
    ModelloHeaders/operaio.h \
    GuiHeaders/w_addbombola.h \
    GuiHeaders/w_inizio.h \
    GuiHeaders/w_consulta.h \
    ModelloHeaders/err.h \
    ModelloHeaders/funzioni.h \
    ModelloHeaders/errnoiniettore.h \
    ModelloHeaders/errnovalidindex.h \
    ModelloHeaders/errchiave.h \
    GuiHeaders/gestionegui.h \
    GuiHeaders/w_inizio_capo.h \
    GuiHeaders/w_show_componente.h \
    GuiHeaders/w_show_scarico.h \
    GuiHeaders/w_show_iniettore.h \
    GuiHeaders/w_show_motore.h \
    GuiHeaders/w_show_alimentatore.h \
    GuiHeaders/w_show_veicolo.h \
    GuiHeaders/w_show_carburatore.h \
    GuiHeaders/w_show_installazzione.h \
    GuiHeaders/w_show_impianto.h \
    GuiHeaders/w_inscomponente.h \
    GuiHeaders/w_insalimentatore.h \
    GuiHeaders/w_insscarico.h \
    GuiHeaders/w_insmotore.h \
    GuiHeaders/w_insveicolo.h \
    GuiHeaders/w_insinstallazzione.h \
    GuiHeaders/w_insimpianto.h \
    GuiHeaders/gestioneutenti.h \
    ModelloHeaders/errxml.h \
    GuiHeaders/w_consulta_capo.h \
    GuiHeaders/w_show_veicolo_capo.h \
    GuiHeaders/w_show_installazzione_capo.h \
    GuiHeaders/w_show_impianto_capo.h
