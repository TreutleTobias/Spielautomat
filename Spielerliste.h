#ifndef SPIELERLISTE_H
#define SPIELERLISTE_H

#include <QList>
#include <QString>

class Spielerliste
{
public:
    Spielerliste();

    void spieler_hinzufuegen(QString& name);
    QList<QString> get_Spielerliste();
    QString get_Spielername(int index);

private:
    QList<QString> spielerliste;




};

#endif // SPIELERLISTE_H
