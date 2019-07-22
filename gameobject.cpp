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
#include "gameobject.h"

extern Jeux * jeux;

// ********** Constructeur **********
GameObject::GameObject(): QObject(), /*QGraphicsRectItem() */ QGraphicsPixmapItem(){

}
