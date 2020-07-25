#ifndef QWIDGETDRAW_H
#define QWIDGETDRAW_H

#include <QWidget>

class QWidgetDraw_3 : public QWidget
{
    Q_OBJECT
public:

    QTimer *timer;
    QPixmap *pixmap;
    int pointX = 0;
    int pointY = 0;
    int dir = 0;
    int cnt = 0;
    explicit QWidgetDraw_3(QWidget *parent = nullptr);
    void drawWidget(void);
    void drawTriangle(QPainter *painter);
    void drawPixmap();
    void refresh();

private:
    void paintEvent(QPaintEvent *event) override;


signals:

public slots:
};

#endif // QWIDGETDRAW_H
