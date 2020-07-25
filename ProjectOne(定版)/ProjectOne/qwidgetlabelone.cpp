#include "qwidgetlabelone.h"
#include <QLabel>

QWidgetLabelOne::QWidgetLabelOne(QWidget *parent) : QWidget(parent)
{
    this->resize(250,150);
    QLabel *label_80 = new QLabel(this);
    label_80->setText("80");
    label_80->setGeometry(60,0,75,75);
    label_80->setStyleSheet("background-color:black;color:rgb(0, 255, 0);font-family:Microsoft YaHei;font-size:50px");
    QLabel *label_bpm = new QLabel(this);
    label_bpm->setText("bpm");
    label_bpm->setGeometry(170,0,40,20);
    label_bpm->setStyleSheet("color:rgb(0,255,0);font-family:Microsoft YaHei;font-size:18px");
}
