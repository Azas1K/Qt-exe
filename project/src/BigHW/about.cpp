#include "about.h"

#include "ui_about.h"

About::About(QWidget* parent) : QDialog(parent), ui(new Ui::About) {
    ui->setupUi(this);
}

void About::paintEvent(QPaintEvent*) {  // рисование лого
    QPainter painter(this);

    painter.setBrush(Qt::GlobalColor::gray);
    painter.drawRect(QRect(50, 50, 200, 200));

    painter.setBrush(Qt::GlobalColor::red);
    painter.setPen({Qt::GlobalColor::black, 2.0});
    painter.drawRect(QRect(100, 100, 100, 100));

    painter.setBrush(Qt::GlobalColor::blue);
    painter.drawRect(QRect(125, 125, 25, 25));

    painter.setBrush(Qt::GlobalColor::green);
    painter.drawRect(QRect(150, 150, 25, 25));
}

About::~About() { delete ui; }
