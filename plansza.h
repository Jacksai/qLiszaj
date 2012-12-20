#ifndef PLANSZA_H
#define PLANSZA_H
#include "cell.h"
#include <QWidget>

const int SIZE =1000 ;
const int WIDTH = 1 ;


class Plansza : public QWidget
{
    Q_OBJECT
public:
    QTimer * timere ;
    explicit Plansza(QWidget *parent = 0);
    bool rysowac;
    QPoint *  punkt;
    QList<QList <Cell> > PUNKTY;
    QList<QPoint> punkciki ;
    bool animacja;
    void resetuj();
signals:

public slots:
    /////////////////////////////
    void zerowy();
    void setIks(int x);
    void setIgrek(int y);
    ////////////////////////////
    void Akcja(int x,int y);
    void Rozwoj();
    void Animacja();
private:
    void keyPressEvent(QKeyEvent *);
    void paintEvent(QPaintEvent *); // event rysowania
    void mousePressEvent(QMouseEvent *event);

};

#endif // PLANSZA_H
