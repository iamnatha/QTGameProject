#include "personnagescore.h"
#include <QFont>
#include <QDebug>
#include <QGraphicsTextItem>
#include <QTextEdit>
#include <QGraphicsScene>

// Constructeur
PersonnageScore::PersonnageScore(QGraphicsItem * parent): QGraphicsTextItem (parent){
    // Initialisation du score à 0
    scoreDuPersonnage = 0;

    // Affichage du score
    setPlainText(QString("Score: ") + QString::number(scoreDuPersonnage));
    // Couleur du texte à afficher
    setDefaultTextColor(Qt::white);
    // Police et taille du texte
    setFont(QFont("Courier New", 20));

}

int PersonnageScore::getScore(){
    return scoreDuPersonnage;
}

void PersonnageScore::setScore(int scoreParametre){
    scoreDuPersonnage = scoreParametre;
    setPlainText(QString("Score: ") + QString::number(scoreDuPersonnage));
}

void PersonnageScore::augmentationScore(){
    // On ajoute 1 au score du Personnage
    scoreDuPersonnage = scoreDuPersonnage + 1;
    qDebug() << "Score: " << scoreDuPersonnage << "";
    setPlainText(QString("Score: ") + QString::number(scoreDuPersonnage));
}

void PersonnageScore::diminutionScore(){
    // On ajoute 1 au score du Personnage
    scoreDuPersonnage = scoreDuPersonnage - 1;
    qDebug() << "Score: " << scoreDuPersonnage << "";
    setPlainText(QString("Score: ") + QString::number(scoreDuPersonnage));
}


