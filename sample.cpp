#include "sample.h"
#include <math.h>
#include <QPainterPath>

TSample::TSample(int n)
{
    count=n;
}

void TSample::draw_sin(QPainter* p, double start = 0, double end = 0)
{
    const int START_X = 10;
    const int MID_Y = 200;
    const int END_X = 510;
    const int MID_X = (START_X + END_X) / 2;
    const int MULTIPLIER = 10;
    const int WIDTH = 25;
    if (!end)
        end = 2 * WIDTH;
    p->setPen(QPen(Qt::darkRed));
    p->setRenderHint(QPainter::Antialiasing, true);
    p->drawLine(MID_X, MID_Y - 2 * WIDTH, MID_X, MID_Y + 2 * WIDTH);
    p->drawLine(START_X, MID_Y, END_X, MID_Y);
    p->setPen(QPen(Qt::black));
    QPainterPath Path(QPointF(START_X, MID_Y));
    double yCoord[100];
    int i = 0;
    for(double xCoord = start; xCoord < end; xCoord++, i++)
    {
        yCoord[i] = MULTIPLIER * sin(xCoord - WIDTH);
        Path.lineTo(QPointF(MULTIPLIER * xCoord + START_X, MID_Y - yCoord[i]));
    }
    p->drawPath(Path);
}

void TSample::draw_integral_sin(QPainter* p, double start, double end)
{
    const int START_X = 10;
    const int MID_Y = 200;
    const int END_X = 610;
    const int MID_X = (START_X + END_X) / 2;
    const int MULTIPLIER_Y = 60;
    const int MULTIPLIER_X = 15;
    const int WIDTH = 20;
    if (!end)
        end = 2 * WIDTH;
    p->setPen(QPen(Qt::darkRed));
    p->setRenderHint(QPainter::Antialiasing, true);
    p->drawLine(MID_X, MID_Y - 4 * WIDTH, MID_X, MID_Y + 4 * WIDTH);
    p->drawLine(START_X, MID_Y, END_X, MID_Y);
    p->setPen(QPen(Qt::black));
    QPainterPath Path(QPointF(START_X, MID_Y));
    double yCoord[400];
    int i = 0;
    for(double xCoord = start; xCoord < end; xCoord += 0.1, i++)
    {
        yCoord[i] = MULTIPLIER_Y * sin(xCoord - WIDTH)/(xCoord - WIDTH);
        Path.lineTo(QPointF(MULTIPLIER_X * xCoord + START_X, MID_Y - yCoord[i]));
    }
    p->drawPath(Path);
}
