#include "ennemie.h"
#include <QTimer>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include <stdlib.h>
#include "jeux.h"
#include "zelda.h"

extern Jeux * jeux;

// ********** Constructeur **********
Ennemie::Ennemie(): QObject(), /*QGraphicsRectItem() */ QGraphicsPixmapItem(){

}

void Ennemie::attaquer(){

    // On envoye les projectile vers la gauche

    setPos(x() + directionX, y() + directionY);

    // Si un ennemie sors de la view une fois lancé, on le supprimer pour
    // On fait ca pour optimiser la mémoire
    if(pos().x() + 100 < 0){

        // Si l'énnemie n'a pas été touché, avant la fin de la view/scéne
        // On perd au niveau du score mais aussi au niveau de la vie
        // jeux->scoreDuPersonnage->diminutionScore();
        // jeux->vieDuPersonnage->diminutionVie();

        // On g

        //scene()->removeItem(this);
        //delete this;
        qDebug() << "Ennemie";
    }

    // Si les Ennemies rentre on collision avec le personnage principale
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i ++){
        if(typeid(*(colliding_items[i])) == typeid(Zelda)){
            // On les enléve  les projectile et ennemie en cas de collision
            // scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);


            // On les suprimer
            // delete colliding_items[i];
            delete this;


            // On augmente le nombre de fléches du personnage princiaple
            jeux->vieDuPersonnage->diminutionVie(pointDeDegat);

            // On sorts de la fonction si il y a collison
            // Sinon le code continuera et il 'y aura une erreur
            // Un peu en mode, le projectile et l'ennemies ont été suprimé, mais le code sur ces deux
            // item run encore -> Erreur
            return;
        }
    }



}

