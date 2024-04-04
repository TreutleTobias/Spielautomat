#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "spielfenster.h"
#include "zufallsgenerator.h"
#include "QDir"

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





void MainWindow::on_exit_clicked()
{
    close();
}

