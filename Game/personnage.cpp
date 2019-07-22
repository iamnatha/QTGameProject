#include "personnage.h"
#include "projectile.h"
#include "ennemie.h"
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

Personnage::Personnage(QGraphicsItem *parent): /*QGraphicsRectItem(parent) */ QGraphicsPixmapItem(){

    // touche = 20;
}

