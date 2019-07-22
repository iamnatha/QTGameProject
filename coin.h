#ifndef COIN_H
#define COIN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include "gameobject.h"

class Coin: public GameObject{
  Q_OBJECT

  public:
    Coin(); // Définition du Constructeur
  public slots:
    // La méthode envoyerLesProjectile() est de type slots
    // La méthode est connecté à un signal
    void deplacementCoin();

private:
    QMediaPlayer * SoundCoin;

};

#endif // COIN_H
