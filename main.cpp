#include <QApplication>
#include <QtGui>
#include <QTime>
#include"plansza.h"
#include "oknoglowne.h"
#include <QDebug>

int main(int argc, char * argv[])
{
    //Inicjalizacja aplikacji
    QApplication a(argc,argv);
    //Inicjaliza siarna dla funkcji generującej losowe liczby
    QTime time =QTime::currentTime();
    qsrand((uint)time.msec());
    Plansza *c = new Plansza();
    c->show();
//    OknoGlowne * okienko ;
//    okienko = new OknoGlowne();
//    okienko->show();

    return a.exec() ;
}

