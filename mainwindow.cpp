#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDoubleValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->hpTxt->setValidator(new QDoubleValidator(0, 10000, 2, this));
    ui->wtTxt->setValidator(new QDoubleValidator(0, 1000000, 2, this));

}

MainWindow::~MainWindow()
{
    delete ui;
}

double getProgressValue(double r)//check the value for the progress bar
{
    if(r/10 < 100 && r >= 0)return r;
    else if(r/10 >= 100) return 100;
    else return 0;
}


void MainWindow::on_pushButton_clicked()
{
    if(ui->hpTxt->text() != "" && ui->wtTxt->text() != ""){//check
        ui->errTxt->setText("");
        double hp = ui->hpTxt->text().toInt();//get hp
        double wt = ui->wtTxt->text().toInt();//get weight in kg
        double rs = hp/(wt/1000);//get power to weight ratio
        //ui->label_2->setText(" "+QString::number(rs)+" ");
        ui->lcdNumber->display(rs);//set value to lcd display
        ui->progressBar->setValue(getProgressValue(rs));//set value to progress bar
    }
    else ui->errTxt->setText("Please enter both values.");

}



