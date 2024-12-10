#ifndef TCANVAS_H
#define TCANVAS_H

#include <QWidget>
#include <QPainter>
//#include "interface.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include "complex.h"
#include "fsin.h"
#include "fsi.h"

class TCanvas : public QWidget
{
    Q_OBJECT
    QLabel* power;
    QLineEdit* power_input;
    QLabel* a_name, *a_delimiter;
    QLineEdit* a_re, *a_im;
    QLabel* func;
    QRadioButton* sin_rb, *integral_sin_rb;
    QPushButton* submit;
    QLabel* output;

public:
    TCanvas(QWidget *parent = nullptr);
    ~TCanvas();
protected:
    void paintEvent(QPaintEvent*);

public slots:
    void print_val();
};
#endif // TCANVAS_H
