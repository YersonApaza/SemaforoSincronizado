#include "semaforo.h"

QString semaforo::avanzar()
{
    tiempo_recorrido++;
    tiempo_total++;
    QString cambio = "";
    QString temp_at1;
    if (tiempo_recorrido == (estado_color->at(iterador_estado_color))){
            if(iterador_estado_color == 2){
                iterador_estado_color = 0;
                segunda_ideracion = true;

            }else {
                iterador_estado_color++;
            }
        tiempo_recorrido = 0;
    }
    if(segunda_ideracion){
        cambio = "v";
    }
    this->estado_actual = iterador_estado_color;
    QString tmp = QString::number(iterador_estado_color)+cambio;

    return tmp;
}
int semaforo::comprobar_estado()
{

}

semaforo::semaforo(int tiempo, int ambar)
{
    this->verde= tiempo-ambar;
    this->rojo = tiempo;
    this->ambar = ambar;
    estado_color = new QList <int>;
    estado_color->append(verde);
    estado_color->append(ambar);
    estado_color->append(rojo);
}
