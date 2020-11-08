#include "PersonData.h"

QTextStream &operator>>(QTextStream &is, PersonData &personData)
{
    QStringList personDataLine = is.readLine().split(QRegExp(";|\\s"), QString::SplitBehavior::SkipEmptyParts);
    Q_ASSERT(personDataLine.size() == 3);
    personData.m_id = personDataLine[0].toInt();
    personData.m_userName = personDataLine[1];
    personData.m_phoneNumber = personDataLine[2];
    Q_ASSERT(QRegExp("^[+]{1}[0-9]{1}[(]{1}[0-9]{3,5}[)]{1}[0-9]{1,3}[-]{1}[0-9]{2}[-]{1}[0-9]{2}$")
             .exactMatch(personData.m_phoneNumber));
    return is;
}
