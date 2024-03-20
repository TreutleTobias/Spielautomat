#ifndef SPIELER_H
#define SPIELER_H
#include <QString>
#include <QList>
#include <QPushButton>

class Spieler
{
public:
    Spieler();
    Spieler(quint8 Anzahl_Spieler, quint8 max_Anzahl_Spieler,QStringList Liste_Spieler);
    QStringList getListe_Spieler() const;
    void setListe_Spieler(const QStringList &newListe_Spieler);

    quint8 getAnzahl_Spieler() const;
    void setAnzahl_Spieler(const quint8 &newAnzahl_Spieler);

    void Spieler_Liste_hinzufuegen(QString Name);

private:
    quint8 Anzahl_Spieler;
    quint8 max_Anzahl_Spieler;
    QStringList Liste_Spieler;
};

#endif // SPIELER_H
