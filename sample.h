#ifndef TSAMPLE_H
#define TSAMPLE_H

#include <QPainter>

class TSample
{
    int count;
public:
    TSample(int);
    void draw_sin(QPainter*,QRect,QColor);
    void draw_integral_sin(QPainter*,QRect,QColor);
};

#endif // TSAMPLE_H
