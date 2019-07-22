#ifndef PERSONNAGEPROJECTILE_H
#define PERSONNAGEPROJECTILE_H

#include <QGraphicsTextItem>

class PersonnageProjectile: public QGraphicsTextItem{
    public:
        // Constructeur
        PersonnageProjectile(QGraphicsItem * parent=0);
        // Accesseur
        int getNbDeProjectile();
        // Setteur
        void setNbDeProjectile(int nbDeProjectileParametre);
        // Autre méthodes
        void affichageNbDeProjectile();
        void diminutionProjectile();
        void augmentationProjectile();
    private:
        int nbDeProjectileDuPersonnage;
};

#endif // PERSONNAGEPROJECTILE_H
