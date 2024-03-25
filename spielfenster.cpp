#include "spielfenster.h"
#include "ui_spielfenster.h"
#include "QPixmap"
#include "QDir"
#include "QFileInfo"

Spielfenster::Spielfenster(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Spielfenster)
{
    ui->setupUi(this);

    QDir dir("../");
    QString s = dir.absoluteFilePath("Spielautomat/images/background.png");

    QPixmap image(s);
    ui->SpinningWheel1->setPixmap(image);
    ui->SpinningWheel2->setText(s);
}

Spielfenster::~Spielfenster()
{
    delete ui;
}

void Spielfenster::on_Spiel_beenden_clicked()
{
    close();
}

