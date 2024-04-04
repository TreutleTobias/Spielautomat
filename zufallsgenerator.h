#ifndef ZUFALLSGENERATOR_H
#define ZUFALLSGENERATOR_H

#include <QList>
#include <QString>

class Zufallsgenerator
{
public:
    Zufallsgenerator();

    static QList<QString> multiplyNames(const QList<QString>& names);
    static QString selectRandomPlayer(const QList<QString>& multipliedNames);

    static int randomBild(int rundenseitJackpot);
};

#endif // ZUFALLSGENERATOR_H
