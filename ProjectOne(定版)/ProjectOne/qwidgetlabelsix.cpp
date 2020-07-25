#include "qwidgetlabelsix.h"
#include <QLabel>

QWidgetLabelSix::QWidgetLabelSix(QWidget *parent) : QWidget(parent)
{
    this->resize(250,150);
    QLabel *label_bpm= new QLabel(this);
    label_bpm->setText("bpm");
    label_bpm->setGeometry(160,0,40,30);
    label_bpm->setStyleSheet("color:rgb(255,219,53);font-family:Microsoft YaHei;font-size:18px");
    //设置-？-
    QLabel *label_date= new QLabel(this);
    label_date->setText("-?-");
    label_date->setGeometry(60,0,100,70);
    label_date->setStyleSheet("color:rgb(255,219,53);font-family:Microsoft YaHei;font-size:70px");
}
