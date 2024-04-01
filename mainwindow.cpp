#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "spielfenster.h"
#include "zufallsgenerator.h"

//#include <QtCore>;
//#include <QtGui>;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);    
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exit_clicked()
{
    // Schließen
    close();
}





void MainWindow::on_Spieler_Hinzufuegen_clicked()
{
    QString name = ui->Eingabe->text(); // getText() wurde zu text() geändert

    Spielerliste.append(name);

    ui->listWidget->addItem(name);

    ui->Eingabe->clear();
}



void MainWindow::on_Fertig_clicked()
{
    spielfenster.setModal(true);
    spielfenster.exec();
}


void MainWindow::on_Spieler_Loeschen_clicked()
{
    QListWidgetItem *item = ui->listWidget->currentItem();
    if (item) {
        delete ui->listWidget->takeItem(ui->listWidget->row(item));
    }
}

QList<QString> get_Spielerliste(const QList<QString>& Spielerliste) {
    // Hier wäre normalerweise die Logik zum Abrufen der Spielerliste implementiert
    // Für diese Funktion wird die übergebene Spielerliste einfach zurückgegeben
    return Spielerliste;
}

