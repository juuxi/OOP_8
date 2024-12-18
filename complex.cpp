#include "complex.h"
#include <math.h>

TComplex::TComplex()
{
    re = 0;
    im = 0;
}

TComplex::TComplex(const int& r)
{
    re = r;
    im = 0;
}

TComplex::TComplex(const double& r, const double& i)
{
    re = r;
    im = i;
}

ostream& operator<< (ostream& os, TComplex c)
{
    os << c.re << "+" << c.im << "i";
    return os;
}

istream& operator>> (istream& is, TComplex& c)
{
    is >> c.re >> c.im;
    return is;
}

QString& operator<< (QString& s, TComplex c)
{
    s += "(";
    s += QString().setNum(c.re);
    s += "+";
    s += QString().setNum(c.im);
    s += "i)";
    return s;
}

void TComplex::operator+= (TComplex c)
{
    re += c.re;
    im += c.im;
}

TComplex TComplex::operator- (TComplex c)
{
    TComplex temp;
    temp.re = re - c.re;
    temp.im = im - c.im;
    return temp;
}

TComplex TComplex::operator- ()
{
    TComplex temp;
    temp.re = -re;
    if (temp.re == -0) temp.re = 0;
    temp.im = -im;
    if (temp.im == -0) temp.im = 0;
    return temp;
}

TComplex TComplex::operator/ (int r)
{
    TComplex temp;
    temp.re = re/r;
    temp.im = im/r;
    return temp;
}

TComplex TComplex::operator* (TComplex c)
{
    TComplex temp;

    temp.re = re * c.re - im * c.im;
    if (temp.re == -0) temp.re = 0;
    temp.im = re * c.im - im * c.re;
    if (temp.im == -0) temp.im = 0;
    return temp;
}

double TComplex::count_module()
{
    return sqrt(re * re + im * im);
}

double TComplex::count_argument()
{
    return atan(im / re);
}

bool TComplex::operator> (TComplex c)
{
    if (count_module() > c.count_module())
        return true;
    if (count_module() < c.count_module())
        return false;
    if (count_argument() > c.count_argument())
        return true;
    else
        return false;
}

bool TComplex::operator< (TComplex c)
{
    if (count_module() < c.count_module())
        return true;
    if (count_module() > c.count_module())
        return false;
    if (count_argument() < c.count_argument())
        return true;
    else
        return false;
}

TComplex sqrt (TComplex c)
{
    TComplex temp;
    temp.re = sqrt(c.re);
    temp.im = sqrt(c.im);
    return temp;
}

TComplex pow (TComplex c, double d)
{
    c.re = pow(c.re, d);
    c.im = pow(c.im, d);
    return c;
}
