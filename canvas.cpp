#include "canvas.h"

TCanvas::TCanvas(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Практика №8");
    setFixedSize(800, 500);
    power = new QLabel("Точность вычисления", this);
    power->setGeometry(10, 10, 200, 30);

    power_input = new QLineEdit(this);
    power_input->setGeometry(210, 15, 30, 20);

    a_name = new QLabel("a = ", this);
    a_name->setGeometry(10, 90, 20, 30);

    a_re = new QLineEdit(this);
    a_re->setGeometry(30, 95, 30, 20);

    func = new QLabel("Вычислить функцию", this);
    func->setGeometry(10, 60, 200, 30);

    sin_rb = new QRadioButton("sin", this);
    sin_rb->setGeometry(210, 60, 70, 30);

    integral_sin_rb = new QRadioButton("Si", this);
    integral_sin_rb->setGeometry(280, 60, 50, 30);

    submit = new QPushButton("Применить", this);
    submit->setGeometry(100, 150, 150, 30);

    output = new QLabel(this);
    output->setGeometry(10, 200, 500, 30);

    connect(submit, SIGNAL(pressed()), this, SLOT(print_val()));
}

void TCanvas::paintEvent(QPaintEvent*)
{
    qreal cw = 0.5*rect().width();
    qreal ch = 0.5*rect().height();
    qreal cr = 0.9*(cw>ch?ch:cw);
    qreal a = 2.0*acos(-1.0)/7;
    QPainter p;
    p.begin(this);
    QPointF *t = new QPointF[7];
    for (int i=0; i<7; i++)
    {
        t[i] = QPointF(cw+cr*sin(i*a),ch-cr*cos(i*a));
    }
    p.drawPolygon(t, 7);
    p.end();
    delete [] t;
}

void TCanvas::print_val()
{
    if (sin_rb->isChecked())
    {
        int n = power_input->text().toInt();
        TFsin<double> sin_func(n);
        QString s;
        s += "p(";
        s += QString::number(a_re->text().toDouble());
        s += ") = ";
        s += QString::number(sin_func(a_re->text().toDouble()));
        output->setText(s);
    }
    else if (integral_sin_rb->isChecked())
    {
        int n = power_input->text().toInt();
        TFSi<double> Si_func(n);
        QString s;
        s += "p(";
        s += QString::number(a_re->text().toDouble());
        s += ") = ";
        s += QString::number(Si_func(a_re->text().toDouble()));
        output->setText(s);
    }
}

TCanvas::~TCanvas()
{
    delete power;
    delete power_input;
    delete a_name;
    delete a_re;
    delete func;
    delete sin_rb;
    delete integral_sin_rb;
    delete submit;
    delete output;
}

