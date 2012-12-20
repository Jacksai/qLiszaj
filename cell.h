
#ifndef CELL_H
#define CELL_H

#include <QApplication>
#include<QtGlobal>
//#include <QPoint>

const int INFECT = 25 ;

enum Stan
{
    ZDROWA,CHORA,ODP1,ODP2,ODP3,ODP4
};

class Cell
{


private:
   // int x;
    //int y;
    Stan stan;
    Stan nextStan;


public:
    Cell();
    Cell(int x,int y);
   // void setX(int x){this->x = x;}
   // void setY(int y){this->y = y;}
    void reset();
   void expozycja()
   {

       bool inf = ((qrand()%100) < INFECT) ;

       if(inf && this->stan == ZDROWA)
       {
           this->nextStan = CHORA ;
       }
   }
   void nextPokolenie()
{
   if(!(this->stan == ZDROWA && this->nextStan == ZDROWA))
   {
       this->stan = (Stan)(((int)(this->getStan())+1)%6);
       if(this->stan) this->nextStan = (Stan)(((int)(this->getStan())+1)%6);
               else this->nextStan = ZDROWA;

   }
}
    void setStan(Stan);
    void setNextStan(Stan);
    Stan getStan(){return this->stan;}
    Stan getNextStan(){return this->nextStan;}
};

#endif // CELL_H
