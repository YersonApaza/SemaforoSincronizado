#ifndef SEMAFORO_H
#define SEMAFORO_H

#include <QString>
#include <QList>
#include <QTime>
enum class enum_semaforo
{
    verde,ambar,rojo
};
class semaforo
{
private:
    //int *estado_semaforo;
    int tiempo_total=0;
    int verde=0;
    int ambar=0;
    int rojo=0;
    QList<int>* estado_color;
    int tiempo_recorrido = 0;
    int iterador_estado_color = 0;
    int comprobar_estado();
    bool segunda_ideracion =false;
public:
     QString avanzar();
     int estado_actual;
     semaforo(int tiempo,int ambar);
};
#endif // SEMAFORO_H
