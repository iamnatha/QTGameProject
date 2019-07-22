#ifndef PERSONNAGEVIE_H
#define PERSONNAGEVIE_H

#include <QGraphicsTextItem>

class PersonnageVie: public QGraphicsTextItem{
    public:
        // Constructeur
        PersonnageVie(QGraphicsItem * parent=0);
        // Accesseur
        int getVie();
        // Setteur
        void setVie(int vieParametre);
        // Autre méthodes
        void diminutionVie(int pointDeVie);
        void augmentationVie();

    private:
        int vieDuPersonnage;
};

#endif // PERSONNAGEVIE_H
