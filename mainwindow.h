#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "spielfenster.h"
#include "zufallsgenerator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QList<QString> Spielerliste;

private slots:
    void on_exit_clicked();
    void on_Spieler_Hinzufuegen_clicked();
    void on_Fertig_clicked();
    void on_Spieler_Loeschen_clicked();

    void on_on_exit_clicked();

private:
    Ui::MainWindow *ui;
    //QList<QString> Spielerliste;
    Spielfenster spielfenster;
    Zufallsgenerator zufallsgenerator;
};

#endif // MAINWINDOW_H

