#ifndef SPIELFENSTER_H
#define SPIELFENSTER_H

#include <QDialog>

namespace Ui {
class Spielfenster;
}

class Spielfenster : public QDialog
{
    Q_OBJECT

public:
    explicit Spielfenster(QWidget *parent = nullptr);
    ~Spielfenster();

private slots:
    void on_Spiel_beenden_clicked();

    void on_Spin_button_clicked();

private:
    Ui::Spielfenster *ui;
};

#endif // SPIELFENSTER_H
