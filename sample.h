#ifndef TSAMPLE_H
#define TSAMPLE_H

#include <QPainter>

class TSample
{
    int count;
public:
    TSample(int);
    void draw_sin(QPainter*, double, double);
    void draw_integral_sin(QPainter*, double, double);
};

#endif // TSAMPLE_H
