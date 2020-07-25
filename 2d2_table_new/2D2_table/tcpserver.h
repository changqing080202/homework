#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QDebug>
#include <QMessageBox>
#include <QMetaType>
#include <QString>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDataStream>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QTextBrowser>
#include "widgetdraw.h"
#include "bufdata.h"


#define SOCKETCLIENTBUFSIZE 1024
class TcpServer : public QWidget
        // 必须继承QWidget，否则无法使用connect
{
    Q_OBJECT
public:
    TcpServer(QWidget *parent = nullptr);


private slots:
    void acceptConnection(void);
    void readClient(void);
    void TcpServerListen(void);
    void TextBrowerClear(void);

private:
    QTcpServer* mQTcpServer = nullptr;
    QTcpSocket* mSocketClient= nullptr;
    QLineEdit *editId= nullptr;
    QLineEdit *editName= nullptr;
    QLineEdit *editSex= nullptr;
    QPushButton *btnSendCmd= nullptr;
    QPushButton *btnClear= nullptr;
    QPushButton *btnSend= nullptr;
    QTextBrowser *msgBrowser= nullptr;
    WidgetDraw *draw = nullptr;
    bool btnflags = 1;
};

#endif // TCPSERVER_H
