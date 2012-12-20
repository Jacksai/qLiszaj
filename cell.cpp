#include "cell.h"
#include <QtGui>

void Cell::reset()
{
    this->stan = ZDROWA;
    this->nextStan = ZDROWA;
}

Cell::Cell()
{
    //this->x = 0;
    //this->y = 0;
    this->stan = ZDROWA;
    this->nextStan = ZDROWA;
}
//Cell::Cell(int x, int y)
//{
//    this->x = x ;
//    this->y = y ;
//    this->stan = ZDROWA;
//    this->nextStan = ZDROWA;
//}

//void Cell::expozycja()
//{

//    bool inf = ((qrand()%100) < INFECT) ;

//    if(inf && this->stan == ZDROWA)
//    {
//        this->nextStan = CHORA ;
//    }
//}

//void Cell::nextPokolenie()
//{
//    if(!(this->stan == ZDROWA && this->nextStan == ZDROWA))
//    {
//        this->stan = (Stan)(((int)(this->getStan())+1)%6);
//        if(this->stan) this->nextStan = (Stan)(((int)(this->getStan())+1)%6);
//                else this->nextStan = ZDROWA;

//    }

//}
void Cell::setStan(Stan a)
{
    this->stan = a;
}
void Cell::setNextStan(Stan a)
{
    this->nextStan = a;
}

