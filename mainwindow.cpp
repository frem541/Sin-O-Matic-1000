#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "math_utility.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);    
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_generate_clicked()
{
    const int ARGUMENT_COLUMN = 0;
    const int VALUE_COLUMN = 1;
    double start = ui->doubleSpinBox_start->value();
    double end = ui->doubleSpinBox_end->value();
    double step = ui->doubleSpinBox_step->value();
    AngleType angleType = (ui->radioButton_degrees->isChecked() ? DEG : RAD);
    std::vector<double> results;
    computeSin(start, end, step, angleType, results);

    ui->tableWidget_results->setRowCount(results.size());
    for (size_t row = 0; row < ui->tableWidget_results->rowCount(); row++)
    {
        QString  argument = "sin("+QString::number(start+step*row, 'f', ui->spinBox_argumentPrecision->value())+(angleType == DEG ? "°)" : ")");
        QString  value = QString::number(results.at(row), 'f', ui->spinBox_valuePrecision->value());
        ui->tableWidget_results->setItem(row, ARGUMENT_COLUMN, new QTableWidgetItem(argument));
        ui->tableWidget_results->setItem(row, VALUE_COLUMN, new QTableWidgetItem(value));
    }
}


void MainWindow::on_spinBox_argumentPrecision_valueChanged(int arg1)
{
    ui->doubleSpinBox_start->setDecimals(ui->spinBox_argumentPrecision->value());
    ui->doubleSpinBox_end->setDecimals(ui->spinBox_argumentPrecision->value());
    ui->doubleSpinBox_step->setDecimals(ui->spinBox_argumentPrecision->value());
    ui->doubleSpinBox_step->setSingleStep(pow(10, (-1)*ui->spinBox_argumentPrecision->value()));
}

