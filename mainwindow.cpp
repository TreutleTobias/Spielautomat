#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "spielfenster.h"
#include "zufallsgenerator.h"
#include "Spielerliste.h"
#include "QDir"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //background Label
    QDir dir("../"); // Hier wird 'dir' deklariert
    QString spielfenster_pfad = dir.absoluteFilePath("Spielautomat/images/Startpage.png");
    QPixmap spielfenster(spielfenster_pfad);

    ui->Background_Label->setPixmap(spielfenster);
    ui->Background_Label->setScaledContents(true);
    ui->Background_Label->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Spieler_Hinzufuegen_clicked()
{
    bool nameVorhanden = false;
    QString name = ui->Eingabe->text();

    for(int i = 0; i < ui->listWidget->count(); ++i) {
        // Hole den Text des Listenelements an der aktuellen Position
        QString aktuellerName = ui->listWidget->item(i)->text();
        // Vergleiche den aktuellen Namen mit dem zu prüfenden Namen
        if(aktuellerName == name) {
            // Der Name ist bereits vorhanden
            nameVorhanden = true;

            break; // Beenden Sie die Schleife, sobald der Name gefunden wurde
        }
    }
    // Was passiert wenn name nicht vorhanden ist
    if(nameVorhanden == false){
    ui->listWidget->addItem(name);
    }else {
        QMessageBox::information(this,tr("Fehlermeldung"),tr("Name ist bereits"));
    }

    ui->Eingabe->clear();




}

void MainWindow::on_Fertig_clicked()
{

    if(ui->listWidget->count() == 0){
        QMessageBox::information(this,tr("Fehlermeldung"),tr("Bitte Spieler eintragen!"));
    } else{
        for(int i = 0; i < ui->listWidget->count(); ++i) {
            // Hole den Text des Listenelements an der aktuellen Position und füge ihn zur Ergebnisliste hinzu
            Spielerliste().spieler_hinzufuegen(ui->listWidget->item(i)->text());


        }
    spielfenster.setModal(true);
    spielfenster.exec();
     }
}

void MainWindow::on_Spieler_Loeschen_clicked()
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    if (item) {
        delete ui->listWidget->takeItem(ui->listWidget->row(item));
    }

}


void MainWindow::on_exit_clicked()
{
    close();
}



