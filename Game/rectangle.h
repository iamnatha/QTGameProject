#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QGraphicsRectItem>
#include <QKeyEvent>

/*
   Header de la classe Rectangle, qui contient uniquement
   la définitions des méthodes de la classes
*/

class Rectangle: public QGraphicsRectItem{
    public:
        // Cette méthode permet à au futur objet Rectangle de réagir à l'évenements
        void keyPressEvent(QKeyEvent *event);

};

#endif // RECTANGLE_H

