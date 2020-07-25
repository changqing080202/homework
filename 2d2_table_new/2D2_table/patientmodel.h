#ifndef PATIENTMODEL_H
#define PATIENTMODEL_H

#include <QObject>
#include <QStandardItemModel>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlQuery>
class PatientModel : public QSqlQueryModel
{
public:
    explicit PatientModel(QSqlQueryModel *parent = nullptr);
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setName(int id, QString name);
    bool setSex(int id, QString sex);
    bool setData(const QModelIndex &index, const QVariant &value, int /* role */);

};

#endif // PATIENTMODEL_H
