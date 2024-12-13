#include "sample.h"
#include <math.h>
#include <QPainterPath>

TSample::TSample(int n)
{
    count=n;
}

void TSample::draw_sin(QPainter* p, QRect r, QColor c)
{
    const int START_X = 10;
    const int MID_X = 260;
    const int MID_Y = 200;
    const int END_X = 530;
    const int MULTIPLIER = 10;
    const int WIDTH = 25;
    p->setPen(QPen(Qt::darkRed));
    p->setRenderHint(QPainter::Antialiasing, true);
    p->drawLine(MID_X, MID_Y - 2 * WIDTH, MID_X, MID_Y + 2 * WIDTH);
    p->drawLine(START_X, MID_Y, END_X, MID_Y);
    p->setPen(QPen(Qt::black));
    QPainterPath Path(QPointF(START_X, MID_Y));
    double yCoord[100];
    for(int xCoord = 0; xCoord < 2 * WIDTH; xCoord++)
    {
        yCoord[xCoord] = MULTIPLIER * sin(xCoord - WIDTH);
        Path.lineTo(QPointF(MULTIPLIER * xCoord + START_X, MID_Y - yCoord[xCoord]));
    }
    p->drawPath(Path);
}

void TSample::draw_integral_sin(QPainter* p, QRect r, QColor c)
{
    const int START_X = 10;
    const int START_DRAW_X = 150;
    const int MID_X = 300;
    const int MID_Y = 200;
    const int END_X = 600;
    const int MULTIPLIER_Y = 60;
    const int MULTIPLIER_X = 15;
    const int WIDTH = 10;
    p->setPen(QPen(Qt::darkRed));
    p->setRenderHint(QPainter::Antialiasing, true);
    p->drawLine(MID_X, MID_Y - 7 * WIDTH, MID_X, MID_Y + 7 * WIDTH);
    p->drawLine(START_X, MID_Y, END_X, MID_Y);
    p->setPen(QPen(Qt::black));
    QPainterPath Path(QPointF(START_DRAW_X, MID_Y));
    double yCoord[400];
    int i = 0;
    for(double xCoord = 0; xCoord < 2 * WIDTH; xCoord += 0.1, i++)
    {
        yCoord[i] = MULTIPLIER_Y * sin(xCoord - WIDTH)/(xCoord - WIDTH);
        Path.lineTo(QPointF(MULTIPLIER_X * xCoord + START_DRAW_X, MID_Y - yCoord[i]));
    }
    p->drawPath(Path);
}
