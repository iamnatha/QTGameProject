#include "zelda.h"
#include "projectile.h"
#include "ennemie.h"
#include "trunk.h"
#include "jeux.h"
#include "coin.h"
#include "coeur.h"
#include "dragon.h"
#include "troll.h"

#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include "personnagescore.h"
#include <QGraphicsTextItem>
#include <QTextEdit>
#include <QGraphicsScene>

extern Jeux * jeux;

Zelda::Zelda(): Personnage (){
    // setPixmap(QPixmap(":/ZeldaDroite.png"));
    toucheX = 20;
    toucheY = 0;

    annimation=new QMovie(":/ZeldaGifDroite.gif");
    annimation->start();
    setPixmap(annimation->currentPixmap());
}

void Zelda::keyPressEvent(QKeyEvent *event){

    /*
      Cette méthode prend en paramétre une variable de type QKeyEvent
      qui va nous permetre de déterminer quel

    */

    if(event->key() == Qt::Key_Left){
        qDebug() << "Key Left pressed";
        // On vérifie que l'élment ne sorts pas du cadre
        if(pos().x() > 0){
            setPos(x()-20, y());

            QList<QGraphicsItem *> colliding_items = collidingItems();
            for (int i = 0, n = colliding_items.size(); i < n; i ++){
                if(typeid(*(colliding_items[i])) == typeid(Trunk)){

                   this->setPos(x()+20, y());

                   return;
                }
            }

        }

        // setPixmap(QPixmap(":/ZeldaGauche.png"));
        if(annimation->fileName()!= ":/ZeldaGifGauche.gif"){
            annimation=new QMovie(":/ZeldaGifGauche.gif");
            annimation->start();
        }
        setPixmap(annimation->currentPixmap());
        toucheX = -20;
        toucheY = 0;
    }
    else if(event->key() == Qt::Key_Right){
        qDebug() << "Key Right pressed";
        // On vérifie que l'élment ne sorts pas du cadre
        if(pos().x() + 32 < 800){
            setPos(x()+20, y());

            QList<QGraphicsItem *> colliding_items = collidingItems();
            for (int i = 0, n = colliding_items.size(); i < n; i ++){
                if(typeid(*(colliding_items[i])) == typeid(Trunk)){

                   this->setPos(x()-20, y());

                   return;
                }
            }
        }
        // setPixmap(QPixmap(":/ZeldaDroite.png"));
        if(annimation->fileName()!= ":/ZeldaGifDroite.gif"){
            annimation=new QMovie(":/ZeldaGifDroite.gif");
            annimation->start();
        }
        setPixmap(annimation->currentPixmap());
        toucheX = + 20;
        toucheY = 0;
    }
    else if(event->key() == Qt::Key_Up){
        qDebug() << "Key Up pressed";
        // On vérifie que l'élment ne sorts pas du cadre

        if(pos().y() > 0){
            setPos(x(), y()-20);

            QList<QGraphicsItem *> colliding_items = collidingItems();
            for (int i = 0, n = colliding_items.size(); i < n; i ++){
                if(typeid(*(colliding_items[i])) == typeid(Trunk)){

                   this->setPos(x(), y()+20);

                   return;
                }
            }

        }
        //setPixmap(QPixmap(":/ZeldaHaut.png"));
        if(annimation->fileName()!= ":/ZeldaGifHaut.gif"){
            annimation=new QMovie(":/ZeldaGifHaut.gif");
            annimation->start();
        }
        setPixmap(annimation->currentPixmap());
        toucheX = 0;
        toucheY = -20;
    }
    else if(event->key() == Qt::Key_Down){
        qDebug() << "Key Down pressed";
        // On vérifie que l'élment ne sorts pas du cadre
        if(pos().y() + 32 < 533){
            setPos(x(), y()+20);

            QList<QGraphicsItem *> colliding_items = collidingItems();
            for (int i = 0, n = colliding_items.size(); i < n; i ++){
                if(typeid(*(colliding_items[i])) == typeid(Trunk)){

                   this->setPos(x(), y()-20);

                   return;
                }
            }

        }
        // setPixmap(QPixmap(":/ZeldaBas.png"));
        if(annimation->fileName()!= ":/ZeldaGifBas.gif"){
            annimation=new QMovie(":/ZeldaGifBas.gif");
            annimation->start();
        }
        setPixmap(annimation->currentPixmap());
        toucheX = 0;
        toucheY = +20;
    }
    else if(event->key() == Qt::Key_Space){

        // On vérifie qu'il reste bien des projectile à notre personnage
        if(jeux->personnageProjectile->getNbDeProjectile() <= 0){
            // Si il n'as pas de projectile, alors, il ne peux en balancer
        }
        else{

        // On crée un projectile quand on appuis sur espace
        // Créons un projectile en instancifions un objet projectile



        qDebug() << "DirectionX: " << toucheX << " ; DirectionY: "<< toucheY ;
        Projectile * projectile = new Projectile(toucheX, toucheY);

        // projectile->diminutionProjectile();
        qDebug() << "Projectile crée";

        // Comme la classe Projectile dérive de QGraphicsRectItem,
        // on a accées à la méthode setPos()
        projectile->setPos(x()+15, y()+10);
        // Ajoutons le projectile à la scéne
        scene()->addItem(projectile);
        }
        jeux->personnageProjectile->diminutionProjectile();

    }

    // Si les projectiles rentre on collision avec les ennemies


}

/*
void Personnage::diminutionProjectile(){
    nbDeProjectile = nbDeProjectile - 1;
}*/

void Zelda::spawn1(){
    // Creation d'ennemies

    if(rand() % 2 + 1 == 2){
        Dragon * dragon = new Dragon();
        scene()->addItem(dragon);
    }
    else {
        Troll * troll = new Troll();
        scene()->addItem(troll);
    }

}

void Zelda::spawn2(){
    // Creation des coins
    Coin * coin = new Coin();
    scene()->addItem(coin);
}

void Zelda::spawn3(){
    // Creation des coins
    Coeur * coeur = new Coeur();
    scene()->addItem(coeur);
}

