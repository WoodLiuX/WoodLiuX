#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPushButton>
#include<QLabel>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QMainWindow w1;
    QMainWindow w2;
     QMainWindow w3;
     void  updateweight();
     void updategrowday();
     void updatenumber();
     QLabel *label;
     void load_file();
     void chuanran();
private slots:



    void on_lineEdit1_editingFinished();

    void on_lineEdit_editingFinished();

    void on_lineEdit2_editingFinished();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
