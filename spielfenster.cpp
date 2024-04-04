#include "spielfenster.h"
#include "ui_spielfenster.h"
#include "zufallsgenerator.h"
#include "mainwindow.h"
#include "QPixmap"
#include "QDir"
#include "QFileInfo"


int rundenseitJackpot = 0;

Spielfenster::Spielfenster(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Spielfenster)
{
    ui->setupUi(this);

    //background Label
    QDir dir("../"); // Hier wird 'dir' deklariert
    QString spielfenster_pfad = dir.absoluteFilePath("Spielautomat/images/mainpage.png");
    QPixmap spielfenster(spielfenster_pfad);

    ui->Background_Label->setPixmap(spielfenster);
    ui->Background_Label->setScaledContents(true);
    ui->Background_Label->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

}

void Spielfenster::on_Spiel_beenden_clicked()
{
    close();
}

void Spielfenster::on_Spin_button_clicked()
{
    int8_t wheel1;
    wheel1 = Zufallsgenerator().randomBild(rundenseitJackpot);

    int8_t wheel2;
    wheel2 = Zufallsgenerator().randomBild(rundenseitJackpot);

    int8_t wheel3;
    wheel3 = Zufallsgenerator().randomBild(rundenseitJackpot);

    QString bild1_s, bild2_s, bild3_s; // Deklaration der Variablen außerhalb des switch-Blocks

    if(!(wheel1 == wheel2 && wheel1==wheel3))
    {
        if (rundenseitJackpot >= 32){
            rundenseitJackpot = 0;
        }
        rundenseitJackpot++;
    }
    switch(wheel1)
    {
    case 1:
    {
        QDir bild1("../");
        bild1_s = bild1.absoluteFilePath("Spielautomat/images/cherry.png");
        break;
    }
    case 2:
    {
        QDir bild2("../");
        bild1_s = bild2.absoluteFilePath("Spielautomat/images/baer.png");
        break;
    }

    case 3:
    {
        QDir bild3("../");
        bild1_s = bild3.absoluteFilePath("Spielautomat/images/shot.png");
        break;
    }

    case 4:
    {
        QDir bild4("../");
        bild1_s = bild4.absoluteFilePath("Spielautomat/images/Questionmark.png");
        break;
    }

    case 5:
    {
        QDir bild5("../");
        bild1_s = bild5.absoluteFilePath("Spielautomat/images/exclamationmark.png");
        break;
    }

    default:
        break;
    }

    switch(wheel2)
    {
    case 1:
    {
        QDir bild1("../");
        bild2_s = bild1.absoluteFilePath("Spielautomat/images/cherry.png");
        break;
    }
    case 2:
    {
        QDir bild2("../");
        bild2_s = bild2.absoluteFilePath("Spielautomat/images/baer.png");
        break;
    }

    case 3:
    {
        QDir bild3("../");
        bild2_s = bild3.absoluteFilePath("Spielautomat/images/shot.png");
        break;
    }

    case 4:
    {
        QDir bild4("../");
        bild2_s = bild4.absoluteFilePath("Spielautomat/images/Questionmark.png");
        break;
    }

    case 5:
    {
        QDir bild5("../");
        bild2_s = bild5.absoluteFilePath("Spielautomat/images/exclamationmark.png");
        break;
    }

    default:
        break;
    }

    switch(wheel3)
    {
    case 1:
    {
        QDir bild1("../");
        bild3_s = bild1.absoluteFilePath("Spielautomat/images/cherry.png");
        break;
    }
    case 2:
    {
        QDir bild2("../");
        bild3_s = bild2.absoluteFilePath("Spielautomat/images/baer.png");
        break;
    }

    case 3:
    {
        QDir bild3("../");
        bild3_s = bild3.absoluteFilePath("Spielautomat/images/shot.png");
        break;
    }

    case 4:
    {
        QDir bild4("../");
        bild3_s = bild4.absoluteFilePath("Spielautomat/images/Questionmark.png");
        break;
    }

    case 5:
    {
        QDir bild5("../");
        bild3_s = bild5.absoluteFilePath("Spielautomat/images/exclamationmark.png");
        break;
    }

    default:
        break;
    }

    ui->SpinningWheel1->setPixmap(bild1_s);
    ui->SpinningWheel1->setScaledContents(true);
    ui->SpinningWheel1->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );


    ui->SpinningWheel2->setPixmap(bild2_s);
    ui->SpinningWheel2->setScaledContents(true);
    ui->SpinningWheel2->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );


    ui->SpinningWheel3->setPixmap(bild3_s);
    ui->SpinningWheel3->setScaledContents(true);
    ui->SpinningWheel3->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

    //Ausgabe der Spielername

    QString Ausgabe_Name;

    //Ausgabe_Name = "Tobias"; //Zufallsgenerator().selectRandomPlayer(Zufallsgenerator().multiplyNames(MainWindow().Spielerliste));

    //Ausgabe_Name = Zufallsgenerator().selectRandomPlayer(Zufallsgenerator().multiplyNames(MainWindow().Spielerliste));




    ui->Name_Line->setText(Ausgabe_Name);
}

