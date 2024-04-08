#include "zufallsgenerator.h"
#include <cstdlib>
#include <ctime>

Zufallsgenerator::Zufallsgenerator() {}

//Kreieren eines Pools in dem jeder Name vier mal vorkommt
QList<QString> Zufallsgenerator::multiplyNames(const QList<QString>& names) {
    QList<QString> multipliedNames;
    for (const QString &name : names) {
        for (int i = 0; i < 4; ++i) {
            multipliedNames.append(name);
        }
    }
    std::srand(std::time(nullptr));
    std::random_shuffle(multipliedNames.begin(), multipliedNames.end());
    return multipliedNames;
}
//Auswählen eines Spielers aus des Pools ohne Zurücklegen um besser verteilte Gewinner zu erhalten
QString Zufallsgenerator::selectRandomPlayer(const QList<QString>& multipliedNames) {
    int index = std::rand() % multipliedNames.size();
    QString selectedPlayer = multipliedNames[index];
    return selectedPlayer;
}
//Die Random Bild Methode wählt je nachdem wie lange kein Jackpot mehr kam die wahrscheinlichkeit für einen Jackpot
int Zufallsgenerator::randomBild(int rundenseitJackpot) {
    int array[4][20] = {{1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5},
                        {1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5},
                        {1, 1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5},
                        {1, 1, 1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5}};
    int i=0;
    if(rundenseitJackpot <= 10){i = 0;}
    else if(rundenseitJackpot > 10 && rundenseitJackpot <= 20){i = 1;}
    else if(rundenseitJackpot > 20 && rundenseitJackpot <= 30){i = 2;}
    else if(rundenseitJackpot > 30){i = 3;}

    int index = rand() % 20;
    return array[i][index];
}







