#ifndef ZELDA_H
#define ZELDA_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QKeyEvent>
#include "personnagescore.h"
#include "personnage.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QObject>
#include <QMovie>

/*
   Header de la classe Rectangle, qui contient uniquement
   la définitions des méthodes de la classes
*/

class Zelda: public Personnage {
    Q_OBJECT
    public:
        // Constructeur
        Zelda();
        // void keyPressEvent(QKeyEvent *event);
        //void diminutionProjectile();
        void keyPressEvent(QKeyEvent *event);
        //void diminutionProjectile();

    public slots:
        void spawn1();
        void spawn2();
        void spawn3();

    private:
        QMovie * annimation;

};

#endif // ZELDA_H
