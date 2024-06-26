#include "spielfenster.h"
#include "ui_spielfenster.h"
#include "zufallsgenerator.h"
#include "mainwindow.h"
#include "spielerliste.h"
#include "QPixmap"
#include "QDir"
#include "QFileInfo"
#include "QMessageBox"


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

    // Spin Button Hintergrundbild hinzufügen
    QString Spin_pfad = dir.absoluteFilePath("Spielautomat/images/Spin.png");
    ui->Spin_button->setStyleSheet("QPushButton {"
                                   "background-image: url('"+Spin_pfad +"');"
                                                 "background-repeat: no-repeat;"
                                                 "background-position: center;"
                                                 "border: none;"  // entfernen Sie die Rahmen des Buttons
                                                 "}");

    // Spin Button Hintergrundbild hinzufügen
    QString Beenden_pfad = dir.absoluteFilePath("Spielautomat/images/Beenden.png");
    ui->Spiel_beenden->setStyleSheet("QPushButton {"
                                     "background-image: url('"+Beenden_pfad +"');"
                                                      "background-repeat: no-repeat;"
                                                      "background-position: center;"
                                                      "border: none;"  // entfernen Sie die Rahmen des Buttons
                                                      "}");


}

void Spielfenster::on_Spiel_beenden_clicked()
{
    Spielerliste().liste_loeschen();
    close();
}

void Spielfenster::on_Spin_button_clicked()
{
    //Zufallsgenerator für 1. Rad
    int8_t wheel1;
    wheel1 = Zufallsgenerator().randomBild(rundenseitJackpot);

    //Zufallsgenerator für 2. Rad
    int8_t wheel2;
    wheel2 = Zufallsgenerator().randomBild(rundenseitJackpot);

    //Zufallsgenerator für 3. Rad
    int8_t wheel3;
    wheel3 = Zufallsgenerator().randomBild(rundenseitJackpot);

    //Bildstrings initialisieren, um den jeweiligen Pfad zu erhalten
    QString bild1_s, bild2_s, bild3_s; // Deklaration der Variablen außerhalb des switch-Blocks

    //Switch case 1, für 1. Rad, je nach dem was zufallsgenerator liefert wird unterschiedlicher String in bild1_s gespeichert
    switch(wheel1)
    {
    case 1:
    {
        //QDir-> SPeicherort von Programm lokal, bild1_s: summe aus speicherort plus pfad im speicherort für bild
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

    //Switch case 2, für 2. Rad, je nach dem was zufallsgenerator liefert wird unterschiedlicher String in bild1_s gespeichert
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

    //Switch case 3, für 3. Rad, je nach dem was zufallsgenerator liefert wird unterschiedlicher String in bild1_s gespeichert
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

    //Anzeigen der Bilder in den einzelnen "Rädern"
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

    Ausgabe_Name = Zufallsgenerator().selectRandomPlayer(Zufallsgenerator().multiplyNames(Spielerliste().get_Spielerliste()));

    ui->Name_Line->setText(Ausgabe_Name);

    //Wahrscheinlichkeit für Jackpot erhöhen, wenn er lange nicht kam
    if(!(wheel1 == wheel2 && wheel1==wheel3))
    {
        if (rundenseitJackpot >= 128){
            rundenseitJackpot = 0;
        }
        rundenseitJackpot++;

    }

    //Jackpot Message Box, Anzeige des Namens und der Aktion
    QString ausgabefeld = Ausgabe_Name + " wird einen Shot verköstigen";
    // Aufruf MessageBox, wenn es drei gleiche Symbole sind
    if(wheel1 == wheel2 && wheel1==wheel3)
    {
        QMessageBox::information(this,tr("Jackpot"),ausgabefeld);
    }
}

