#include "spieler.h"

Spieler::Spieler() {}

Spieler(quint8 Anzahl_Spieler, quint8 max_Anzahl_Spieler, QStringList Liste_Spieler)
//:    Anzahl(Anzahl_Spieler),max(max_Anzahl_Spieler),Liste(Liste_Spieler)
{
    Anzahl_Spieler = 0;
    max_Anzahl_Spieler = 8;
}

QStringList Spieler::getListe_Spieler() const
{
    return Liste_Spieler;
}

void Spieler::setListe_Spieler(const QStringList &newListe_Spieler)
{
    Liste_Spieler = newListe_Spieler;
}

quint8 Spieler::getAnzahl_Spieler() const
{
    return Anzahl_Spieler;
}

void Spieler::setAnzahl_Spieler(const quint8 &newAnzahl_Spieler)
{
    Anzahl_Spieler = newAnzahl_Spieler;
}

void Spieler::Spieler_Liste_hinzufuegen(QString Name) {
    // Holen Sie sich die aktuelle Liste der Spieler von dem aktuellen Objekt
    QStringList liste = getListe_Spieler();

    // Fügen Sie den neuen Namen zur Liste hinzu
    liste.append(Name);

    // Setzen Sie die aktualisierte Liste der Spieler für das aktuelle Objekt
    setListe_Spieler(liste);
}
