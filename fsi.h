#ifndef TFSI_H
#define TFSI_H

#include "function.h"

template <class number>
class TFSi : public TFunction<number>
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
            {
                der_value[i] = cos(0);
                der_value[i] = der_value[i] / i;
            }
            else if (i % 4 == 3)
            {
                der_value[i] = -cos(0);
                der_value[i] = der_value[i] / i;
            }
        }
        return der_value;
    }
public:
    TFSi(int n) : TFunction<number> (n, count_der(n)) {};
    void draw(QPainter*, double, double);
    ~TFSi() {delete [] der_value;}
};

template <class number>
void TFSi<number>::draw(QPainter* p, double start, double end)
{
    const double double_NULL = -1000.1;
    const int START_X = 10;
    const int MID_Y = 200;
    const int END_X = 610;
    const int MID_X = (START_X + END_X) / 2;
    const int MULTIPLIER_Y = 60;
    const int MULTIPLIER_X = 15;
    const int WIDTH = 20;
    if (start == double_NULL)
        start = 0;
    else
        start += WIDTH;

    if (end == double_NULL)
        end = 2 * WIDTH;
    else
        end += WIDTH;
    p->setPen(QPen(Qt::darkRed));
    p->setRenderHint(QPainter::Antialiasing, true);
    p->drawLine(MID_X, MID_Y - 4 * WIDTH, MID_X, MID_Y + 4 * WIDTH);
    p->drawLine(START_X, MID_Y, END_X, MID_Y);
    p->setPen(QPen(Qt::black));

    p->drawLine(MID_X-3, MID_Y - MULTIPLIER_Y, MID_X+3, MID_Y - MULTIPLIER_Y);
    p->drawLine(MID_X-3, MID_Y + MULTIPLIER_Y, MID_X+3, MID_Y + MULTIPLIER_Y);
    p->drawText(QPointF(MID_X + 1, MID_Y - MULTIPLIER_Y), "1");
    p->drawText(QPointF(MID_X + 1, MID_Y + MULTIPLIER_Y), "-1");

    p->drawLine(MID_X - MULTIPLIER_X, MID_Y - 3, MID_X - MULTIPLIER_X, MID_Y + 3);
    p->drawLine(MID_X + MULTIPLIER_X, MID_Y - 3, MID_X + MULTIPLIER_X, MID_Y + 3);
    p->drawText(QPointF(MID_X + MULTIPLIER_X, MID_Y + 1), "1");
    p->drawText(QPointF(MID_X - MULTIPLIER_X, MID_Y + 1), "-1");

    QPainterPath Path(QPointF(MULTIPLIER_X * (start + 0.1), MID_Y));
    double yCoord[400];
    int i = 0;
    for(double xCoord = start; xCoord < end; xCoord += 0.1, i++)
    {
        yCoord[i] = MULTIPLIER_Y * this->operator()(xCoord - WIDTH);
        Path.lineTo(QPointF(MULTIPLIER_X * xCoord + START_X, MID_Y - yCoord[i]));
    }
    p->drawPath(Path);
}

#endif // TFSI_H
