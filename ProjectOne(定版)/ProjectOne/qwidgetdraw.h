#ifndef QWIDGETDRAW_H
#define QWIDGETDRAW_H

#include <QWidget>
#include <QSerialPort>

class QWidgetDraw : public QWidget
{
    Q_OBJECT
public:
    QTimer *timer;
    QTimer *timer2;
    QPixmap *pixmap;
    QSerialPort *serialPort;

    int pointX = 0;
    int pointY = 0;
    int pointYY = 0;
    int dir = 0;
    int cnt = 0;

    explicit QWidgetDraw(QWidget *parent = nullptr);

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

#endif // QWIDGETDRAW_H
