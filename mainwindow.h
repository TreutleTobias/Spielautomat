#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "spielfenster.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_exit_clicked();



    void on_Spieler_Hinzufuegen_clicked();

    void on_Fertig_clicked();

    void on_Spieler_Loeschen_clicked();

    //QList<QString> get_Spielerliste(return Spielerliste;);

    QList<QString> get_Spielerliste(const QList<QString>& Spielerliste);

private:
    Ui::MainWindow *ui;
    QList<QString> Spielerliste;
    Spielfenster spielfenster;

};
#endif // MAINWINDOW_H
