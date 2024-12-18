#ifndef TCOMPLEX_H
#define TCOMPLEX_H

#include <math.h>
#include <iostream>
#include <QString>
using namespace std;

class TComplex
{
    double re, im;
public:
    TComplex();
    TComplex(const int&);
    TComplex(const double&, const double&);

    friend ostream& operator<< (ostream&, TComplex);
    friend istream& operator>> (istream&, TComplex&);
    friend QString& operator<< (QString&, TComplex);
    friend TComplex sqrt (TComplex);
    friend TComplex pow (TComplex, double);

    void operator+= (TComplex);
    TComplex operator- (TComplex);
    TComplex operator- ();
    TComplex operator/ (int);
    TComplex operator* (TComplex);

    bool operator> (TComplex);
    bool operator< (TComplex);
private:
    double count_module();
    double count_argument();
};

#endif // TCOMPLEX_H
