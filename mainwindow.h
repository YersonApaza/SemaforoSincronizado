#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <semaforo.h>
#include <QMessageBox>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool son_iguales(QList <QString> *tmp);
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void on_prueba_semaforo_clicked();

private:
    bool encontrado = false;
    Ui::MainWindow *ui;
    QList<semaforo*>* mis_semaforos;
    QMessageBox alert;
    QString tmp;
    QString sem_tmp;
    int tiempo = 10000;
    int tiempo_tmp = 0;
    QStringList *zona_comparar = new QStringList;
};

#endif // MAINWINDOW_H
