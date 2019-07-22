#include "trunk.h"
#include <QTimer>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include <stdlib.h>
#include "jeux.h"
#include "zelda.h"
#include "obstacle.h"

extern Jeux * jeux;

// ********** Constructeur **********
Trunk::Trunk(): Obstacle(){

    setPixmap(QPixmap(":/Trunk.png"));

}

