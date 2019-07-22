#include "personnageprojectile.h"
#include <QFont>
#include <QDebug>
#include <QGraphicsTextItem>
#include <QTextEdit>
#include <QGraphicsScene>
#include <jeux.h>

extern Jeux * jeux;

// Constructeur
PersonnageProjectile::PersonnageProjectile(QGraphicsItem * parent): QGraphicsTextItem (parent){
    // Initialisation du score à 0
    nbDeProjectileDuPersonnage = 10;

    // Affichage du score
    setPlainText(QString("Fléches: ") + QString::number(nbDeProjectileDuPersonnage));
    // Couleur du texte à afficher
    setDefaultTextColor(Qt::white);
    // Police et taille du texte
    setFont(QFont("Courier New", 20));

}

int PersonnageProjectile::getNbDeProjectile(){
    return nbDeProjectileDuPersonnage;
}

void PersonnageProjectile::affichageNbDeProjectile(){
    setPlainText(QString("Fléches: ") + QString::number(nbDeProjectileDuPersonnage));
}

void PersonnageProjectile::diminutionProjectile(){
    if(nbDeProjectileDuPersonnage > 0){
        nbDeProjectileDuPersonnage = nbDeProjectileDuPersonnage - 1;
        setPlainText(QString("Fléches: ") + QString::number(nbDeProjectileDuPersonnage));
    }
    else {
        setPlainText(QString("Fléches: ") + QString::number(0));
    }
}

void PersonnageProjectile::setNbDeProjectile(int nbDeProjectileParametre){
    nbDeProjectileDuPersonnage = nbDeProjectileParametre;
    setPlainText(QString("Fléches: ") + QString::number(nbDeProjectileDuPersonnage));
}

void PersonnageProjectile::augmentationProjectile(){
     nbDeProjectileDuPersonnage = nbDeProjectileDuPersonnage + 6;
     setPlainText(QString("Fléches: ") + QString::number(nbDeProjectileDuPersonnage));

}

