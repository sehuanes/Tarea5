#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "particula.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    timer = new QTimer(this);
    ui->setupUi(this);
    this->resize(600,720);
    this->setFixedSize(600,720);

    escena = new QGraphicsScene();
    ui->pantalla->setScene(escena);
    escena->setSceneRect(-10,-10,540,540);
    Particle = new Particula(100,300,15,10,17);  //Declarando un objeto grafico de la clase Part
    escena->addItem(Particle); //Agregando el objeto grafico a la escena
    timer->stop();
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizarEscena()));
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actualizarEscena(void)
{
   Particle->moverParticula(0.5,400);
   Particle->colisionParticula(400,400);
}


void MainWindow::on_inicio_clicked()
{
    timer->start(50);
}
