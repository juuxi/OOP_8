#ifndef TSAMPLE_H
#define TSAMPLE_H

#include <QPainter>

class TSample
{
    int count;
public:
    TSample(int);
    void draw(QPainter*,QRect,QColor);
};

#endif // TSAMPLE_H