#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <QGraphicsRectItem>
#include <QObject>
#include "personnagescore.h"
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>

class Projectile: public QObject, /*public QGraphicsRectItem, */ public QGraphicsPixmapItem{
  Q_OBJECT

  public:
    Projectile(int directionX = 20, int directionY = 0); // Définition du Constructeur
  public slots:
    // La méthode envoyerLesProjectile() est de type slots
    // La méthode est connecté à un signal
    void envoyerLesProjectile();
    // C'est le personnage qui a des projectile, donc cette méthode ne doit pas être ici
    // void diminutionProjectile();

  private:
    // Idem
    // int nbDeProjectile;
    int directionProjectileX;
    int directionProjectileY;
  QMediaPlayer * SoundProjectile;
  QMediaPlayer * SoundPouf;

};

#endif // PROJECTILE_H

