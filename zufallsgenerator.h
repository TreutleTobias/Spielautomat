#ifndef ZUFALLSGENERATOR_H
#define ZUFALLSGENERATOR_H
#include <QCoreApplication>
#include <QList>
#include <QString>
#include <QTime>

class Zufallsgenerator
{
public:
    Zufallsgenerator();
    QString selectRandomPlayer(QList<QString> multipliedNames, QList<QString> Spielerliste);
    QList<QString> multiplyNames(QList<QString> names);
    void shuffleList(QList<QString> &list);
    int8_t randomBild(int16_t RundenseitJackpot);
};

#endif // ZUFALLSGENERATOR_H
