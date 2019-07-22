#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "personnage.h"
#include "projectile.h"
#include <QGraphicsView>
#include <QLabel>
#include <QPixmap>
#include <QPalette>
#include <QTimer>
#include <personnagescore.h>
#include "jeux.h"

/*
   Page: main.cpp

   ### Intro
   Les notions que j'utilise ici, sont basé d'un tutoriel sur C+1 QT Game programming.

   ### Partie 1: Déco

   On va utiliser 4 librairie/Classes:
    - QGraphicsScene
    - QGraphicsItem (GGraphicsRectItem qui est une subclasse de QGraphicsItem)
    - QGraphicsView
    - QLabel pour accéder à la propriétée pixmap pour ajouter une image

   QGraphicsScene est une sorte de container/Map pour nos objets graphics.
   QGraphicsItem contien les item de la scene, si on a un element dans notre scene, ce dernier devra dérivée de QGraphicsItem.
   GGraphicsView qui est une widget qui est utilisé pour visiualiser les scenes

   ### Partie 2: Events

   Grâce au events (keyPressedEvents() et QKeyEvents()),
   ON VA POUVOIR DéFINIR LES éVNEMENTS DU TYPE QUAND, un utilisateur
   fait un clic de souris.
   Event Proppagation system -> Quel objet reagit en premiers quand l'événements a lieu

   ### Partie 3: Tirée avec la barre d'espace

   Utilisation de QTimer, signals and slots (connect function), QObject and Q_Object macro

   ### Partie 4: coordinnation

   Utilisation de:
    - QGraphicsScene's sceneRect
    - QGraphicView's sceneRect
    - QGraphicView coordinates vs QGraphics coordinates vs QGraphicsItem coorinates

  ### Partie 5: Ajoutons les ennemies

  Utilisation de:
    - collidingItems()
    - QTimer and coordinates systems

  ### Partie 6: Ajout de la santé du joueur et du score

  Utilisation de:
    - parents and children
    - QGraphicsTextItem, setPlainText(), setFont(), setDefaultTextColor()

*/

Jeux * jeux;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow fenêtreDeBienvenue;
    fenêtreDeBienvenue.show();

    //jeux = new Jeux();

    return a.exec();
}
