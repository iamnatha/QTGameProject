#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>

class GameObject: public QObject, /*public QGraphicsRectItem*/ public QGraphicsPixmapItem{
  Q_OBJECT

    public:
      GameObject();

};

#endif // GAMEOBJECT_H
