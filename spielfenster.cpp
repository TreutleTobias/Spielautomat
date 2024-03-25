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
}

Spielfenster::~Spielfenster()
{
    delete ui;
}

void Spielfenster::on_Spiel_beenden_clicked()
{
    close();
}

