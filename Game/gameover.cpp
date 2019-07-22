#include "gameover.h"
#include <QFont>
#include <QDebug>
#include <QGraphicsTextItem>
#include <QTextEdit>
#include <QGraphicsScene>

// Constructeur
GameOver::GameOver(QGraphicsItem * parent): QGraphicsTextItem (parent){
    // Initialisation du score à 0

    // Affichage du score
    setPlainText(QString("Game Over!"));
    // Couleur du texte à afficher
    setDefaultTextColor(Qt::white);
    // Police et taille du texte
    setFont(QFont("Courier New", 80));

}

