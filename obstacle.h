#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>

class Obstacle: public QObject, /*public QGraphicsRectItem*/ public QGraphicsPixmapItem{
  Q_OBJECT

  public:
    Obstacle();
    void collision();

};

#endif // OBSTACLE_H
