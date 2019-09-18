#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <semaforo.h>
#include <QList>
#include <QMessageBox>
#include <QImage>
#include <QThread>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mis_semaforos = new QList<semaforo*>;
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    int temp = ui->lineEdit->text().toInt();
    semaforo *tmp_semaforo;
    tmp_semaforo = new semaforo(temp,5);
    mis_semaforos->append(tmp_semaforo);

}
bool MainWindow::son_iguales(QList<QString> *tmp){
    QString Valor_verde = "0v";
    for (int i=0;i<tmp->size();i++) {
        if(tmp->at(i).size()!=2){
            return false;
        }
    }
    QString cambio = Valor_verde;
    for (int i=0;i<tmp->size();i++) {
        if(cambio != tmp->at(i)){
            return false;
       }
    }
    return true;
}
void MainWindow::on_pushButton_2_clicked()
{
    for (int i = 0; i < 7200;i++) {
        on_prueba_semaforo_clicked();
        if(encontrado == true){
            return;
        }
    }
}

void MainWindow::on_prueba_semaforo_clicked()
{
    QString temp_rpta= "";
    QString tmp_int = "";
   tiempo_tmp++;

       for (int j = 0;j < mis_semaforos->size();j++) {//cantidad_semaforos
           sem_tmp = mis_semaforos->at(j)->avanzar();
               //ui->listWidget->clear();
               zona_comparar->append(sem_tmp);
               temp_rpta.append(sem_tmp+" ");
       }
       tmp_int = QString::number(tiempo_tmp);
       temp_rpta.append(tmp_int);
       ui->lcdNumber->display(tiempo_tmp);
       ui->listWidget->addItem(temp_rpta);
       if(son_iguales(zona_comparar)){
           tmp = QString::number(tiempo_tmp);
           int minu_int = tiempo_tmp/60;
           int segun_int = tiempo_tmp%60;

           QString minu =QString::number(minu_int);
           QString seg = QString::number(segun_int);
           ui->statusBar->showMessage("SI Concuerda segundo " + tmp + " Minutos :" + minu + " y segundo " +seg ,20000);
           encontrado = true;
           alert.show();
           return;
       }
       zona_comparar->clear();
       temp_rpta.clear();

}



