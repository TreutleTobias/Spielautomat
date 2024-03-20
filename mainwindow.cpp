#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "spieler.h"
#include "spielfenster.h"

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

    //spielerObjekt.Spieler_Liste_hinzufuegen(name);// Annahme: spielerObjekt ist eine Instanz von Spieler
}



void MainWindow::on_Fertig_clicked()
{
    Spielfenster spielfenster;
    spielfenster.setModal(true);
    spielfenster.exec();
}

