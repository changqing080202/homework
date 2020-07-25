#include "widgetdraw.h"
#include <QPaintEvent>
#include <QPainter>
float bufdata = 0;
float lastdata = 0;

WidgetDraw::WidgetDraw(QWidget *parent) : QWidget(parent)
{
    this->resize(600,150);
    pixmap = new QPixmap(this->width(), this->height());
    pixmap->fill(Qt::black);
    timer = new QTimer(parent);
}

void WidgetDraw::refresh()
{
    drawPixmap();
    this->update();
}

void WidgetDraw::paintEvent(QPaintEvent *event)
{
    drawWidget();
}

void WidgetDraw::drawWidget()
{
    QPainter *painter = new QPainter();
    painter->begin(this);
    painter->drawPixmap(0,0,*pixmap);
    painter->end();
}

void WidgetDraw::drawPixmap()
{
    QPainter *painter = new QPainter();
    painter->begin(pixmap);
    this->drawData(painter);
    painter->end();
}

void WidgetDraw::drawData(QPainter *painter)
{
    painter->setPen(QPen(Qt::red,2,Qt::DashLine,Qt::RoundCap));
    int height = this->height();
    int width = this->width();
    pointX = pointX + 1;
    painter->save();
    painter->setPen(QPen(Qt::black,8));
    painter->drawRect(pointX+4,0,1,height);
    painter->restore();
    painter->drawLine(QPoint(pointX, height - (bufdata/8-200)),QPoint(pointX+1, height - (lastdata/8-200)));
    if(pointX > width-4)
    {
        pointX = 0;
    }
    if(temp >= 2500)
    {
        temp = 0;
    }
}

void WidgetDraw::erase()
{
    QPainter *painter = new QPainter();

    int height = this->height();
    int width = this->width();
    painter->begin(this);
    painter->setBrush(Qt::black);
    painter->drawRect(0,0,height,width);
    painter->end();

}
