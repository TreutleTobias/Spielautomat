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

    // Hintergrund hinzufügen
    QDir dir("../"); // Hier wird 'dir' deklariert
    QString spielfenster_pfad = dir.absoluteFilePath("Spielautomat/images/Startpage.png");
    QPixmap spielfenster(spielfenster_pfad);

    ui->Background_Label->setPixmap(spielfenster);
    ui->Background_Label->setScaledContents(true);
    ui->Background_Label->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );



    // Spieler_hinzufügen Button Hintergrundbild hinzufügen
    QString Spieler_hinzufuegen_pfad = dir.absoluteFilePath("Spielautomat/images/Spieler_hinzufuegen.png");
    ui->Spieler_Hinzufuegen->setStyleSheet("QPushButton {"
                                           "background-image: url('"+Spieler_hinzufuegen_pfad +"');"
                                           "background-repeat: no-repeat;"
                                           "background-position: center;"
                                           "border: none;"  // entfernen Sie die Rahmen des Buttons
                                           "}");

    // Spieler_hinzufügen Button Hintergrundbild hinzufügen
    QString Spieler_loeschen_pfad = dir.absoluteFilePath("Spielautomat/images/Spieler_loeschen.png");
    ui->Spieler_Loeschen->setStyleSheet("QPushButton {"
                                           "background-image: url('"+Spieler_loeschen_pfad +"');"
                                                                        "background-repeat: no-repeat;"
                                                                        "background-position: center;"
                                                                        "border: none;"  // entfernen Sie die Rahmen des Buttons
                                                                        "}");

    // Spieler_hinzufügen Button Hintergrundbild hinzufügen
    QString Fertig_pfad = dir.absoluteFilePath("Spielautomat/images/Fertig.png");
    ui->Fertig->setStyleSheet("QPushButton {"
                                           "background-image: url('"+Fertig_pfad +"');"
                                                                     "background-repeat: no-repeat;"
                                                                     "background-position: center;"
                                                                     "border: none;"  // entfernen Sie die Rahmen des Buttons
                                                                     "}");

    ui->listWidget->setStyleSheet("QListWidget { border: none; }");
    ui->Eingabe->setStyleSheet("QLineEdit{ border: none; }");



}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Spieler_Hinzufuegen_clicked()
{
    bool nameVorhanden = false;
    // Text aus QEditLine auslesen
    QString name = ui->Eingabe->text();

    // Überprüfung, ob Name bereits vorhanden ist
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
        // Wenn Name nicht vorhanden ist wird neuer Name hinzugefügt
    ui->listWidget->addItem(name);
    }else {
        // Falls Name doch vorhanden ist wird eine Fehlermeldung ausgegeben
        QMessageBox::information(this,tr("Fehlermeldung"),tr("Name ist bereits"));
    }
    // Text aus QEditLine löschen
    ui->Eingabe->clear();




}

void MainWindow::on_Fertig_clicked()
{
    // Überprüdung ob die eine leere Liste übergeben wird
    if(ui->listWidget->count() == 0){
        // Wenn eine Liste übergebn wird eine Fehlermeldung ausgeben
        QMessageBox::information(this,tr("Fehlermeldung"),tr("Bitte Spieler eintragen!"));
    } else{
        // Abspeichern der Liste in ein QList<Qstring>
        for(int i = 0; i < ui->listWidget->count(); ++i) {
            // Hole den Text des Listenelements an der aktuellen Position und füge ihn zur Ergebnisliste hinzu
            Spielerliste().spieler_hinzufuegen(ui->listWidget->item(i)->text());


        }
        // Öffnen des Spielerfensters
        spielfenster.setModal(true);
        spielfenster.exec();
     }
}

void MainWindow::on_Spieler_Loeschen_clicked()
{
    // Element aus der Liste löschen
    QListWidgetItem *item = ui->listWidget->currentItem();
    if (item) {
        delete ui->listWidget->takeItem(ui->listWidget->row(item));
    }

}


void MainWindow::on_exit_clicked()
{
    // Schließen des Programms
    close();
}



