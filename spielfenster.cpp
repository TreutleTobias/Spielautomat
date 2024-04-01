#include "spielfenster.h"
#include "ui_spielfenster.h"
#include "QPixmap"
#include "QDir"
#include "QFileInfo"
#include "zufallsgenerator.h"

int16_t rundenseitJackpot = 0;

Spielfenster::Spielfenster(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Spielfenster)
{
    ui->setupUi(this);

    QDir dir("../");
    QString s = dir.absoluteFilePath("Spielautomat/images/background.png");
    QPixmap image(s);

    //Label1
    ui->SpinningWheel1->setPixmap(image);
    ui->SpinningWheel1->setScaledContents(true);
    ui->SpinningWheel1->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

    //Label2
    ui->SpinningWheel2->setPixmap(image);
    ui->SpinningWheel2->setScaledContents(true);
    ui->SpinningWheel2->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

    //Label3
    ui->SpinningWheel3->setPixmap(image);
    ui->SpinningWheel3->setScaledContents(true);
    ui->SpinningWheel3->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

    //background Label
    QDir spielfenster_rel_pfad("../");
    QString spielfenster_pfad = dir.absoluteFilePath("Spielautomat/images/mainpage.png");
    QPixmap spielfenster(spielfenster_pfad);

    ui->Background_Label->setPixmap(spielfenster);
    ui->Background_Label->setScaledContents(true);
    ui->Background_Label->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
}

Spielfenster::~Spielfenster()
{
    delete ui;
}

void Spielfenster::on_Spiel_beenden_clicked()
{
    close();
}




void Spielfenster::on_Spin_button_clicked()
{
    int8_t bildauswahl1;
    bildauswahl1 = Zufallsgenerator::randomBild(rundenseitJackpot);

}

