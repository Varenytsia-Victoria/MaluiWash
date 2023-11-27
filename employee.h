#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QtCore>

class Employee
{
public:
    Employee(const QString &name, double salary, const QString &typeOfWork, const QDateTime &time)
        : name(name)
        , salary(salary)
        , typeOfWork(typeOfWork)
        , time(time)
    {
    }

    QString name;
    double salary;
    QString typeOfWork;
    QDateTime time;
};

#endif // EMPLOYEE_H
