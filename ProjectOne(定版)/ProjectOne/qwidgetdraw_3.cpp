#include "qwidgetdraw_3.h"
#include <QPaintEvent>
#include <QPainter>
#include <QtMath>
#include <QTimer>

QWidgetDraw_3::QWidgetDraw_3(QWidget *parent) : QWidget(parent)
{
    this->resize(1000,250);
    //创建像素图
    pixmap = new QPixmap(this->width(), this->height());
    pixmap->fill(Qt::black);

    //创建定时器
    timer = new QTimer(parent);
    timer->start(10);//单位：毫秒
    //定时器timeout信号与时间刷新函数进行关联
    connect(timer,&QTimer::timeout,this,&QWidgetDraw_3::refresh);
}

void QWidgetDraw_3::refresh()
{
    drawPixmap();
    this->update();//每次刷新触发paintEvent事件
}

void QWidgetDraw_3::paintEvent(QPaintEvent *event)
{
   drawWidget();
}

void QWidgetDraw_3::drawWidget()
{
    //把缓冲区内容画到界面this上,就是把画笔画过的痕迹留下来
    QPainter *painter = new QPainter();
    painter->begin(this);//this是widgetDraw，若要在其子界面画图this要改为子界面
    painter->drawPixmap(0,0,*pixmap);
    painter->end();
}

void QWidgetDraw_3::drawPixmap()
{
    //把三角形数据画到像素图pixmap上
    QPainter *painter = new QPainter();
    painter->begin(pixmap);//this是widgetDraw，若要在其子界面画图this要改为子界面(this->pixmap)
    this->drawTriangle(painter);
    painter->end();
}

void QWidgetDraw_3::drawTriangle(QPainter *painter)
{
    //设置画笔参数，修改画笔颜色，线条粗细
    painter->setPen(QPen(Qt::green,6, Qt::DashLine,Qt::RoundCap));

    //获取画图窗口尺寸
    int height = this->height();
    int width = this->width();

    pointX=pointX+1;
    if (0 == dir)
    {
        pointY=pointY+1;
        if (pointY > height/2+7)
          dir=1;
    }
    else
    {
        pointY=pointY-1;
        if(0 == pointY)
        dir=0;
    }

    //擦除历史波形
    painter->save();
    painter->setPen(QPen(Qt::black,4));
    painter->drawLine(pointX+4,0,pointX+1,height);
    painter->restore();

    painter->drawPoint(pointX,height-pointY);
    if(pointX > width - 4)
        pointX = 0;
}
