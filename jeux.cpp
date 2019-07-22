#include "mainwindow.h"
#include "trunk.h"
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
#include "personnagevie.h"
#include "zelda.h"
#include <QImage>
#include <QBrush>
#include <QMediaPlayer>

/*
   Page: main.cpp

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

  ### Partie 7: Ajout du son, effets

  Utilisation de:
    - Ressource files
    - QMediaPlayer
    - setMedia()
    - QUrl
    - play()

   ### Partie 8: AJout des élément graphics

   Utilisation de:
    - QGraphicsPixmapItem
    - QPixmap
    - QImage


*/

Jeux::Jeux(int niveau, QWidget *parent)
{

    if(niveau == 1){
        qDebug() << "1";
    }
    else if(niveau == 2){
        qDebug() << "2";
    }

    // *********** Scéne **********
    // Création due l'objet score -> Obtenu grâce à #include "jeux.h"
    // qui contien un attribut sceneGame de type QGraphicsScene
    // qui doit être instancié.
    sceneGame = new QGraphicsScene();

    if(niveau == 1){
        sceneGame->setBackgroundBrush(QBrush(QImage(":/Fond2.png")));
    }
    else if(niveau == 2){
        sceneGame->setBackgroundBrush(QBrush(QImage(":/Fond3.jpg")));
    }

    // ********** Item **********
    // Création due l'objet score -> Obtenu grâce à #include "jeux.h"
    // qui contien un attribut joueurPrincipal de type Personnage
    // qui doit être instancié.
    joueurPrincipal = new Zelda();
    // On accéde à la méthode pour déinir les caractéristique du rectangle. On change les dimensions.
    // Taille 100*100 pixels et position dans la View: (0;0)
    // Précédement, le joeur princiapale était un rectangle
    // joueurPrincipal->setRect(0,0,100,100);

    // Maintenant
    // joueurPrincipal->setPixmap(QPixmap(":/Zelda.png"));

    // Ajoutons les items dans la scéne
    sceneGame->addItem(joueurPrincipal);

    // Rendons le item "focusable"
    joueurPrincipal->setFlag(QGraphicsItem::ItemIsFocusable);
    joueurPrincipal->setFocus();

    // ********** View **********
    // Ajoutons une view
    QGraphicsView * viewGame = new QGraphicsView(sceneGame);
    // Pour éviter quand on lance un projectiel que la fen^tre s'agrandisse
    // On fixe donc ScrollBar
    viewGame->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    viewGame->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // Montrons la view grâce à méthode show() de l'objet car par défaut elle est invisible
    viewGame->show();
    // On donne les dimension de la view de jeux
    viewGame->setFixedSize(800, 533);
    // On donne les dimensions de la scéne
    sceneGame->setSceneRect(0, 0, 800, 533);

    // ********** Autres **********
    // On fixe la position initial du joeueur
    joueurPrincipal->setPos(300, 300);

    // ********** Ennemie **********
    QTimer * timer1 = new QTimer();
    // Dans l'objet joeurPrinciaple, il y aune fonction spawn() qui créer des ennemies
    QObject::connect(timer1, SIGNAL(timeout()), joueurPrincipal, SLOT(spawn1()));
    // On crée un ennemie dragon tous les 1000 milli seconde
    // Si on veux changer la vitesse de création d'ennemi, donc d'ennemie sur la fenêtre,
    // faut juste changer ca

    if(niveau == 1){
        timer1->start(1500);
    }
    else if(niveau == 2){
        timer1->start(750);
    }

    // ********* Coin *********
    QTimer * timer2 = new QTimer();
    // Dans l'objet joeurPrinciaple, il y aune fonction spawn() qui créer des ennemies
    QObject::connect(timer2, SIGNAL(timeout()), joueurPrincipal, SLOT(spawn2()));
    // On crée un ennemie dragon tous les 1000 milli seconde
    // Si on veux changer la vitesse de création d'ennemi, donc d'ennemie sur la fenêtre,
    // faut juste changer ca


    if(niveau == 1){
        timer2->start(5000);
    }
    else if(niveau == 2){
        timer2->start(8000);
    }

    // ********* Coeur *********
    QTimer * timer3 = new QTimer();
    // Dans l'objet joeurPrinciaple, il y aune fonction spawn() qui créer des ennemies
    QObject::connect(timer3, SIGNAL(timeout()), joueurPrincipal, SLOT(spawn3()));
    // On crée un ennemie dragon tous les 1000 milli seconde
    // Si on veux changer la vitesse de création d'ennemi, donc d'ennemie sur la fenêtre,
    // faut juste changer ca


    if(niveau == 1){
        timer3->start(15000);
    }
    else if(niveau == 2){
        timer3->start(20000);
    }

    // ********** Score **********
    // Création due l'objet score -> Obtenu grâce à #include "jeux.h"
    // qui contien un attribut scoreDuPersonnage de type PersonnageScore
    // qui doit être instancié.
    scoreDuPersonnage = new PersonnageScore();
    // On ajoute le score à notre scéne
    scoreDuPersonnage->setPos(206, 30);
    sceneGame->addItem(scoreDuPersonnage);

    // ********** Vie du personnage *********
    // Création due l'objet score -> Obtenu grâce à #include "jeux.h"
    // qui contien un attribut vieDuPersonnage de type PersonnageVie
    // qui doit être instancié.
    vieDuPersonnage = new PersonnageVie();
    vieDuPersonnage->setPos(56, 30);
    sceneGame->addItem(vieDuPersonnage);

    // ********** Trunk **********
    // Création due l'objet score -> Obtenu grâce à #include "jeux.h"
    // qui contien un attribut scoreDuPersonnage de type PersonnageScore
    // qui doit être instancié.
    Trunk * trunk1 = new Trunk();
    // On ajoute le score à notre scéne
    trunk1->setPos(146, 100);
    sceneGame->addItem(trunk1);

    Trunk * trunk2 = new Trunk();
    // On ajoute le score à notre scéne
    trunk2->setPos(146, 350);
    sceneGame->addItem(trunk2);

    Trunk * trunk3 = new Trunk();
    // On ajoute le score à notre scéne
    trunk3->setPos(600, 100);
    sceneGame->addItem(trunk3);

    Trunk * trunk4 = new Trunk();
    // On ajoute le score à notre scéne
    trunk4->setPos(600, 350);
    sceneGame->addItem(trunk4);

    if(niveau == 1){
        Trunk * trunk5 = new Trunk();
        // On ajoute le score à notre scéne
        trunk5->setPos(368, 234);
        sceneGame->addItem(trunk5);
    }
    else if(niveau == 2){
        Trunk * trunk5 = new Trunk();
        // On ajoute le score à notre scéne
        trunk5->setPos(368, 100);
        sceneGame->addItem(trunk5);

        Trunk * trunk6 = new Trunk();
        // On ajoute le score à notre scéne
        trunk6->setPos(368, 350);
        sceneGame->addItem(trunk6);
    }

    // ********** Projectile du personnage *********
    // Création due l'objet score -> Obtenu grâce à #include "jeux.h"
    // qui contien un attribut personnageProjectile de type PersonnageProjectile
    // qui doit être instancié.
    personnageProjectile = new PersonnageProjectile();
    personnageProjectile->setPos(356, 30);
    sceneGame->addItem(personnageProjectile);

    // Play Background Music
    QMediaPlayer * backgroundSound = new QMediaPlayer();
    backgroundSound->setMedia(QUrl("qrc:/BackgroundMusic.mp3"));
    backgroundSound->play();

}
