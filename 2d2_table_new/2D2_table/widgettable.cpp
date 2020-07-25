#include "widgettable.h"
#include "patientmodel.h"
#include "tcpserver.h"
WidgetTable::WidgetTable(QWidget *parent) : QWidget(parent)
{
    this->editId = new QLineEdit(this);
    this->editName = new QLineEdit(this);
    this->editSex = new QLineEdit(this);
    this->ID = new QLabel(this);
    this->Name = new QLabel(this);
    this->Sex = new QLabel(this);
    this->editUsername = new QLineEdit(this);
    this->editPassword = new QLineEdit(this);

    this->btnSendCmd= new QPushButton(this);
    this->btnSendCmd->setText("录入病人信息");
    this->btnLogin = new QPushButton(this);
    this->btnLogin->setText("登录");
    this->btnExit = new QPushButton(this);
    this->btnExit->setText("退出");

    ID->setText("病人ID（可不输）：");
    Name->setText("姓名：");
    Sex->setText("性别：");

    ID->resize(100,20);
    ID->move(270,10);
    Name->resize(80,20);
    Name->move(330,40);
    Sex->resize(80,20);
    Sex->move(330,70);
    this->editId->move(380,10);
    this->editName->move(380,40);
    this->editSex->move(380,70);
    this->btnSendCmd->move(380,100);
    this->editUsername->move(70,10);
    this->editPassword->move(70,40);
    this->btnLogin->move(70,70);
    this->btnExit->move(150,70);

    this->nameId = new QLabel(this);
    nameId->resize(40,20);
    nameId->move(10,10);
    nameId->setText("用户名：");
    this->passWord = new QLabel(this);
    passWord->resize(40,20);
    passWord->move(10,40);
    passWord->setText("密码：");


    this->labelStatus = new QLabel(this);
    this->labelStatus->resize(200,15);
    this->labelStatus->move(230,70);

    this->btnview = new QPushButton(this);
    this->btnview->move(70,110);
    this->btnview->resize(80,20);
    this->btnview->setText("查看病人信息");

    db = QSqlDatabase::addDatabase("QMYSQL");

    connect(this->btnLogin,&QPushButton::clicked,this,&WidgetTable::login);
    connect(this->btnExit,&QPushButton::clicked,this,&WidgetTable::exit);
    connect(this->btnview,&QPushButton::clicked,this,&WidgetTable::look);

    db.setHostName("localhost");
    db.setDatabaseName("medical_monitor");

    db.setUserName("doctor");
    db.setPassword("123456");

    QSqlQuery query(db);

    bool ok = db.open();
    if(ok)
    {
        qDebug("打开成功");

        query.exec("DELETE FROM doctor WHERE uid = 'doctor2';INSERT INTO medical_monitor.doctor(uid, name, mobile) VALUES('doctor2','张无忌','13987654321');");
    }
    else
    {
        qDebug("打开失败");

    }

    patientsModel = new PatientModel();
    patientTableView = new QTableView(this);
//    patientsModel->setQuery("SELECT * FROM patient");
    patientsModel->setQuery("SELECT * "
                            "FROM patient, device, device_patient "
                            "WHERE patient.id = device_patient.patient_id and device.dev_id = device_patient.dev_id");
    patientTableView->setModel(patientsModel);
    patientTableView->move(10,150);
    patientTableView->setMaximumWidth(800);
    patientTableView->setMinimumWidth(800);
    connect(this->btnSendCmd,&QPushButton::clicked,this,WidgetTable::sendCmd);
}

void WidgetTable::look()
{
    TcpServer *mTcpServer = new TcpServer();
    mTcpServer->setWindowTitle("第6组");
    mTcpServer->resize(800,250);
    mTcpServer->show();
}

void WidgetTable::login()
{
    // 配置服务器地址，这里用的是本地地址，这里也可以是远程的IP或域名
    db.setHostName("localhost");
    // 配置数据库名字
    db.setDatabaseName("medical_monitor");
    // 从窗口读取用户名密码
    db.setUserName(this->editUsername->text());
    db.setPassword(this->editPassword->text());
    // 用open方法打开与数据的连接
    bool ok = db.open();
    if(ok)
    {
        qDebug("数据库打开成功");
        this->labelStatus->setText("登录成功");
    }
    else
    {
        qDebug("数据库打开失败");
        this->labelStatus->setText("登录失败");
    }
}

void WidgetTable::exit()
{
    if(db.isOpen())
    {
        db.close();
    }
    this->labelStatus->setText("已退出登录");
}

void WidgetTable::sendCmd()
{
    qDebug()<<"todo";
    QSqlQuery query(db);
    query.prepare("INSERT INTO patient (name, sex) "
                  "VALUES(:name, :sex)");
    query.bindValue(":name", this->editName->text());
    query.bindValue(":sex", this->editSex->text());
    bool cmdOk = query.exec();
    if(cmdOk)
    {
        qDebug()<<"发送成功";
    }
    else
    {
        qDebug()<<query.lastError();
    }
}

void WidgetTable::refresh()
{
    this->update();
}
