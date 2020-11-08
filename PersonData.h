#ifndef PERSONDATA_H
#define PERSONDATA_H

#include <QTextStream>
#include <QString>
#include <QList>

// Class represents structure of one person data: id, name and phone number

class PersonData final
{
    // Reading from file and saving data
    friend QTextStream &operator>>(QTextStream &is, PersonData &personData);

public:
    PersonData() = default;
    PersonData(int id, const QString& userName, const QString& phoneNumber):
            m_id(id), m_userName(userName), m_phoneNumber(phoneNumber) {}
    int getId() const noexcept { return m_id; }
    QString getUserName() const noexcept { return m_userName; }
    QString getPhoneNumber() const noexcept { return m_phoneNumber; }

private:
    int m_id;
    QString m_userName;
    QString m_phoneNumber;
};

using PersonDataList = QList<PersonData>;

QTextStream &operator>>(QTextStream &is, PersonData &personData);

#endif // PERSONDATA_H
