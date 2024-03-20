#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <spieler.h>

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

    void on_pushButton_3_clicked();

    void on_Spieler_Hinzufuegen_clicked();

    void on_Fertig_clicked();

private:
    Ui::MainWindow *ui;
    Spieler spielerObjekt;
};
#endif // MAINWINDOW_H
