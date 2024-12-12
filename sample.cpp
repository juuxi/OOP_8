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
    p->drawLine(10, 150, 10, 250);
    p->drawLine(10, 200, 800, 200);
    p->setPen(QPen(Qt::black));
    QPainterPath Path(QPointF(10, 200));
    double yCoord[150];
    for(int xCoord = 0; xCoord < 75; xCoord++)
    {
        yCoord[xCoord] = 10 * sin(xCoord);
        Path.lineTo(QPointF(10 * xCoord + 10, 200 - yCoord[xCoord]));
    }
    p->drawPath(Path);
}
