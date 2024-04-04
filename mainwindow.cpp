#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "spielfenster.h"
#include "zufallsgenerator.h"

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
    close();
}

void MainWindow::on_Spieler_Hinzufuegen_clicked()
{
    QString name = ui->Eingabe->text();
    Spielerliste.append(name);
    ui->listWidget->addItem(name);
    ui->Eingabe->clear();
}

void MainWindow::on_Fertig_clicked()
{
    /*QList<QString> multipliedNames = Zufallsgenerator::multiplyNames(Spielerliste);
    QString selectedPlayer = Zufallsgenerator::selectRandomPlayer(multipliedNames);
    // Hier können Sie die Instanz von Spielfenster verwenden und die Logik für die Spielstartseite implementieren
    spielfenster.show(); // Zeigen Sie das Spielfenster an*/

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

