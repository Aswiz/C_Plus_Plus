#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void showMesseges(int k,int x);
    int kPlusPlus(int k);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
