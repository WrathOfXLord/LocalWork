#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool checkValue();
private slots:
    void on_progressBar_valueChanged(int value);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_HPP
