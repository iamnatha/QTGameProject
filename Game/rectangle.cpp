#include "rectangle.h"
#include "projectile.h"

#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>

// Cette méthode a était difini dans le rectangle.h

void Rectangle::keyPressEvent(QKeyEvent *event){

    /*
      Cette méthode prend en paramétre une variable de type QKeyEvent
      qui va nous permetre de déterminer quel

    */

    if(event->key() == Qt::Key_Left){
        qDebug() << "Key Left pressed";
        setPos(x()-10, y());
    }
    else if(event->key() == Qt::Key_Right){
        qDebug() << "Key Right pressed";
        setPos(x()+10, y());
    }
    else if(event->key() == Qt::Key_Up){
        qDebug() << "Key Up pressed";
        setPos(x(), y()-10);
    }
    else if(event->key() == Qt::Key_Down){
        qDebug() << "Key Down pressed";
        setPos(x(), y()+10);
    }
    else if(event->key() == Qt::Key_Space){
        // On crée un projectile quand on appuis sur espace
        // Créons un projectile en instancifions un objet projectile
        Projectile * projectile = new Projectile();
        qDebug() << "Projectile crée";

        // Comme la classe Projectile dérive de QGraphicsRectItem,
        // on a accées à la méthode setPos()
        projectile->setPos(x(), y());
        // Ajoutons le projectile à la scéne
        scene()->addItem(projectile);
    }

}
