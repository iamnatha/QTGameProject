#ifndef DRAGON_H
#define DRAGON_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include "ennemie.h"

class Dragon: public Ennemie{
  Q_OBJECT

  public:
    Dragon(); // Définition du Constructeur

};

#endif // DRAGON_H
