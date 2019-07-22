#include "coin.h"
#include <QTimer>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include <stdlib.h>
#include "jeux.h"
#include "zelda.h"
#include <QMediaPlayer>

extern Jeux * jeux;

// ********** Constructeur **********
Coin::Coin(): GameObject (){

    SoundCoin = new QMediaPlayer();
    SoundCoin->setMedia(QUrl("qrc:/SoundCoin.wav"));

    // Mettre un postion aléatoire au ennemies
    int nombreAleatoire = rand() % 400 + 40; // Pour mettra à l'intérieur de la view/scene ni trop haut ni trop bas
    setPos(800, nombreAleatoire);

    // Précdement, l'enemie était un rectangle
    // Le projectile correspond à un rectangle de largeur 10 et
    // de hauteur 50
    // setRect(0,0,100, 100);

    // Maintenant
    setPixmap(QPixmap(":/Coin.png"));

    // Connectons le timer au slots (voir projectile.h)
    QTimer * timer = new QTimer();
    // On connect un certain signal à un certain slots
    // C'est à dire, quand le timer est remis à zéro, un signal a lieu
    // Connecte le timeout() fonction du timer au attaquer() du projectile
    connect(timer, SIGNAL(timeout()), this, SLOT(deplacementCoin()));

    // Tous les 50 milliSeconde, il y a un timeout
    // La fonction envoyerLesProjectile() est appelée
    // Tous les projectile bouge indépendaement
    timer->start(50);
}

void Coin::deplacementCoin(){
    // On envoye les projectile vers la gauche
    setPos(x()-10, y());

    // Si les Coins rentre on collision avec le ppersonnage principale
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i ++){
        if(typeid(*(colliding_items[i])) == typeid(Zelda)){
            // On les enléve  les projectile et ennemie en cas de collision
            // scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // On les suprimer
            // delete colliding_items[i];
            delete this;

            // On regarde si le son n'est pas entrain de se jouer
            if(SoundCoin->state() == QMediaPlayer::PlayingState){
                SoundCoin->setPosition(0);
            }
            else if(SoundCoin->state() == QMediaPlayer::StoppedState){
                SoundCoin->play();
            }

            // On augmente le nombre de fléches du personnage princiaple
            jeux->personnageProjectile->augmentationProjectile();



            // On sorts de la fonction si il y a collison
            // Sinon le code continuera et il 'y aura une erreur
            // Un peu en mode, le projectile et l'ennemies ont été suprimé, mais le code sur ces deux
            // item run encore -> Erreur
            return;
        }
    }

    // Si un Coin sors de la view une fois lancé, on le supprimer pour
    // On fait ca pour optimiser la mémoire
    if(pos().x() + 100 < 0){
        scene()->removeItem(this);
        delete this;
        qDebug() << "Coin";
    }
}
