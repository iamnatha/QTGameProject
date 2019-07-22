#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QKeyEvent>
#include "personnagescore.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QObject>

/*
   Header de la classe Rectangle, qui contient uniquement
   la définitions des méthodes de la classes
*/

class Personnage: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
    public:
        // Constructeur
        Personnage(QGraphicsItem * parent=0);


   protected:
        int toucheX;
        int toucheY;
        char nom;
};

#endif // PERSONNAGE_H
