#include "sample.h"
#include <math.h>

TSample::TSample(int n)
{
    count=n;
}

void TSample::draw(QPainter* p, QRect r, QColor c)
{
    qreal cw = 0.5*r.width();
    qreal ch = 0.5*r.height();
    qreal cr = 0.9*(cw>ch?ch:cw);
    qreal a = 2.0*acos(-1.0)/count;
    QPointF *t = new QPointF[count];
    for (int i=0; i<count; i++)
    {
        t[i] = QPointF(100 + cw+cr*sin(i*a),ch-cr*cos(i*a));
    }
    p->setPen(QPen(Qt::black));
    p->setBrush(QBrush(c));
    p->drawPolygon(t,count);
    delete [] t;
}
