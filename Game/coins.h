#ifndef COINS_H
#define COINS_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>

class Coins: public QObject, /*public QGraphicsRectItem*/ public QGraphicsPixmapItem{
  Q_OBJECT

  public:
    Ennemie(); // Définition du Constructeur
  public slots:
    // La méthode envoyerLesProjectile() est de type slots
    // La méthode est connecté à un signal
    void attaquer();

};

#endif // COINS_H
