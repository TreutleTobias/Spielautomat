#include "Spielerliste.h"
#include <cstdlib>
#include <ctime>

Spielerliste::Spielerliste() {


}

QList<QString> Liste;

void Spielerliste::spieler_hinzufuegen(const QString& name){

        Liste.append(name);

}
QList<QString> Spielerliste::get_Spielerliste(){

    return Liste;

}

QString Spielerliste::get_Spielername(int index){

    return Liste.at(index);
}

void Spielerliste::liste_loeschen(){

    Liste.clear();
}
