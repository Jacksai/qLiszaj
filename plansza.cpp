#include <QPainter>
#include <QPen>
#include <QTimer>
#include <QMouseEvent>
#include "plansza.h"
#include <QDebug>






Plansza::Plansza(QWidget *parent) :
    QWidget(parent)
{
    timere = new QTimer(this);
    timere->setInterval(50);
    animacja = false;


    //Okno ma być dokładnie takich rozmiarów
    this->setMinimumWidth(SIZE  * WIDTH + 20);
    this->setMinimumHeight(SIZE * WIDTH + 20);
    this->setMaximumHeight(SIZE * WIDTH + 20);
    this->setMaximumWidth(SIZE  * WIDTH + 20);
    rysowac = true ;

    for(int i = 0 ; i < SIZE ; i++)
    {
        QList<Cell> temp ;
        for(int j = 0 ; j < SIZE ; j++)
        {
            temp.append(Cell());
        }
        PUNKTY.append(temp);
    }
    connect(timere,SIGNAL(timeout()),this,SLOT(Rozwoj()));

    //SESJA DEBUGOWANA
    qDebug() << sizeof(Cell);
    qDebug() << sizeof(int);
    qDebug() << "Sizeof Plansza = " << sizeof(Plansza);

}

void Plansza::resetuj()
{
    for(int i = 0 ; i < SIZE ;i++)
    {
        for(int j = 0 ; j < SIZE ;j++)
        {
            PUNKTY[i][j].reset();
        }
    }

    rysowac = true;
    update();
}

void Plansza::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QColor kolor(0,0,0);
    painter.setPen(QPen(kolor));

    //painter.drawRect(20,20,20,20);
   //INICJALIZAJA PLANSZY
    /*
    for(int i = 10 ; i < SIZE*WIDTH+10 ; i=i+WIDTH)
    {
        for(int j = 10 ; j < SIZE*WIDTH+10 ; j = j+WIDTH)
        {
            painter.drawRect(i,j,WIDTH,WIDTH);
        }
    }
    */
    // Obsługa innych głupich zdarzeń

    if(rysowac)
    {

        QColor kol(0,255,0);
        QColor red(255,0,0);
        QColor green(255,255,190);
        QColor blue(0,0,255);
        QColor grey1(30,30,30);
        QColor grey2(70,70,70);
        QColor grey3(110,110,110);
        QColor grey4(150,150,150);
        painter.setPen(QPen(kol));

        for(int i = 0 ; i < SIZE ; i++)
        {
            for(int j = 0 ; j < SIZE ; j++)
            {
                switch(PUNKTY[i][j].getStan())
                {
                case ZDROWA:
                    painter.setPen(QPen(green));
                    break;
                case CHORA:
                    painter.setPen(QPen(red));
                    break;
                case ODP1:
                    painter.setPen(QPen(grey1));
                    break;
                case ODP2:
                    painter.setPen(QPen(grey2));
                    break;
                case ODP3:
                    painter.setPen(QPen(grey3));
                    break;
                case ODP4:
                    painter.setPen(QPen(grey4));
                    break;

                }
//                painter.fillRect(11+i*WIDTH,11+j*WIDTH,WIDTH-1,WIDTH-1,QBrush(painter.pen().color()));
                 painter.fillRect(11+i*WIDTH,11+j*WIDTH,WIDTH,WIDTH,QBrush(painter.pen().color()));

            }
        }

        rysowac = false;
    }

}

///////////////////////////////
void Plansza::zerowy()
{
    punkciki.append(*punkt);
    rysowac = true ;
    update();
}
void  Plansza::setIks(int x)
{
    punkt->setX(x);
}
void Plansza::setIgrek(int y)
{
    punkt->setY(y);
}
////////////////////////////////////////
void Plansza::Akcja(int x, int y)
{
    punkt->setX(x);
    punkt->setY(y);
    punkciki.append(*punkt);
    PUNKTY[x][y].setStan(CHORA);
    PUNKTY[x][y].setNextStan(ODP1);
    rysowac = true ;
    update();

}


void Plansza::Rozwoj()
{
    // Najpierw ekspozycje :)
    for(int x = 0 ; x < SIZE ; x++)
    {
        for(int y = 0 ; y < SIZE ; y++)
        {
            if(PUNKTY[x][y].getStan()==CHORA)
            {
                for(int i = -1 ; i < 2 ; i++)
                {
                    for (int j = -1 ; j < 2 ; j++)
                    {
                        if((x+i)<SIZE && (x+i)>=0 && (y+j)<SIZE && (y+j)>=0 )
                        {
                            PUNKTY[x+i][y+j].expozycja();
                        }
                    }
                }
            }
        }
    }

    // Teraz przechodzenie do następnego stanu
    for(int x = 0 ; x < SIZE ; x++)
    {
        for(int y = 0 ; y < SIZE ; y++)
        {
            PUNKTY[x][y].nextPokolenie();
        }
    }
    this->rysowac = true;
    update();


}

void Plansza::mousePressEvent(QMouseEvent *event)
{
    if(event->x() > 10 && event->x() < SIZE*WIDTH+10 && event->y() > 10 and event->y() < SIZE*WIDTH+10 )
    {
        int x = (event->x()- 10) / WIDTH  ;
        int y = (event->y()-10) / WIDTH  ;
        // PUNKTY[x][y].setStan((Stan)((int)PUNKTY[x][y].getStan()+1 %6));
        //PUNKTY[x][y].setNextStan((Stan)((int)(PUNKTY[x][y].getStan())+1 %6));
        PUNKTY[x][y].setNextStan((Stan)((int)(PUNKTY[x][y].getStan())+1 %6));
        PUNKTY[x][y].nextPokolenie();
        rysowac=true;
        update();
    }

}

void Plansza::Animacja()
{
    animacja = !animacja;
    if(! timere->isActive()) timere->start() ;
    else timere->stop();
}
void Plansza::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Space)
    {
        this->Animacja();
    }
    if(e->key() == Qt::Key_Shift)
    {
        for(int i = 0 ; i < SIZE ;i++)
        {
            for(int j = 0 ; j < SIZE ;j++)
            {
                PUNKTY[i][j].reset();
            }
        }

        rysowac = true;
        update();
    }
    if(e->key() == Qt::Key_Control)
    {
        this->Rozwoj();
    }


}
