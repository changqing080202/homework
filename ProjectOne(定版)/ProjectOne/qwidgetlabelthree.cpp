#include "qwidgetlabelthree.h"
#include <QLabel>
#include "qlabelclock.h"


QWidgetLabelThree::QWidgetLabelThree(QWidget *parent) : QWidget(parent)
{
    this->resize(250,150);
    QLabel *label_sign = new QLabel(this);
    label_sign->setText("/");
    label_sign->setGeometry(150,0,50,100);
    label_sign->setStyleSheet("color:rgb(66,170,249); font-family:Microsoft YaHei; font-size:48px");
    QLabel *label_mmHg = new QLabel(this);
    label_mmHg->setText("mmHg");
    label_mmHg->setGeometry(400,0,60,25);
    label_mmHg->setStyleSheet("color:rgb(66,170,249); font-family:Microsoft YaHei; font-size:18px");
    //设置3个-？-，从左到右
    QLabel *label_dataOne = new QLabel(this);
    label_dataOne->setText("-?-");
    label_dataOne->setGeometry(50,30,80,50);
    label_dataOne->setStyleSheet("color:rgb(66,170,249); font-family:Microsoft YaHei; font-size:30px");
    QLabel *label_dataTwo = new QLabel(this);
    label_dataTwo->setText("-?-");
    label_dataTwo->setGeometry(190,30,80,50);
    label_dataTwo->setStyleSheet("background-color:black; color:rgb(66,170,249); font-family:Microsoft YaHei; font-size:56px");
    QLabel *label_dataThree = new QLabel(this);
    label_dataThree->setText("-?-");
    label_dataThree->setGeometry(400,30,80,50);
    label_dataThree->setStyleSheet("background-color:black; color:rgb(66,170,249); font-family:Microsoft YaHei; font-size:38px");

    //显示时间
    QLabelClock *labelClock = new QLabelClock(this);
    labelClock->setGeometry(210,0,100,25);
    labelClock->setStyleSheet("color:rgb(66,170,249); font-family:Microsoft YaHei; font-size:20px");


}
