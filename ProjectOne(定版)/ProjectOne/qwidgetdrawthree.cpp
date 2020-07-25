#include "qwidgetdrawthree.h"
#include <QPaintEvent>
#include <QPainter>
#include <QtMath>
#include <QTimer>

QWidgetDrawThree::QWidgetDrawThree(QWidget *parent) : QWidget(parent)
{
    this->resize(1000,200);
    //创建像素图
    pixmap = new QPixmap(this->width(), this->height());
    pixmap->fill(Qt::black);

    //创建定时器
    timer = new QTimer(parent);
    timer->start(5);//单位：毫秒
    //定时器timeout信号与时间刷新函数进行关联
    connect(timer,&QTimer::timeout,this,&QWidgetDrawThree::refresh);
}

void QWidgetDrawThree::refresh()
{
    drawPixmap();
    this->update();//每次刷新触发paintEvent事件
}

void QWidgetDrawThree::paintEvent(QPaintEvent *event)
{
   drawWidget();
}

void QWidgetDrawThree::drawWidget()
{
    //把缓冲区内容画到界面this上,就是把画笔画过的痕迹留下来
    QPainter *painter = new QPainter();
    painter->begin(this);
    painter->drawPixmap(0,0,*pixmap);
    painter->end();
}

void QWidgetDrawThree::drawPixmap()
{
    //把三角形数据画到像素图pixmap上
    QPainter *painter = new QPainter();
    painter->begin(pixmap);//
    this->drawTriangle(painter);
    painter->end();
}

void QWidgetDrawThree::drawTriangle(QPainter *painter)
{
    //设置画笔参数，修改画笔颜色，线条粗细
    painter->setPen(QPen(Qt::yellow,3, Qt::DashLine,Qt::RoundCap));

    //获取画图窗口尺寸
    int height = this->height();
    int width = this->width();

    pointX=pointX+1;
    if (0 == dir)
    {
        pointY=pointY+1;
        if (pointY > height*0.8)
          dir=1;
    }
    else
    {
        pointY=pointY-1;
        if(pointY<height*0.2)
        dir=0;
    }


    //擦除历史波形
    painter->save();
    painter->setPen(QPen(Qt::black,2));
    painter->drawRect(pointX, 0, 10, height);
    painter->restore();

    painter->drawPoint(pointX, height - pointY);
    if(pointX > width - 4)
        pointX = 0;
}

