#ifndef COEUR_H
#define COEUR_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>
#include "gameobject.h"

class Coeur: public GameObject{
  Q_OBJECT
  public:
    Coeur(); // Définition du Constructeur
  public slots:
    // La méthode envoyerLesProjectile() est de type slots
    // La méthode est connecté à un signal
    void deplacementCoeur();

  private:
    QMediaPlayer * SoundCoeur;

};

#endif // COEUR_H
