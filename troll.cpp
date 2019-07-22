#include "troll.h"
#include <QTimer>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include <stdlib.h>
#include "jeux.h"

extern Jeux * jeux;

// ********** Constructeur **********
Troll::Troll(): Ennemie (){

    //directionX = rand() % 400 + 40;
    // directionY = rand() % 400 + 40;
    pointDeDegat = 1;

    // Mettre un postion aléatoire au ennemies
    int nombreAleatoire = rand() % 400 + 40; // Pour mettra à l'intérieur de la view/scene ni trop haut ni trop bas

    int x, y;

    if(rand() % 2 + 1 == 1){
        x = 0;
    }
    else {
        x = 800;
    }

    if(rand() % 2 + 1 == 1){
        y = 0;
    }
    else {
        y = 533;
    }

    setPos(x, y);

    directionX = (jeux->joueurPrincipal->pos().x() - x) / 50;
    directionY = (jeux->joueurPrincipal->pos().y() - y) / 50;

    // Précdement, l'enemie était un rectangle
    // Le projectile correspond à un rectangle de largeur 10 et
    // de hauteur 50
    // setRect(0,0,100, 100);

    // Maintenant
    setPixmap(QPixmap(":/Troll.png").scaled(45,45));


    // Connectons le timer au slots (voir projectile.h)
    QTimer * timer = new QTimer();
    // On connect un certain signal à un certain slots
    // C'est à dire, quand le timer est remis à zéro, un signal a lieu
    // Connecte le timeout() fonction du timer au attaquer() du projectile
    connect(timer, SIGNAL(timeout()), this, SLOT(attaquer()));

    // Tous les 50 milliSeconde, il y a un timeout
    // La fonction envoyerLesProjectile() est appelée
    // Tous les projectile bouge indépendaement
    timer->start(50);

}
