#include "qwidgetlabelfour.h"
#include <QLabel>

QWidgetLabelFour::QWidgetLabelFour(QWidget *parent) : QWidget(parent)
{
    this->resize(250,150);
    QLabel *label_98= new QLabel(this);
    label_98->setText("98");
    label_98->setGeometry(60,0,75,75);
    label_98->setStyleSheet("color:rgb(255,0,0);font-family:Microsoft YaHei;font-size:50px");
    QLabel *label_84= new QLabel(this);
    label_84->setText("84");
    label_84->setGeometry(110,75,40,20);
    label_84->setStyleSheet("color:rgb(255,0,0);font-family:Microsoft YaHei;font-size:20px");
    QLabel *label_bpm= new QLabel(this);
    label_bpm->setText("bpm");
    label_bpm->setGeometry(150,75,60,20);
    label_bpm->setStyleSheet("color:rgb(255,0,0);font-family:Microsoft YaHei;font-size:20px");
    QLabel *label_sign= new QLabel(this);
    label_sign->setText("%");
    label_sign->setGeometry(180,30,20,20);
    label_sign->setStyleSheet("color:rgb(255,0,0);font-family:Microsoft YaHei;font-size:20px");
}
