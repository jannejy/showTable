#include "PersonDataModel.h"
#include <QFileInfo>

int PersonDataModel::rowCount(const QModelIndex &) const
{
    return m_persondataList.size() + 1;
}

int PersonDataModel::columnCount(const QModelIndex &) const
{
    return COLUMNS_COUNT;
}

QVariant PersonDataModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    switch(role)
    {
        case TableDataRole:
        {
            if (index.row() == 0)
            {
                return m_headers.at(index.column());
            }

            const auto& currentData = m_persondataList.at(index.row() - 1);
            switch(index.column())
            {
                case TableColumns::USER_ID:
                    return currentData.getId();
                case TableColumns::USER_NAME:
                    return currentData.getUserName();
                case TableColumns::PHONE_NUMBER:
                    return currentData.getPhoneNumber();
                default:
                    break;
            }
            break;
        }

        case HeadingRole:
        {
            return index.row() == 0;
        }
    }

    return QVariant();
}

QHash<int, QByteArray> PersonDataModel::roleNames() const
{
    return { {TableDataRoles::TableDataRole, "tableData"},
        {TableDataRoles::HeadingRole, "header"} };
}

void PersonDataModel::openFile(const QUrl& fileName)
{
    QFile file(fileName.toLocalFile());
    if (!file.open(QFile::ReadOnly))
    {
        return;
    }

    QTextStream ts(&file);
    while (!ts.atEnd())
    {
        PersonData data;
        ts >> data;

        beginInsertRows(QModelIndex(), rowCount(), rowCount());
        m_persondataList.push_back(data);
        endInsertRows();
    }
}

void PersonDataModel::clear()
{
    if (m_persondataList.size() > 0)
    {
        beginRemoveRows(QModelIndex(), 1, rowCount() - 1);
        m_persondataList.clear();
        endRemoveRows();
    }
}
