#ifndef PERSONNAGESCORE_H
#define PERSONNAGESCORE_H

#include <QGraphicsTextItem>

class PersonnageScore: public QGraphicsTextItem{
    public:
        // Constructeur
        PersonnageScore(QGraphicsItem * parent=0);
        // Accesseur
        int getScore();
        // Setteur
        void setScore(int scoreParametre);
        // Autre méthodes
        void augmentationScore();
        void diminutionScore();
    private:
        int scoreDuPersonnage;
};

#endif // PERSONNAGESCORE_H
