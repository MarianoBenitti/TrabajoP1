#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer1 = new QTimer(this);

    connect(QTimer1, &QTimer::timeout,this,&MainWindow::OnQTimer1);
    cont=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnQTimer1(){
    if(ui->checkBox->isChecked()){ 
        if(cont==0){
            QTimer1->stop();
            ui->startstop->setText("START");
        }else{
            cont--;
        }

    }else{
         cont++;
         if(cont==10000){
             cont=0;
         }
    }

    ui->lcdNumber->display(QString("%1").arg(cont,5,10,QChar('0')));

}

void MainWindow::on_startstop_clicked()
{

    if(QTimer1->isActive()){
        QTimer1->stop();
        ui->startstop->setText("START");
    }else{
        QTimer1->start(20);
        ui->startstop->setText("STOP");
    }


}


void MainWindow::on_reset_clicked()
{
    QTimer1->stop();
    cont=0;
    ui->lcdNumber->display(QString("%1").arg(cont,5,10,QChar('0')));
}





void MainWindow::on_SetTemp_clicked()
{
    QString str;
    str=ui->lineEdit->text();
    if(str.toInt()>0){
        cont=str.toInt();
    }

    ui->lcdNumber->display(QString("%1").arg(cont,5,10,QChar('0')));
}

