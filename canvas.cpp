#include "canvas.h"

TCanvas::TCanvas(QWidget *parent)
    : QWidget(parent), s(7)
{
    setWindowTitle("Практика №8");
    setFixedSize(800, 500);
    low_arg_name = new QLabel("Аргумент от", this);
    low_arg_name->setGeometry(30, 10, 120, 30);

    low_arg_input = new QLineEdit(this);
    low_arg_input->setGeometry(130, 15, 30, 20);

    high_arg_name = new QLabel("до", this);
    high_arg_name->setGeometry(170, 10, 20, 30);

    high_arg_input = new QLineEdit(this);
    high_arg_input->setGeometry(190, 15, 30, 20);

    func = new QLabel("Вычислить функцию", this);
    func->setGeometry(30, 60, 200, 30);

    sin_rb = new QRadioButton("sin", this);
    sin_rb->setGeometry(210, 60, 70, 30);

    integral_sin_rb = new QRadioButton("Si", this);
    integral_sin_rb->setGeometry(280, 60, 50, 30);

    submit = new QPushButton("Применить", this);
    submit->setGeometry(100, 120, 150, 30);

    connect(submit, SIGNAL(pressed()), this, SLOT(print_val()));
}

void TCanvas::paintEvent(QPaintEvent*)
{
    QPainter p;
    p.begin(this);
    if (sin_rb->isChecked())
        s.draw_sin(&p,rect(),Qt::green);
    if (integral_sin_rb->isChecked())
        ;
    p.end();
}

void TCanvas::print_val()
{
//    if (sin_rb->isChecked())
//    {
//        int n = power_input->text().toInt();
//        TFsin<double> sin_func(n);
//        QString s;
//        s += "p(";
//        s += QString::number(a_re->text().toDouble());
//        s += ") = ";
//        s += QString::number(sin_func(a_re->text().toDouble()));
//        output->setText(s);
//    }
//    else if (integral_sin_rb->isChecked())
//    {
//        int n = power_input->text().toInt();
//        TFSi<double> Si_func(n);
//        QString s;
//        s += "p(";
//        s += QString::number(a_re->text().toDouble());
//        s += ") = ";
//        s += QString::number(Si_func(a_re->text().toDouble()));
//        output->setText(s);
//    }
    update();
}

TCanvas::~TCanvas()
{
    delete low_arg_name;
    delete low_arg_input;
    delete high_arg_name;
    delete high_arg_input;
    delete func;
    delete sin_rb;
    delete integral_sin_rb;
    delete submit;
}

