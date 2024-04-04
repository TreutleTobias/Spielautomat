#ifndef SPIELFENSTER_H
#define SPIELFENSTER_H

#include <QDialog>
#include <QList>
#include "ui_spielfenster.h"


class Spielfenster : public QDialog
{
    Q_OBJECT

public:
    explicit Spielfenster(QWidget *parent = nullptr);

private slots:
    void on_Spiel_beenden_clicked();
    void on_Spin_button_clicked();

private:
    Ui::Spielfenster *ui;

};

#endif // SPIELFENSTER_H
