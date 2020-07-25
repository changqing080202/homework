#include "qlabelclock.h"
#include <QDateTime>
#include <QTimer>
#include <QMouseEvent>

QLabelClock::QLabelClock(QWidget *parent) : QLabel(parent)
{
    this->setText(QDateTime::currentDateTime().toString("hh:mm:ss"));

    //创建定时器
    timer = new QTimer(parent);
    timer->start(100);

    //定时器timeout信号与时间刷新函数进行关联/绑定
    //信号与槽机制实现
    connect(timer, &QTimer::timeout, this, &QLabelClock::refresh);
}

void QLabelClock::refresh()
{
    if (1 == refreshEnable)
        //显示刷个内心文本内容
        this->setText(QDateTime::currentDateTime().toString("hh:mm:ss"));
}

    //鼠标按下时间数理函数
    //事件机制
void QLabelClock::mousePressEvent(QMouseEvent *ev)
{
    if (ev->buttons() == Qt::LeftButton)
    {
        if (this->refreshEnable)
            this->refreshEnable = 0;
        else
            this->refreshEnable = 1;
    }
}

