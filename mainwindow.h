#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <particula.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_inicio_clicked();
    void actualizarEscena(void);


private:
    Ui::MainWindow *ui;
    QGraphicsScene *escena;
    Particula *Particle;
    QTimer *timer;

};

#endif // MAINWINDOW_H
