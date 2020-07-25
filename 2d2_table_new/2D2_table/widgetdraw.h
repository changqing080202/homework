#ifndef WIDGETDRAW_H
#define WIDGETDRAW_H

#include <QWidget>
#include <QTimer>

class WidgetDraw : public QWidget
{
public:
    QTimer *timer;
    QPixmap *pixmap;
    int pointX = 0;
    int pointY = 0;
    int temp = 0;
    explicit WidgetDraw(QWidget *parent = nullptr);
    void drawPixmap();
    void refresh();
    void drawWidget(void);
    void erase();
private:
    void paintEvent(QPaintEvent *event) override;

    //void drawPixmap(int ecgdata,int lastdata);
    //void drawWidget(void);
    void drawData(QPainter *painter);
};

#endif // WIDGETDRAW_H
