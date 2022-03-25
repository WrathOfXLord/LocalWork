#include "mainwindow.hpp"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // ui->progressBar->setRange(0, 100);
    ui->horizontalSlider->setRange(0, 100);
    ui->progressBar->reset();
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
            ui->progressBar, SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::checkValue() {
    if(ui->progressBar->value() > 99) {
        disconnect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
                ui->progressBar, SLOT(setValue(int)));
        delete ui->horizontalSlider;
        return true;
    }
    return false;
}

void MainWindow::on_progressBar_valueChanged(int value)
{
    this->checkValue();
}
