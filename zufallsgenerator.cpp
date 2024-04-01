#include "zufallsgenerator.h"
#include "math.h"
#include <QCoreApplication>
#include <QList>
#include <QString>
#include <QTime>
//#include <cstdlib>

void shuffleList(QList<QString> &list) { //shuffle Funktion wird die Adresse einer Liste übergeben und mischt diese durch

    srand(QTime::currentTime().msec());     //Seed
    for (int i = 0; i < list.size(); ++i) {
        int j = rand() % list.size();
        list.swapItemsAt(i,j);
    }
}

QList<QString> multiplyNames(QList<QString> names) {
    QList<QString> multipliedNames;
    for (const QString &name : names) {
        for (int i = 0; i < 4; ++i) {
            multipliedNames.append(name);
        }
    }
    shuffleList(multipliedNames);
    return multipliedNames;
}

QString selectRandomPlayer(QList<QString> multipliedNames, QList<QString> Spielerliste) {
    if(multipliedNames.isEmpty()){
        multipliedNames = multiplyNames(Spielerliste);
    }
    int index = rand() % multipliedNames.size();
    QString selectedPlayer = multipliedNames.takeAt(index);
    return selectedPlayer;
}

int8_t randomBild(int16_t RundenseitJackpot){
    int array[4][20] = {{1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5},
                        {1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5},
                        {1, 1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5},
                        {1, 1, 1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5}};
    int i=0;
    if(RundenseitJackpot <= 10){i = 0;}
    else if(RundenseitJackpot > 10 && RundenseitJackpot <= 20){i = 1;}
    else if(RundenseitJackpot > 20 && RundenseitJackpot <= 30){i = 2;}
    else if(RundenseitJackpot > 30){i = 3;}

    int index = rand() % 20;
    return array[i][index];
}


Zufallsgenerator::Zufallsgenerator() {}




