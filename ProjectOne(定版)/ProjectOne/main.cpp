#include <QApplication>
#include <QLayout>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include "qwidgetdraw.h"
#include "qwidgetdrawtwo.h"
#include "qwidgetdrawthree.h"
#include "qwidgetlabelone.h"
#include "qwidgetlabeltwo.h"
#include "qwidgetlabelthree.h"
#include "qwidgetlabelfour.h"
#include "qwidgetlabelfive.h"
#include "qwidgetlabelsix.h"
#include "qwidgetlabelseven.h"
#include "qwidgetlabeltitle.h"
#include "tcpclient.h"

void create_Layout( QWidget *mainWin)
{
    mainWin->resize(1500,660);
    mainWin->setWindowTitle("第6组");
    mainWin->setStyleSheet("background-color:black");
//    mainWin->setWindowFlags(Qt::CustomizeWindowHint);//隐藏标题栏

    //设置11个窗口，顺序从上到下，从左到右
    QWidgetLabelTitle *one = new QWidgetLabelTitle();
    one->setStyleSheet("background-color:rgb(79,79,79)");

    QWidgetDraw *two = new QWidgetDraw();
    two->setStyleSheet("background-color:rgb(0, 0, 0)");

    QWidgetDrawTwo *three = new QWidgetDrawTwo();
    three->setStyleSheet("background-color:rgb(0, 0, 0)");

    QWidgetDrawThree *four = new QWidgetDrawThree();
    four->setStyleSheet("background-color:rgb(0, 0, 0)");

    QWidgetLabelOne *five = new QWidgetLabelOne();
    five->setStyleSheet("background-color:black");

    QWidgetLabelTwo *six = new QWidgetLabelTwo();
    six->setStyleSheet("background-color:black");

    QWidgetLabelThree *seven = new QWidgetLabelThree();
    seven->setStyleSheet("background-color:black");

    QWidgetLabelFour *eight = new QWidgetLabelFour();
    eight->setStyleSheet("background-color:black");

    QWidgetLabelFive *nine = new QWidgetLabelFive();
    nine->setStyleSheet("background-color:black");

    QWidgetLabelSix *ten = new QWidgetLabelSix();
    ten->setStyleSheet("background-color:black");

    QWidgetLabelSeven *eleven = new QWidgetLabelSeven();
    eleven->setStyleSheet("background-color:black");

    //设置10个label，用来添加文本
    QLabel *label_1 = new QLabel();
    label_1->setText("    ECG II        X1");
    label_1->setStyleSheet("background-color:rgb(0,0,0);color:white;font-family:Microsoft YaHei;font-size:18px");
    QLabel *label_2 = new QLabel();
    label_2->setText("    SPO2");
    label_2->setStyleSheet("background-color:rgb(0,0,0);color:white;font-family:Microsoft YaHei;font-size:18px");
    QLabel *label_3 = new QLabel();
    label_3->setText("     RESP          X1");
    label_3->setStyleSheet("background-color:rgb(0,0,0);color:white;font-family:Microsoft YaHei;font-size:18px");
    QLabel *label_4 = new QLabel();
    label_4->setText("   HR                                                ▣");
    label_4->setStyleSheet("background-color:rgb(105,105,105);color:white;font-family:Microsoft YaHei;font-size:15px");
    QLabel *label_5 = new QLabel();
    label_5->setText("   ST                                                ▣");
    label_5->setStyleSheet("background-color:rgb(105,105,105);color:white;font-family:Microsoft YaHei;font-size:15px");
    QLabel *label_6 = new QLabel();
    label_6->setText("   NIBP                                                                                                    ?");
    label_6->setStyleSheet("background-color:rgb(105,105,105);color:white;font-family:Microsoft YaHei;font-size:15px");
    QLabel *label_7 = new QLabel();
    label_7->setText("   SpO2                                           ?");
    label_7->setStyleSheet("background-color:rgb(105,105,105);color:white;font-family:Microsoft YaHei;font-size:15px");
    QLabel *label_8 = new QLabel();
    label_8->setText("   TEMP                                            ?");
    label_8->setStyleSheet("background-color:rgb(105,105,105);color:white;font-family:Microsoft YaHei;font-size:15px");
    QLabel *label_9 = new QLabel();
    label_9->setText("   RESP                                              ?");
    label_9->setStyleSheet("background-color:rgb(105,105,105);color:white;font-family:Microsoft YaHei;font-size:15px");
    QLabel *label_10 = new QLabel();
    label_10->setText("   CO2                                              ?");
    label_10->setStyleSheet("background-color:rgb(105,105,105);color:white;font-family:Microsoft YaHei;font-size:15px");

    //网格布局
    QGridLayout *gLayout = new QGridLayout();
    gLayout->addWidget(one,0, 0, 4, 6);
    gLayout->addWidget(label_1,4, 0, 3, 4);
    gLayout->addWidget(two,7, 0, 13, 4);
    gLayout->addWidget(label_2,20, 0, 3, 4);
    gLayout->addWidget(three,23, 0, 13, 4);
    gLayout->addWidget(label_3,36, 0, 3, 4);
    gLayout->addWidget(four,39, 0, 13, 4);
    gLayout->addWidget(label_4,4, 4, 2, 1);
    gLayout->addWidget(five,6, 4, 10, 1);
    gLayout->addWidget(label_5,4, 5, 2, 1);
    gLayout->addWidget(six,6, 5, 10, 1);
    gLayout->addWidget(label_6,16, 4, 2, 2);
    gLayout->addWidget(seven,18, 4, 10, 2);
    gLayout->addWidget(label_7,28, 4, 2, 1);
    gLayout->addWidget(eight,30, 4, 10, 1);
    gLayout->addWidget(label_8,28, 5, 2, 1);
    gLayout->addWidget(nine,30, 5, 10, 1);
    gLayout->addWidget(label_9,40, 4, 2, 1);
    gLayout->addWidget(ten,42, 4, 10, 1);
    gLayout->addWidget(label_10,40, 5, 2, 1);
    gLayout->addWidget(eleven,42, 5, 10, 1);

    //设置竖向间距
    gLayout->setHorizontalSpacing(0);
    //设置横向间距
    gLayout->setVerticalSpacing(0);
    //设置外间距
    gLayout->setContentsMargins(0,0,0,0);
    //布局器用到界面
    mainWin->setLayout(gLayout);



}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget *Monitor = new QWidget();
    create_Layout(Monitor);
    Monitor->show();

    TcpClient *mTcpClient = new TcpClient();
    mTcpClient->setWindowTitle("六组-何葳");
    mTcpClient->show();



    return a.exec();
}
