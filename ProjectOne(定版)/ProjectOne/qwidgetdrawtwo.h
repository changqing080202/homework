#ifndef QWIDGETDRAWTWO_H
#define QWIDGETDRAWTWO_H

#include <QWidget>
#include <QSerialPort>
#include <QPushButton>

class QWidgetDrawTwo : public QWidget
{
    Q_OBJECT
public:

    QTimer *timer;
    QTimer *timer2;
    QPixmap *pixmap;
    QSerialPort *serialPort;
    QPushButton  *btnSend;

    int pointX = 0;
    int pointY = 0;
    int pointYY = 0;
    int dir = 0;
    int cnt = 0;

    explicit QWidgetDrawTwo(QWidget *parent = nullptr);

    void drawWidget(void);
    void drawSinWave(QPainter *painter);
    void drawTriangle(QPainter *painter);
    void drawWave(QPainter *painter);
    void refresh();
    void drawPixmap();
    void sendPkg();


private:
    void paintEvent(QPaintEvent *event) override;

signals:

public slots:
};

#endif // QWIDGETDRAWTWO_H
