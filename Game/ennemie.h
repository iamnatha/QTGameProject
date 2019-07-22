#ifndef ENNEMIE_H
#define ENNEMIE_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include <QMovie>

class Ennemie: public QObject, /*public QGraphicsRectItem*/ public QGraphicsPixmapItem{
  Q_OBJECT

  public:
    Ennemie(); // Définition du Constructeur
  public slots:
    // La méthode envoyerLesProjectile() est de type slots
    // La méthode est connecté à un signal
    void attaquer();

  protected:
    int directionX;
    int directionY;
    int composant;
    int pointDeDegat;
    // QMovie * annimation = nullptr;
};


#endif // ENNEMIE_H
