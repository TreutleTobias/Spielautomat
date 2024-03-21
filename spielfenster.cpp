#include "spielfenster.h"
#include "ui_spielfenster.h"
#include "QPixmap"

Spielfenster::Spielfenster(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Spielfenster)
{
    ui->setupUi(this);

    QString imagePath = QCoreApplication::applicationFilePath() + "/images/background.png";
    QPixmap pix(imagePath);
    ui->SpinningWheel1->setPixmap(pix);
    ui->SpinningWheel2->setText(imagePath);
}

Spielfenster::~Spielfenster()
{
    delete ui;
}

void Spielfenster::on_Spiel_beenden_clicked()
{
    close();
}

