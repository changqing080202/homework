#include "qwidgetlabelseven.h"
#include <QLabel>

QWidgetLabelSeven::QWidgetLabelSeven(QWidget *parent) : QWidget(parent)
{
    this->resize(250,150);
    QLabel *label_ins= new QLabel(this);
    label_ins->setText("ins");
    label_ins->setGeometry(20,80,40,30);
    label_ins->setStyleSheet("color:rgb(255,219,53);font-family:Microsoft YaHei;font-size:18px");
    QLabel *label_awrr= new QLabel(this);
    label_awrr->setText("awrr");
    label_awrr->setGeometry(100,80,40,30);
    label_awrr->setStyleSheet("color:rgb(255,219,53);font-family:Microsoft YaHei;font-size:18px");
    QLabel *label_mmHg= new QLabel(this);
    label_mmHg->setText("mmHg");
    label_mmHg->setGeometry(160,0,80,30);
    label_mmHg->setStyleSheet("color:rgb(255,219,53);font-family:Microsoft YaHei;font-size:18px");
    // //三个_?_，从上到下，从左到右
    QLabel *label_bigdate= new QLabel(this);
    label_bigdate->setText("-?-");
    label_bigdate->setGeometry(60,30,60,40);
    label_bigdate->setStyleSheet("color:rgb(255,219,53);font-family:Microsoft YaHei;font-size:40px");
    QLabel *label_ins_date= new QLabel(this);
    label_ins_date->setText("-?-");
    label_ins_date->setGeometry(60,80,40,30);
    label_ins_date->setStyleSheet("color:rgb(255,219,53);font-family:Microsoft YaHei;font-size:18px");
    QLabel *label_awrr_date= new QLabel(this);
    label_awrr_date->setText("-?-");
    label_awrr_date->setGeometry(150,80,40,30);
    label_awrr_date->setStyleSheet("color:rgb(255,219,53);font-family:Microsoft YaHei;font-size:18px");
}
