#include "qwidgetlabeltitle.h"
#include <QLabel>

QWidgetLabelTitle::QWidgetLabelTitle(QWidget *parent) : QWidget(parent)
{
    this->resize(1500,60);
    QLabel *label_left_title= new QLabel(this);
    label_left_title->setText("       设备：XD001 备注：001");
    label_left_title->setGeometry(10,0,500,60);
    label_left_title->setStyleSheet("background-color:black;color:white;font-family:Microsoft YaHei;font-size:18px");
    QLabel *label_right_title= new QLabel(this);
    label_right_title->setText("                          ☐");
    label_right_title->setGeometry(900,0,500,60);
    label_right_title->setStyleSheet("background-color:black;color:white;font-family:Microsoft YaHei;font-size:20px");
}
