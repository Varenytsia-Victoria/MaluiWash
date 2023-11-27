#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "employee.h"
#include <QComboBox>
#include <QCheckBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Find the checkboxes
    checkBox = findChild<QCheckBox*>("checkBox");
    checkBox1 = findChild<QCheckBox*>("checkBox1");
    checkBox2 = findChild<QCheckBox*>("checkBox2");
    TypeComboBox = findChild<QComboBox*>("TypeComboBox");
    QStandardItemModel *model = new QStandardItemModel(this);
    ui->listView->setModel(model);

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_AddButton_clicked() {
    auto typeOfWork = TypeComboBox->currentText();

    QString name = "";
    if (checkBox->isChecked()) {
        name += "Бачало О.С.";
    }
    if (checkBox1->isChecked()) {
        if (!name.isEmpty()) {
            name += " ";
        }
        name += "Дзюбяк К.М.";
    }
    if (checkBox2->isChecked()) {
        if (!name.isEmpty()) {
            name += " ";
        }
        name += "Семеряк Н.О.";
    }

    auto time = QDateTime::currentDateTime();

    Employee employee(name, 0, typeOfWork, time);

    employees.push_back(employee);

    QStandardItem *item = new QStandardItem(employee.name + " - " + typeOfWork + " " + employee.time.toString());

    QStandardItemModel *model = dynamic_cast<QStandardItemModel*>(ui->listView->model());

    if (model) {
        model->appendRow(item);

    }
}

