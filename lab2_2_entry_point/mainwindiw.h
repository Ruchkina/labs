#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTextStream>
#include <QVector>
#include "QStandardItemModel"
#include "QStandardItem"

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

    void on_fileDialog_clicked();

    void on_LoadData_clicked();

    void on_CalculateMetrics_clicked();

    //void on_drawing_clicked();

private:
    Ui::MainWindow *ui;
    double xBegin, xEnd, xStep, yBegin, yEnd, yStep;
    QVector<double> x,y;
    void DrawGraph (QVector <double> metrics, double Max, double Min);
    void DrawPoint(QVector <double> DataY, double Max, double Min);


};

namespace Ui {
    class MainWindow;
}

#endif // MAINWINDOW_H
