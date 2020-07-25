#include "qwidgetlabelfive.h"
#include <QLabel>

QWidgetLabelFive::QWidgetLabelFive(QWidget *parent) : QWidget(parent)
{
    this->resize(250,150);
    QLabel *label_T1= new QLabel(this);
    label_T1->setText("T1");
    label_T1->setGeometry(10,30,30,15);
    label_T1->setStyleSheet("color:rgb(160,32,240);font-family:Microsoft YaHei;font-size:15px");
    QLabel *label_T2= new QLabel(this);
    label_T2->setText("T2");
    label_T2->setGeometry(10,80,30,15);
    label_T2->setStyleSheet("color:rgb(160,32,240);font-family:Microsoft YaHei;font-size:15px");
    QLabel *label_TD= new QLabel(this);
    label_TD->setText("TD");
    label_TD->setGeometry(120,50,30,15);
    label_TD->setStyleSheet("color:rgb(160,32,240);font-family:Microsoft YaHei;font-size:15px");
    QLabel *label_sign= new QLabel(this);
    label_sign->setText("℃");
    label_sign->setGeometry(180,0,20,20);
    label_sign->setStyleSheet("color:rgb(160,32,240);font-family:Microsoft YaHei;font-size:20px");
    //三个_?_，从上到下,从左到右
    QLabel *label_T1_date= new QLabel(this);
    label_T1_date->setText("-?-");
    label_T1_date->setGeometry(40,20,30,30);
    label_T1_date->setStyleSheet("color:rgb(160,32,240);font-family:Microsoft YaHei;font-size:24px");
    QLabel *label_T2_date= new QLabel(this);
    label_T2_date->setText("-?-");
    label_T2_date->setGeometry(40,70,30,30);
    label_T2_date->setStyleSheet("color:rgb(160,32,240);font-family:Microsoft YaHei;font-size:24px");
    QLabel *label_TD_date= new QLabel(this);
    label_TD_date->setText("-?-");
    label_TD_date->setGeometry(150,40,30,30);
    label_TD_date->setStyleSheet("color:rgb(160,32,240);font-family:Microsoft YaHei;font-size:24px");
}
