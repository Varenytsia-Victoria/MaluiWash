#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employee.h"
#include <QMainWindow>
#include <QComboBox>
#include <QCheckBox>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_AddButton_clicked();


private:
    Ui::MainWindow *ui;
    QVector<Employee> employees;
    QStandardItem *item;
    QCheckBox* checkBox;
    QCheckBox* checkBox1;
    QCheckBox* checkBox2;
    QComboBox* TypeComboBox;
    QAbstractItemModel *model;

};
#endif // MAINWINDOW_H
