#include <QApplication>

#include "widgettable.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WidgetTable *login = new WidgetTable();

    login->resize(820,390);
    login->setWindowTitle("第6组医生工作站");
    login->show();
    return a.exec();
}
