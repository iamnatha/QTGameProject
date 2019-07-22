#ifndef JEUX_H
#define JEUX_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "personnage.h"
#include "personnagescore.h"
#include "personnagevie.h"
#include "personnageprojectile.h"
#include "gameover.h"

class Jeux: public QGraphicsView{
public:
    Jeux( int niveau = 0, QWidget * parent=0);
    QGraphicsScene * sceneGame;
    Personnage * joueurPrincipal;
    PersonnageScore * scoreDuPersonnage;
    PersonnageVie * vieDuPersonnage;
    PersonnageProjectile * personnageProjectile;
    GameOver * gameOver;

};

#endif // JEUX_H
