#include "tcpserver.h"

TcpServer::TcpServer(QWidget *parent) : QWidget(parent)
{
    //创建ID编辑框
    this->editId=new QLineEdit(this);
    this->editId->move(50,25);
    this->editId->resize(100,25);
    this->editId->setText("127.0.0.1");
    //创建ID标签框
    QLabel *textId = new QLabel(this);
    textId->setText("IP:");
    textId->move(20,25);
    textId->resize(25,25);

    //创建端口号编辑框
    this->editName=new QLineEdit(this);
    this->editName->move(220,25);
    this->editName->resize(75,25);
    this->editName->setText("10001");
    //创建端口号标签框
    QLabel *textName = new QLabel(this);
    textName->move(175,25);
    textName->resize(75,25);
    textName->setText("Port:");

    //创建侦听按钮
    this->btnSendCmd=new QPushButton(this);
    this->btnSendCmd->move(330,25);
    this->btnSendCmd->setText("侦听");

    //创建清屏按钮
    this->btnClear = new QPushButton(this);
    this->btnClear->move(450,25);
    this->btnClear->setText("刷新");

    draw = new WidgetDraw(this);
    draw->resize(600,150);
    draw->move(50,70);

    connect(this->btnSendCmd,&QPushButton::clicked,this,TcpServer::TcpServerListen);
    connect(this->btnClear,&QPushButton::clicked,this,TcpServer::TextBrowerClear);
}

void TcpServer::TcpServerListen()
{
    if(btnflags)
    {
        mQTcpServer = new QTcpServer(); // 构造QTcpServer
        if(mQTcpServer->listen(QHostAddress(this->editId->text()), this->editName->text().toInt()))// 监听本机port端口
        {
            connect(mQTcpServer, SIGNAL(newConnection()), this, SLOT(acceptConnection()));

            qDebug()<<"Server is listening on "<<QString::number(this->editName->text().toInt());

            this->btnSendCmd->setText("停止");
            btnflags = 0;
        }
        else
        {
            QMessageBox::critical(this,"QTCPServer",QString("Unable to start the server: %1.").arg(mQTcpServer->errorString())); // 报错
            mQTcpServer->close();

        }
    }
    else
    {
        mQTcpServer->close();
        delete mQTcpServer;
        mQTcpServer = nullptr;
        this->btnSendCmd->setText("侦听");
        btnflags = 1;
    }
}

void TcpServer::acceptConnection(void)
{
    mSocketClient = mQTcpServer->nextPendingConnection();
    connect(mSocketClient, SIGNAL(readyRead()), this, SLOT(readClient()));
}

void TcpServer::readClient()
{

    QByteArray rxbuf = mSocketClient->readAll(); // 取出客户Client中的所有数据
    bool ok;
    lastdata = bufdata;
    bufdata = rxbuf.toFloat(&ok);
    draw ->refresh();
}

void TcpServer::TextBrowerClear()
{
    lastdata = 0;
    bufdata = 0;
    draw->erase();
}
