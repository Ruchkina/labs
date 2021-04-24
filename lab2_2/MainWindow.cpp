#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <fstream>
#include <QTextStream>
#include "MainWindow.h"
#include "QStandardItemModel"
#include "QStandardItem"
#include <QTextStream>
#include <iostream>
#include <fstream>
#include <QFileDialog>
#include <QStandardItemModel>
#include <QDialog>

#include "funces.h"

int numStruct;

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

void MainWindow::on_fileDialog_clicked()
{
    QString fn = QFileDialog::getOpenFileName(this, "Open file", "c:/", "*.csv");
    ui->label_3->setText(fn);
    numStruct = ReadFile(fn.toStdString());
    if ( numStruct == -1 ) {
        ui->F_ERR->setText("ERROR: open not file !!");
    }
    else { ui->F_ERR->setText("Open file"); }
}


void MainWindow::on_LoadData_clicked()
{
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Год" << "Регион" << "npg" << "birth_rate" << "death_rate" << "gdw" << "urbanization");

    Demog* ptrD;

    for (int i = 0; i < numStruct; i++) {
      ptrD = searchR(i, ui->comboBox->currentText().toStdString());
      if (ptrD) {
        int rowCount = ui->tableWidget->rowCount();
          ui->tableWidget->insertRow(rowCount);

          ui->tableWidget->setItem( rowCount, 0, new QTableWidgetItem(QString::number(ptrD->year)));
          ui->tableWidget->setItem( rowCount, 1, new QTableWidgetItem(QString::fromStdString(ptrD->region)));
          ui->tableWidget->setItem( rowCount, 2, new QTableWidgetItem(QString::number(ptrD->natural_population_growth)));
          ui->tableWidget->setItem( rowCount, 3, new QTableWidgetItem(QString::number(ptrD->birth_rate)));
          ui->tableWidget->setItem( rowCount, 4, new QTableWidgetItem(QString::number(ptrD->death_rate)));
          ui->tableWidget->setItem( rowCount, 5, new QTableWidgetItem(QString::number(ptrD->general_demographic_weight)));
          ui->tableWidget->setItem( rowCount, 6, new QTableWidgetItem(QString::number(ptrD->urbanization)));
      }
    }
}


void MainWindow::on_CalculateMetrics_clicked()
{
    double Max, Min, Med;
    Max = findMax (ui->comboBox->currentText().toStdString(), ui->comboBox_2->currentText().toStdString(), numStruct);
    Min = findMin (ui->comboBox->currentText().toStdString(), ui->comboBox_2->currentText().toStdString(), numStruct);
    Med = findMed (ui->comboBox->currentText().toStdString(), ui->comboBox_2->currentText().toStdString(), numStruct);

    ui->label_6->setText(QString::number(Max));
    ui->label_7->setText(QString::number(Min));
    ui->label_9->setText(QString::number(Med));

    DrawPoint(DataForDraw(ui->comboBox->currentText().toStdString(), ui->comboBox_2->currentText().toStdString()), Max, Min);
    DrawGraph(DataForDraw(ui->comboBox->currentText().toStdString(), ui->comboBox_2->currentText().toStdString()), Max, Min);

}



void MainWindow::DrawGraph(QVector <double> DataY, double Max, double Min)
{
    xBegin = 1990;
    xEnd = 2018;
    yBegin = Min - 2;
    yEnd = Max + 2;

    QVector <double> DataX;

    for(int i = 0; i < 2017 - 1990; i++)
        DataX.push_back(i + 1990);

    ui->widget->addGraph();
    ui->widget->graph(1)->setData(DataX, DataY);

    ui->widget->xAxis->setLabel("Год");
    ui->widget->yAxis->setLabel("Данные");

    ui->widget->xAxis->setRange(xBegin, xEnd);
    ui->widget->yAxis->setRange(yBegin, yEnd);
    ui->widget->replot();

    DataX.clear();
    DataY.clear();

}

void MainWindow::DrawPoint(QVector <double> DataY, double Max, double Min)
{
    int yearMax, yearMin;
    QVector<double> x(1), y(1);

    for(int i = 0; i < 2017 - 1990; i++)
    {
        if (DataY.at(i) == Min)
            yearMin = i + 1990;
        if (DataY.at(i) == Max)
            yearMax = i + 1990;
    }

    y.push_back(Min);
    y.push_back(Max);
    x.push_back(yearMin);
    x.push_back(yearMax);

    ui->widget->addGraph();
    ui->widget->graph(0)->setData(x, y);

    ui->widget->graph(0)->setPen(QColor(50, 50, 50, 255));
    ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->widget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 10));

    ui->widget->replot();

    x.clear();
    y.clear();
}
