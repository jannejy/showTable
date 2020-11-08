#ifndef PERSONDATAMODEL_H
#define PERSONDATAMODEL_H

#include <QAbstractTableModel>
#include "PersonData.h"

//Class represents model data of table

class PersonDataModel final: public QAbstractTableModel
{
    Q_OBJECT

    enum TableColumns
    {
       USER_ID,
       USER_NAME,
       PHONE_NUMBER,
       COLUMNS_COUNT
    };

    enum TableDataRoles
    {
        TableDataRole = Qt::UserRole + 1,
        HeadingRole
    };

public:
    explicit PersonDataModel(QObject *parent = nullptr): QAbstractTableModel(parent) { }

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

    // read the file data
    Q_INVOKABLE void openFile(const QUrl& fileName);
    // clear data in the table
    Q_INVOKABLE void clear();

private:
    PersonDataList m_persondataList;
    const QStringList m_headers {"User ID", "User Name", "Phone Number"};
};

#endif // PERSONDATAMODEL_H
