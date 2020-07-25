#ifndef TCPCLIENT_H
#define TCPCLIENT_H
#include <QTimer>
#include <QWidget>
#include <QString>
#include <QTcpServer>
#include <QTcpSocket>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>


class TcpClient : public QWidget
{
    Q_OBJECT
public:
    explicit TcpClient(QWidget *parent = nullptr);
    void TcpClientLink(void);

private:
    QTcpSocket *mClient;
    QLineEdit *editId;
    QLineEdit *editName;
//    QLineEdit *editSex;
    QPushButton  *btnSendCmd;
    QTimer *timer;
    int cnt = 0;
    void Send(void);


};

#endif // TCPCLIENT_H
