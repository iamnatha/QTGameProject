#include "personnagevie.h"
#include <QFont>
#include <QDebug>
#include <QGraphicsTextItem>
#include <QTextEdit>
#include <QGraphicsScene>
#include "jeux.h";
#include <QLabel>

extern Jeux * jeux;

// Constructeur
PersonnageVie::PersonnageVie(QGraphicsItem * parent): QGraphicsTextItem (parent){
    // Initialisation du score à 0
    vieDuPersonnage = 10;

    // Affichage du score
    setPlainText(QString("Vie: ") + QString::number(vieDuPersonnage));
    // Couleur du texte à afficher
    setDefaultTextColor(Qt::white);
    // Police et taille du texte
    setFont(QFont("Courier New", 20));

}

int PersonnageVie::getVie(){
    return vieDuPersonnage;
}

void PersonnageVie::diminutionVie(int pointDeVie){
    // On ajoute 1 au score du Personnage
    if(vieDuPersonnage >= 1){
        vieDuPersonnage = vieDuPersonnage - pointDeVie;
        setPlainText(QString("Vie: ") + QString::number(vieDuPersonnage));
        qDebug() << "Vie: " << vieDuPersonnage << "";
    }
    else{
        // GAME OVER
        jeux->sceneGame->clear();
        jeux->gameOver = new GameOver();
        jeux->gameOver->setPos(50, 100);
        jeux->sceneGame->addItem(jeux->gameOver);

        // On affiche ces performances

        int vieFinale = jeux->vieDuPersonnage->getVie();
        int scoreFinale = jeux->scoreDuPersonnage->getScore();
        int nbDeProjectileFinale = jeux->personnageProjectile->getNbDeProjectile();

        jeux->vieDuPersonnage = new PersonnageVie();
        jeux->vieDuPersonnage->setVie(vieFinale);
        jeux->vieDuPersonnage->setPos(56, 30);
        jeux->sceneGame->addItem(jeux->vieDuPersonnage);

        jeux->scoreDuPersonnage = new PersonnageScore();
        jeux->scoreDuPersonnage->setScore(scoreFinale);
        jeux->scoreDuPersonnage->setPos(206, 30);
        jeux->sceneGame->addItem(jeux->scoreDuPersonnage);


        jeux->personnageProjectile = new PersonnageProjectile();
        jeux->personnageProjectile->setNbDeProjectile(nbDeProjectileFinale);
        jeux->personnageProjectile->setPos(356, 30);
        jeux->sceneGame->addItem(jeux->personnageProjectile);


        QLabel * labelVie = new QLabel();
        labelVie->setText("Vie" + QString::number(jeux->vieDuPersonnage->getVie()));




    }
}

void PersonnageVie::setVie(int vieParametre){
    vieDuPersonnage = vieParametre;
     setPlainText(QString("Vie: ") + QString::number(vieDuPersonnage));
}

void PersonnageVie::augmentationVie(){
    // On ajoute 1 au score du Personnage
    vieDuPersonnage = vieDuPersonnage + 2;
    setPlainText(QString("Vie: ") + QString::number(vieDuPersonnage));
    qDebug() << "Vie: " << vieDuPersonnage << "";
}
