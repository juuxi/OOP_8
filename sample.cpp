#include "sample.h"
#include <math.h>
#include <QPainterPath>

TSample::TSample(int n)
{
    count=n;
}

void TSample::draw_sin(QPainter* p, QRect r, QColor c)
{
    p->setPen(QPen(Qt::darkRed));
    p->setRenderHint(QPainter::Antialiasing, true);
    p->drawLine(260, 150, 260, 250);
    p->drawLine(10, 200, 530, 200);
    p->setPen(QPen(Qt::black));
    QPainterPath Path(QPointF(10, 200));
    double yCoord[150];
    for(int xCoord = 0; xCoord < 50; xCoord++)
    {
        yCoord[xCoord] = 10 * sin(xCoord - 25);
        Path.lineTo(QPointF(10 * xCoord + 10, 200 - yCoord[xCoord]));
    }
    p->drawPath(Path);
}

void TSample::draw_integral_sin(QPainter* p, QRect r, QColor c)
{
    p->setPen(QPen(Qt::darkRed));
    p->setRenderHint(QPainter::Antialiasing, true);
    p->drawLine(300, 150, 300, 250);
    p->drawLine(10, 200, 600, 200);
    p->setPen(QPen(Qt::black));
    QPainterPath Path(QPointF(150, 200));
    double yCoord[400];
    int i = 0;
    for(double xCoord = 0; xCoord < 20; xCoord += 0.1, i++)
    {
        yCoord[i] = 60 * sin(xCoord - 10)/(xCoord - 10);
        Path.lineTo(QPointF(15 * xCoord + 150, 200 - yCoord[i]));
    }
    p->drawPath(Path);
}
