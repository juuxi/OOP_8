#ifndef TCANVAS_H
#define TCANVAS_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include "sample.h"

class TCanvas : public QWidget
{
    Q_OBJECT
    QLabel* low_arg_name;
    QLineEdit* low_arg_input;
    QLabel* high_arg_name;
    QLineEdit* high_arg_input;
    QLabel* func;
    QRadioButton* sin_rb, *integral_sin_rb;
    QPushButton* submit;

    TSample s;

public:
    TCanvas(QWidget *parent = nullptr);
    ~TCanvas();
protected:
    void paintEvent(QPaintEvent*);

public slots:
    void print_val();
};
#endif // TCANVAS_H
