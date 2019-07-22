#include "projectile.h"
#include <QTimer>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include "ennemie.h"
#include "personnagescore.h"
#include "jeux.h"
#include "troll.h"
#include "dragon.h"

extern Jeux * jeux;

// ********** Constructeur **********
Projectile::Projectile(int directionX, int directionY) : QObject(), /*QGraphicsRectItem(parent), */ QGraphicsPixmapItem (){

    SoundProjectile = new QMediaPlayer();
    SoundProjectile->setMedia(QUrl("qrc:/SoundProjectile.wav"));

    SoundPouf = new QMediaPlayer();
    SoundPouf->setMedia(QUrl("qrc:/SoundPouf.wav"));

    // nbDeProjectile = 10;

    // Precédement, quand les projectile était des rectangle
    // Le projectile correspond à un rectangle de largeur 10 et
    // de hauteur 50
    // setRect(40,40,50, 10);

    // Maintenant, quand les projectile sont des flêches
    if((directionX == 20) && (directionY == 0)){
        setPixmap(QPixmap(":/FlecheDroite.png").scaled(20,20));

    }
    else if((directionX == -20) && (directionY == 0)){
        setPixmap(QPixmap(":/FlecheGauche.png").scaled(20,20));
        qDebug() << "FLECHE GAUCHE";
    }
    else if((directionX == 0) && (directionY == -20)){
        setPixmap(QPixmap(":/FlecheHaut.png").scaled(20,20));
        qDebug() << "FLECHE HAUT";
    }
    else if((directionX == 0) && (directionY == +20)){
        setPixmap(QPixmap(":/FlecheBas.png").scaled(20,20));
        qDebug() << "FLECHE BAS";
    }

    // On regarde si le son n'est pas entrain de se jouer
    if(SoundProjectile->state() == QMediaPlayer::PlayingState){
        SoundProjectile->setPosition(0);
    }
    else if(SoundProjectile->state() == QMediaPlayer::StoppedState){
        SoundProjectile->play();
    }

    directionProjectileX = directionX;
    directionProjectileY = directionY;

    // Connectons le timer au slots (voir projectile.h)
    QTimer * timer = new QTimer();
    // On connect un certain signal à un certain slots
    // C'est à dire, quand le timer est remis à zéro, un signal a lieu
    // Connecte le timeout() fonction du timer au envoyerLesProjectile() du projectile
    connect(timer, SIGNAL(timeout()), this, SLOT(envoyerLesProjectile()));

    // Tous les 50 milliSeconde, il y a un timeout
    // La fonction envoyerLesProjectile() est appelée
    // Tous les projectile bouge indépendaement
    timer->start(50);
}

void Projectile::envoyerLesProjectile(){
    // C'est pas ici qu'on décimente le nb de projectile, car cette fonction est appelé toutes les 50 milliseconde
    // nbDeProjectile = nbDeProjectile - 1;
    // qDebug() << "Il vous reste " << nbDeProjectile << " .";
    // if(nbDeProjectile <= 0){
        // On ne balance pas de fléches
    // }




    int nbDeProjectileDuPersonnage = jeux->personnageProjectile->getNbDeProjectile();
    qDebug() << "Il vous reste " << nbDeProjectileDuPersonnage << " projectile.";

    // Si les projectiles rentre on collision avec les ennemies
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i ++){
        if(typeid(*(colliding_items[i])) == typeid(Troll) || typeid(*(colliding_items[i])) == typeid(Dragon)){
            // On les enléve  les projectile et ennemie en cas de collision
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // On les suprimer
            delete colliding_items[i];
            delete this;

            // On regarde si le son n'est pas entrain de se jouer
            if(SoundPouf->state() == QMediaPlayer::PlayingState){
                SoundPouf->setPosition(0);
            }
            else if(SoundPouf->state() == QMediaPlayer::StoppedState){
                SoundPouf->play();
            }



            // On augmente le score si le projectile envoyé touche un ennemie
            jeux->scoreDuPersonnage->augmentationScore();

            // On sorts de la fonction si il y a collison
            // Sinon le code continuera et il 'y aura une erreur
            // Un peu en mode, le projectile et l'ennemies ont été suprimé, mais le code sur ces deux
            // item run encore -> Erreur
            return;
        }
    }

    // On envoye les projectile vers la droite

        setPos(x()+directionProjectileX, y()+directionProjectileY);



    // Si le projectile est sors de la view une fois lancé, on le supprimer pour
    // On fait ca pour optimiser la mémoire
    if(pos().x() > 800){
        scene()->removeItem(this);
        delete this;
        qDebug() << "Projectil suprimée car hors du cadre";
    }

}

/*
 Pareil, c'est pas ici qu'il faut mettre cette fonction
 car c'est le personnage qui détien un nb de projectile

void Projectile::diminutionProjectile(){
    nbDeProjectile = nbDeProjectile - 1;
}

*/

