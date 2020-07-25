#include "qwidgetdraw.h"
#include <QPaintEvent>
#include <QPainter>
#include <QtMath>
#include <QTimer>


QWidgetDraw::QWidgetDraw(QWidget *parent) : QWidget(parent)
{

    this->resize(1000,200);
    serialPort = new QSerialPort();

    serialPort->setPortName("COM4");

    serialPort->open(QIODevice::ReadWrite);

    timer2 = new QTimer(parent); //创建定时器

    if(serialPort->isOpen())
    {
        qDebug("Open Serial");
        serialPort->setBaudRate(QSerialPort::Baud115200,QSerialPort::AllDirections); //设置波特率和读写方向
        serialPort->setDataBits(QSerialPort::Data8);  //数据位数为8位
        serialPort->setFlowControl(QSerialPort::NoFlowControl);  //无流控制
        serialPort->setParity(QSerialPort::NoParity);  //无校验位
        serialPort->setStopBits(QSerialPort::OneStop);  //一位停止位

        connect(timer2, &QTimer::timeout, this, &QWidgetDraw::sendPkg);
        timer2->start(5000);
        //serialPort->close();

    }
    else{
        qDebug("Open Serial failed");
    }

    //创建像素图
    pixmap  = new QPixmap(this->width(), this->height());
//    pixmap->fill(Qt::black);

    //创建定时器
    timer = new QTimer(parent);
    timer->start(5);

    //定时器timeout信号与时间刷新函数进行关联/绑定
    //信号与槽机制实现
    connect(timer, &QTimer::timeout, this, &QWidgetDraw::refresh);
}

void QWidgetDraw::refresh()
{
    drawPixmap();
    this->update();
}

void QWidgetDraw::sendPkg()
{
     qDebug("Send Data!");
     char dataBuf[10] = "abcde";
     serialPort->write(dataBuf, 5);
}

void QWidgetDraw::paintEvent(QPaintEvent *event)
{
    drawWidget();
}

void QWidgetDraw::drawPixmap()
{
    QPainter *painter = new QPainter();
    //启动绘图
    painter->begin(this->pixmap);
    //    this->drawSinWave(painter);
    this->drawWave(painter);

    //绘图结束
    painter->end();
}

void QWidgetDraw::drawWidget()
{

    QPainter *painter = new QPainter();
    //启动绘图
    painter->begin(this);
    //把缓冲区内容画到界面上
    painter->drawPixmap(0, 0, *pixmap);
    //绘图结束
    painter->end();

}

void QWidgetDraw::drawWave(QPainter *painter)
{
    //设置画图参数，修改画笔颜色，线条粗细
    painter->setPen(QPen(Qt::green,3,Qt::SolidLine,Qt::RoundCap));

    int height = this->height();
    int width = this->width();

    int ecgWave[500] = {
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2008, 2016, 2016, 2016, 2024, 2032, 2048,
            2064, 2064, 2064, 2072, 2080, 2080, 2080, 2088, 2096, 2104,
            2112, 2112, 2112, 2112, 2112, 2112, 2104, 2096, 2088,
            2080, 2080, 2080, 2072, 2064, 2064, 2064, 2048, 2032, 2032,
            2032, 2016, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 1992, 1984, 1976,
            1968, 1960, 1952, 1944, 1936, 1944, 1952, 2016, 2080, 2136,
            2192, 2256, 2320, 2376, 2432, 2488, 2544, 2568, 2592, 2536,
            2480, 2424, 2368, 2304, 2240, 2184, 2128, 2072, 2016, 1968,
            1920, 1928, 1936, 1944, 1952, 1960, 1968, 1984, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2008, 2016, 2024, 2032, 2032,
            2032, 2048, 2064, 2064, 2064, 2072, 2080, 2088, 2096, 2104,
            2112, 2112, 2112, 2120, 2128, 2136, 2144, 2152, 2160, 2160,
            2160, 2160, 2160, 2168, 2176, 2176, 2176, 2184, 2192,
            2192, 2192, 2192, 2200, 2208, 2208, 2208, 2208, 2208, 2208,
            2208, 2200, 2192, 2192, 2192, 2184, 2176, 2176, 2176, 2168,
            2160, 2160, 2160, 2144, 2128, 2128, 2128, 2128, 2128, 2112,
            2096, 2088, 2080, 2072, 2064, 2064, 2064, 2048, 2032, 2024,
            2016, 2016, 2016, 2008, 2000, 2000, 2000, 2000, 2000,
            2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000};


    pointX = pointX +1;
    if( dir < 497)
    {
        pointYY = pointY;
        pointY = (ecgWave[dir])/8-200;
        dir = dir + 3;
    }
    else
    {
        pointYY = pointY;
        pointY = (ecgWave[497])/8-200;
        dir = 0;
    }


    //擦除历史波形
    painter->save();
    painter->setPen(QPen(Qt::black,2));
    painter->drawRect(pointX, 0, 10, height);
    painter->restore();

    painter->drawLine(pointX, height - pointY,pointX+1,height -pointYY);

    if (pointX > width-2)
        pointX = 0;
}



