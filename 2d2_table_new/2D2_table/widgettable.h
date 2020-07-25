#ifndef WIDGETTABLE_H
#define WIDGETTABLE_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql/QSqlDatabase>
#include <QLabel>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QTableView>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QSqlQueryModel>

class WidgetTable : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetTable(QWidget *parent = nullptr);
private:
    void login();
    void exit();
    QLabel *nameId;
    QLabel *passWord;

    QLabel *ID;
    QLabel *Name;
    QLabel *Sex;
    QSqlDatabase db;
    void sendCmd();
    QLineEdit *editId;
    QLineEdit *editName;
    QLineEdit *editSex;

    QLineEdit *editUsername;
    QLineEdit *editPassword;
    QPushButton *btnLogin;
    QPushButton *btnExit;
    QPushButton *btnview;
    QLabel *labelStatus;

    QPushButton  *btnSendCmd;
    QSqlQueryModel *patientsModel;
    QTableView *patientTableView;
    void refresh();
    void look();
};

#endif // WIDGETTABLE_H
