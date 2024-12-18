#include "canvas.h"

TCanvas::TCanvas(QWidget *parent)
    : QWidget(parent)
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
    const double double_NULL = -1000.1;
    p.begin(this);
    if (sin_rb->isChecked())
    {
        TFsin<double> sin_func(15);
        if (low_arg_input->text() == "" && high_arg_input->text() == "")
            sin_func.draw(&p, double_NULL, double_NULL);
        else if (low_arg_input->text() == "")
            sin_func.draw(&p, double_NULL, high_arg_input->text().toDouble());
        else if (high_arg_input->text() == "")
            sin_func.draw(&p, low_arg_input->text().toDouble(), double_NULL);
        else
            sin_func.draw(&p, low_arg_input->text().toDouble(), high_arg_input->text().toDouble());
    }

    if (integral_sin_rb->isChecked()) 
    {
        TFSi<double> si_func(30);
        if (low_arg_input->text() == "" && high_arg_input->text() == "")
            si_func.draw(&p, double_NULL, double_NULL);
        else if (low_arg_input->text() == "")
            si_func.draw(&p, double_NULL, high_arg_input->text().toDouble());
        else if (high_arg_input->text() == "")
            si_func.draw(&p, low_arg_input->text().toDouble(), double_NULL);
        else
            si_func.draw(&p, low_arg_input->text().toDouble(), high_arg_input->text().toDouble());
    }
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

