#include "qwidgetlabeltwo.h"
#include <QLabel>

QWidgetLabelTwo::QWidgetLabelTwo(QWidget *parent) : QWidget(parent)
{
    this->resize(250,150);
    QLabel *label_ST1 = new QLabel(this);
    label_ST1->setText("ST1");
    label_ST1->setGeometry(60,0,60,30);
    label_ST1->setStyleSheet("background-color:black;color:rgb(0, 255, 0);font-family:Microsoft YaHei;font-size:20px");
    QLabel *label_ST2 = new QLabel(this);
    label_ST2->setText("bpm");
    label_ST2->setGeometry(60,30,60,30);
    label_ST2->setStyleSheet("color:rgb(0,255,0);font-family:Microsoft YaHei;font-size:20px");
    QLabel *label_PVCs = new QLabel(this);
    label_PVCs->setText("PVCs");
    label_PVCs->setGeometry(60,60,60,30);
    label_PVCs->setStyleSheet("color:rgb(0,255,0);font-family:Microsoft YaHei;font-size:20px");
    //三个_?_，从上到下
    QLabel *label_ST1_data = new QLabel(this);
    label_ST1_data->setText("-?-");
    label_ST1_data->setGeometry(120,0,40,30);
    label_ST1_data->setStyleSheet("color:rgb(0,255,0);font-family:Microsoft YaHei;font-size:20px");
    QLabel *label_ST2_data = new QLabel(this);
    label_ST2_data->setText("-?-");
    label_ST2_data->setGeometry(120,30,40,30);
    label_ST2_data->setStyleSheet("color:rgb(0,255,0);font-family:Microsoft YaHei;font-size:20px");
    QLabel *label_PVCs_data = new QLabel(this);
    label_PVCs_data->setText("-?");
    label_PVCs_data->setGeometry(120,60,40,30);
    label_PVCs_data->setStyleSheet("color:rgb(0,255,0);font-family:Microsoft YaHei;font-size:20px");


}
