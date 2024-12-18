#ifndef TFSIN_H
#define TFSIN_H

#include "function.h"
#include <math.h>

template <class number>
class TFsin : public TFunction<number>
{
    number* der_value;
    number* count_der(int& n)
    {
        der_value = new number[n+1];
        n++;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
                der_value[i] = sin(0);
            else if (i % 4 == 1)
                der_value[i] = cos(0);
            else if (i % 4 == 3)
                der_value[i] = -cos(0);
        }
        return der_value;
    }
public:
    TFsin(int n) : TFunction<number> (n, count_der(n)) {};
    void draw(QPainter*, double, double);
    ~TFsin() {delete [] der_value;}
};

template <class number>
void TFsin<number>::draw(QPainter* p, double start, double end)
{
    const double double_NULL = -1000.1;
    const int START_X = 10;
    const int MID_Y = 200;
    const int END_X = 510;
    const int MID_X = (START_X + END_X) / 2;
    const int MULTIPLIER = 10;
    const int WIDTH = 25;
    if (start == double_NULL)
        start = 0;
    else
        start += WIDTH;

    if (end == double_NULL)
        end = 2 * WIDTH;
    else
        end += WIDTH + 1;
    p->setPen(QPen(Qt::darkRed));
    p->setRenderHint(QPainter::Antialiasing, true);
    p->drawLine(MID_X, MID_Y - 2 * WIDTH, MID_X, MID_Y + 2 * WIDTH);
    p->drawLine(START_X, MID_Y, END_X, MID_Y);
    p->setPen(QPen(Qt::black));

    p->drawLine(MID_X-3, MID_Y - MULTIPLIER, MID_X+3, MID_Y - MULTIPLIER);
    p->drawLine(MID_X-3, MID_Y + MULTIPLIER, MID_X+3, MID_Y + MULTIPLIER);
    p->drawText(QPointF(MID_X + 1, MID_Y - MULTIPLIER), "1");
    p->drawText(QPointF(MID_X + 1, MID_Y + MULTIPLIER), "-1");

    p->drawLine(MID_X - 5 * MULTIPLIER, MID_Y - 3, MID_X - 5 * MULTIPLIER, MID_Y + 3);
    p->drawLine(MID_X + 5 * MULTIPLIER, MID_Y - 3, MID_X + 5 * MULTIPLIER, MID_Y + 3);
    p->drawText(QPointF(MID_X + 5 * MULTIPLIER, MID_Y + 1), "5");
    p->drawText(QPointF(MID_X - 5 * MULTIPLIER, MID_Y + 1), "-5");

    QPainterPath Path(QPointF(MULTIPLIER * (start + 1), MID_Y));
    double yCoord[100];
    int i = 0;
    for(double xCoord = start; xCoord < end; xCoord++, i++)
    {
        yCoord[i] = MULTIPLIER * this->operator()(xCoord - WIDTH);
        Path.lineTo(QPointF(MULTIPLIER * xCoord + START_X, MID_Y - yCoord[i]));
    }
    p->drawPath(Path);
}

#endif // TFSIN_H
