#include "spielfenster.h"
#include "ui_spielfenster.h"
#include "zufallsgenerator.h"
#include "QPixmap"
#include "QDir"
#include "QFileInfo"
int rundenseitJackpot;
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

    //QList<QString> multipliedNames; // Hier sollten Sie die Liste der Namen haben, die Sie von MainWindow erhalten
    //QString selectedPlayer = Zufallsgenerator::selectRandomPlayer(multipliedNames);
    // Jetzt können Sie den ausgewählten Spieler verwenden, um die Spiellogik fortzusetzen


    int8_t wheel1;
    wheel1 = Zufallsgenerator().randomBild(rundenseitJackpot);

    int8_t wheel2;
    wheel2 = Zufallsgenerator().randomBild(rundenseitJackpot);

    int8_t wheel3;
    wheel3 = Zufallsgenerator().randomBild(rundenseitJackpot);

    QString bild1_s, bild2_s; // Deklaration der Variablen außerhalb des switch-Blocks

    switch(wheel1)
    {
    case 1:
    {
        QDir bild1("../");
        bild1_s = bild1.absoluteFilePath("Spielautomat/images/background.png");
        break;
    }
    case 2:
    {


        QDir bild2("../");
        bild2_s = bild2.absoluteFilePath("Spielautomat/images/background.png");
        break;
    }
    default:
        break;
    }
}

