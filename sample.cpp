#include "sample.h"
#include <math.h>
#include <QPainterPath>

TSample::TSample(int n)
{
    count=n;
}

void TSample::draw(QPainter* p, QRect r, QColor c)
{
//    qreal cw = 0.5*r.width();
//    qreal ch = 0.5*r.height();
//    qreal cr = 0.9*(cw>ch?ch:cw);
//    qreal a = 2.0*acos(-1.0)/count;
//    QPointF *t = new QPointF[count];
//    for (int i=0; i<count; i++)
//    {
//        t[i] = QPointF(100 + cw+cr*sin(i*a),ch-cr*cos(i*a));
//    }
    p->setPen(QPen(Qt::black));
    p->setRenderHint(QPainter::Antialiasing, true);
//    p->drawPolygon(t,count);
//    delete [] t;
    QPainterPath Path(QPointF(10, 200));
    double yCoord[150];
    for(int xCoord = 2; xCoord < 152; xCoord++)
    {
        //p->drawPoint(xCoord, 300 + sin(xCoord - 100));
        yCoord[xCoord - 2] = 5 * sin(xCoord);
        Path.lineTo(QPointF(5 * xCoord, 200 + yCoord[xCoord - 2]));
    }
    p->drawPath(Path);
}
