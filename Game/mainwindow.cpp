#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "jeux.h"

extern Jeux * jeux;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setFont(QFont("Courier New", 50));
    ui->label->setStyleSheet("QLabel {color: black}");

    ui->label_2->setFont(QFont("Courier New", 11));
    ui->label_2->setStyleSheet("QLabel {color: black}");


    ui->label_4->setFont(QFont("Courier New", 11));
    ui->label_4->setStyleSheet("QLabel {color: black}");

    ui->label_5->setFont(QFont("Courier New", 11));
    ui->label_5->setStyleSheet("QLabel {color: black}");

    ui->label_6->setFont(QFont("Courier New", 11));
    ui->label_6->setStyleSheet("QLabel {color: black}");

    ui->label_7->setFont(QFont("Courier New", 11));
    ui->label_7->setStyleSheet("QLabel {color: black}");

    ui->label_2->setText("Vous devez tuer le plus de dragon possible tant que vous avez de la vie.");
    ui->label_4->setText("1/ Vous perdez de la vie si vous touchez un dragon");
    ui->label_5->setText("2/ Vous perdez de la vie si un dragon arriver à traverser l'écran");
    ui->label_6->setText("3/ Vous gagnez des point si tuez un dragon (espace pour lancer une fléches)");
    ui->label_7->setText("4/ En chopant des point vous recevez des fléches");

    ui->pushButton->setStyleSheet("QPushButton {background-color: black; color: white}");
    ui->pushButton_2->setStyleSheet("QPushButton {background-color: black; color: white}");

    ui->statusBar->setVisible(true);
    ui->menuBar->setVisible(true);
    ui->mainToolBar->setVisible(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    jeux = new Jeux(1);
    this->close();
}


void MainWindow::on_pushButton_2_clicked()
{
    jeux = new Jeux(2);
    this->close();
}
