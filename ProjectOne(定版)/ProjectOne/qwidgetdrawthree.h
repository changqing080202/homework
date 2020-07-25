#ifndef QWIDGETDRAWTHREE_H
#define QWIDGETDRAWTHREE_H

#include <QWidget>

class QWidgetDrawThree : public QWidget
{
    Q_OBJECT
public:
    QTimer *timer;
    QPixmap *pixmap;
    int pointX = 0;
    int pointY = 0;
    int dir = 0;
    int cnt = 0;
    explicit QWidgetDrawThree(QWidget *parent = nullptr);
    void drawWidget(void);
    void drawTriangle(QPainter *painter);
    void drawPixmap();
    void refresh();

private:
    void paintEvent(QPaintEvent *event) override;


signals:

public slots:
};

#endif // QWIDGETDRAWTHREE_H
