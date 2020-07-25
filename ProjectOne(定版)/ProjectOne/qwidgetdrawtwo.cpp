#include "qwidgetdrawtwo.h"
#include <QPaintEvent>
#include <QPainter>
#include <QtMath>
#include <QTimer>

QWidgetDrawTwo::QWidgetDrawTwo(QWidget *parent) : QWidget(parent)
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

        connect(timer2, &QTimer::timeout, this, &QWidgetDrawTwo::sendPkg);
        timer2->start(5000);
        //serialPort->close();

    }
    else{
        qDebug("Open Serial failed");
    }

    //创建像素图
    pixmap  = new QPixmap(this->width(), this->height());

    //创建定时器
    timer = new QTimer(parent);
    timer->start(5);

    //定时器timeout信号与时间刷新函数进行关联/绑定
    //信号与槽机制实现
    connect(timer, &QTimer::timeout, this, &QWidgetDrawTwo::refresh);
}

void QWidgetDrawTwo::refresh()
{
    drawPixmap();
    this->update();
}

void QWidgetDrawTwo::sendPkg()
{
     qDebug("Send Data!");
     char dataBuf[10] = "abcde";
     serialPort->write(dataBuf, 5);
}

void QWidgetDrawTwo::paintEvent(QPaintEvent *event)
{
    drawWidget();
}

void QWidgetDrawTwo::drawPixmap()
{
    QPainter *painter = new QPainter();

    //启动绘图
    painter->begin(this->pixmap);
    //    this->drawSinWave(painter);
    this->drawSinWave(painter);

    //绘图结束
    painter->end();
}

void QWidgetDrawTwo::drawWidget()
{

    QPainter *painter = new QPainter();


    //启动绘图
    painter->begin(this);
    //把缓冲区内容画到界面上
    painter->drawPixmap(0, 0, *pixmap);

    //绘图结束
    painter->end();

}

void QWidgetDrawTwo::drawSinWave(QPainter *painter)
{
    //设置画图参数，修改画笔颜色，线条粗细
    painter->setPen(QPen(Qt::red,3,Qt::SolidLine,Qt::RoundCap));

    int height = this->height();
    int width = this->width();

    int sinWave[500] = {
            63,63,63,63,63,63,63,63,63,63,
            63,62,62,62,62,62,62,62,61,61,
            61,61,61,60,60,60,60,59,59,59,
            59,58,58,58,57,57,57,56,56,56,
            55,55,54,54,54,53,53,52,52,51,
            51,50,50,49,49,48,48,47,47,46,
            46,45,45,44,44,43,42,42,41,41,
            40,39,39,38,38,37,36,36,35,34,
            34,33,32,32,31,30,30,29,28,27,
            27,26,25,25,24,23,22,22,21,20,
            19,19,18,17,16,16,15,14,13,12,
            12,11,10,9,9,8,7,6,5,5,
            4,3,2,1,1,0,-1,-2,-3,-3,
            -4,-5,-6,-7,-7,-8,-9,-10,-10,-11,
            -12,-13,-14,-14,-15,-16,-17,-17,-18,-19,
            -20,-20,-21,-22,-23,-23,-24,-25,-26,-26,
            -27,-28,-28,-29,-30,-31,-31,-32,-33,-33,
            -34,-35,-35,-36,-37,-37,-38,-39,-39,-40,
            -40,-41,-42,-42,-43,-43,-44,-44,-45,-46,
            -46,-47,-47,-48,-48,-49,-49,-50,-50,-51,
            -51,-52,-52,-53,-53,-53,-54,-54,-55,-55,
            -55,-56,-56,-56,-57,-57,-57,-58,-58,-58,
            -59,-59,-59,-60,-60,-60,-60,-60,-61,-61,
            -61,-61,-61,-62,-62,-62,-62,-62,-62,-62,
            -63,-63,-63,-63,-63,-63,-63,-63,-63,-63,
            -63,-63,-63,-63,-63,-63,-63,-63,-63,-63,
            -62,-62,-62,-62,-62,-62,-62,-61,-61,-61,
            -61,-61,-60,-60,-60,-60,-60,-59,-59,-59,
            -58,-58,-58,-57,-57,-57,-56,-56,-56,-55,
            -55,-55,-54,-54,-53,-53,-53,-52,-52,-51,
            -51,-50,-50,-49,-49,-48,-48,-47,-47,-46,
            -46,-45,-44,-44,-43,-43,-42,-42,-41,-40,
            -40,-39,-39,-38,-37,-37,-36,-35,-35,-34,
            -33,-33,-32,-31,-31,-30,-29,-28,-28,-27,
            -26,-26,-25,-24,-23,-23,-22,-21,-20,-20,
            -19,-18,-17,-17,-16,-15,-14,-14,-13,-12,
            -11,-10,-10,-9,-8,-7,-7,-6,-5,-4,
            -3,-3,-2,-1,0,1,1,2,3,4,
            5,5,6,7,8,9,9,10,11,12,
            12,13,14,15,16,16,17,18,19,19,
            20,21,22,22,23,24,25,25,26,27,
            27,28,29,30,30,31,32,32,33,34,
            34,35,36,36,37,38,38,39,39,40,
            41,41,42,42,43,44,44,45,45,46,
            46,47,47,48,48,49,49,50,50,51,
            51,52,52,53,53,54,54,54,55,55,
            56,56,56,57,57,57,58,58,58,59,
            59,59,59,60,60,60,60,61,61,61,
            61,61,62,62,62,62,62,62,62,63,
            63,63,63,63,63,63,63,63,63,63};


        pointX = pointX +1;
        if( dir < 496)
        {
            pointYY = pointY;
            pointY = sinWave[dir]+75;
            dir = dir + 4;
        }
        else
        {
            pointYY = pointY;
            pointY = sinWave[496]+75;
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
