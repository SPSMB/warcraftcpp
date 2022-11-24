#include "Footman.hpp"

Footman::Footman(QPointF pos, ResourceManager *rm) : Unit(pos, FOOTMAN, 0.7f, 1, 2, 0, 12)
{
    setMaxHP(60);
    setHP(60);
    QPixmap *spriteSheet = rm->getSprite("FOOTMAN");
    QPixmap *spriteSheetFlipped = rm->getSprite("FOOTMAN_flipped");

       //walk animations

       QList<QList<int>> walk0DegFrames;
       walk0DegFrames.reserve(8);
       walk0DegFrames.append(QList<int>() << 2 << 0);
       walk0DegFrames.append(QList<int>() << 2 << 1);
       walk0DegFrames.append(QList<int>() << 2 << 2);
       walk0DegFrames.append(QList<int>() << 2 << 1);
       walk0DegFrames.append(QList<int>() << 2 << 0);
       walk0DegFrames.append(QList<int>() << 2 << 4);
       walk0DegFrames.append(QList<int>() << 2 << 3);
       walk0DegFrames.append(QList<int>() << 2 << 4);

       Animation *walk0Deg = new Animation(spriteSheet, 48,48, walk0DegFrames, 150, true);

       movementAnims.append(walk0Deg);

       QList<QList<int>> walk45DegFrames;
       walk45DegFrames.reserve(8);
       walk45DegFrames.append(QList<int>() << 1 << 0);
       walk45DegFrames.append(QList<int>() << 1 << 1);
       walk45DegFrames.append(QList<int>() << 1 << 2);
       walk45DegFrames.append(QList<int>() << 1 << 1);
       walk45DegFrames.append(QList<int>() << 1 << 0);
       walk45DegFrames.append(QList<int>() << 1 << 4);
       walk45DegFrames.append(QList<int>() << 1 << 3);
       walk45DegFrames.append(QList<int>() << 1 << 4);

       Animation *walk45Deg = new Animation(spriteSheet, 48,48, walk45DegFrames, 150, true);

       movementAnims.append(walk45Deg);

       QList<QList<int>> walk90DegFrames;
       walk90DegFrames.reserve(8);
       walk90DegFrames.append(QList<int>() << 0 << 0);
       walk90DegFrames.append(QList<int>() << 0 << 1);
       walk90DegFrames.append(QList<int>() << 0 << 2);
       walk90DegFrames.append(QList<int>() << 0 << 1);
       walk90DegFrames.append(QList<int>() << 0 << 0);
       walk90DegFrames.append(QList<int>() << 0 << 4);
       walk90DegFrames.append(QList<int>() << 0 << 3);
       walk90DegFrames.append(QList<int>() << 0 << 4);

       Animation *walk90Deg = new Animation(spriteSheet, 48,48, walk90DegFrames, 150, true);

       movementAnims.append(walk90Deg);

       QList<QList<int>> walk135DegFrames;
       walk135DegFrames.reserve(8);
       walk135DegFrames.append(QList<int>() << 13 << 0);
       walk135DegFrames.append(QList<int>() << 13 << 1);
       walk135DegFrames.append(QList<int>() << 13 << 2);
       walk135DegFrames.append(QList<int>() << 13 << 1);
       walk135DegFrames.append(QList<int>() << 13 << 0);
       walk135DegFrames.append(QList<int>() << 13 << 4);
       walk135DegFrames.append(QList<int>() << 13 << 3);
       walk135DegFrames.append(QList<int>() << 13 << 4);

       Animation *walk135Deg = new Animation(spriteSheetFlipped, 48,48, walk135DegFrames, 150, true);

       movementAnims.append(walk135Deg);

       QList<QList<int>> walk180DegFrames;
       walk180DegFrames.reserve(8);
       walk180DegFrames.append(QList<int>() << 12 << 0);
       walk180DegFrames.append(QList<int>() << 12 << 1);
       walk180DegFrames.append(QList<int>() << 12 << 2);
       walk180DegFrames.append(QList<int>() << 12 << 1);
       walk180DegFrames.append(QList<int>() << 12 << 0);
       walk180DegFrames.append(QList<int>() << 12 << 4);
       walk180DegFrames.append(QList<int>() << 12 << 3);
       walk180DegFrames.append(QList<int>() << 12 << 4);

       Animation *walk180Deg = new Animation(spriteSheetFlipped, 48,48, walk180DegFrames, 150, true);

       movementAnims.append(walk180Deg);

       QList<QList<int>> walk225DegFrames;
       walk225DegFrames.reserve(8);
       walk225DegFrames.append(QList<int>() << 11 << 0);
       walk225DegFrames.append(QList<int>() << 11 << 1);
       walk225DegFrames.append(QList<int>() << 11 << 2);
       walk225DegFrames.append(QList<int>() << 11 << 1);
       walk225DegFrames.append(QList<int>() << 11 << 0);
       walk225DegFrames.append(QList<int>() << 11 << 4);
       walk225DegFrames.append(QList<int>() << 11 << 3);
       walk225DegFrames.append(QList<int>() << 11 << 4);

       Animation *walk225Deg = new Animation(spriteSheetFlipped, 48,48, walk225DegFrames, 150, true);

       movementAnims.append(walk225Deg);

       QList<QList<int>> walk270DegFrames;
       walk270DegFrames.reserve(8);
       walk270DegFrames.append(QList<int>() << 4 << 0);
       walk270DegFrames.append(QList<int>() << 4 << 1);
       walk270DegFrames.append(QList<int>() << 4 << 2);
       walk270DegFrames.append(QList<int>() << 4 << 1);
       walk270DegFrames.append(QList<int>() << 4 << 0);
       walk270DegFrames.append(QList<int>() << 4 << 4);
       walk270DegFrames.append(QList<int>() << 4 << 3);
       walk270DegFrames.append(QList<int>() << 4 << 4);

       Animation *walk270Deg = new Animation(spriteSheet, 48,48, walk270DegFrames, 150, true);

       movementAnims.append(walk270Deg);

       QList<QList<int>> walk315DegFrames;
       walk315DegFrames.reserve(8);
       walk315DegFrames.append(QList<int>() << 3 << 0);
       walk315DegFrames.append(QList<int>() << 3 << 1);
       walk315DegFrames.append(QList<int>() << 3 << 2);
       walk315DegFrames.append(QList<int>() << 3 << 1);
       walk315DegFrames.append(QList<int>() << 3 << 0);
       walk315DegFrames.append(QList<int>() << 3 << 4);
       walk315DegFrames.append(QList<int>() << 3 << 3);
       walk315DegFrames.append(QList<int>() << 3 << 4);

       Animation *walk315Deg = new Animation(spriteSheet, 48,48, walk315DegFrames, 150, true);

       movementAnims.append(walk315Deg);

       //atack animations

       QList<QList<int>> attack0DegFrames;
       attack0DegFrames.reserve(6);
       attack0DegFrames.append(QList<int>() << 8 << 0);
       attack0DegFrames.append(QList<int>() << 8 << 1);
       attack0DegFrames.append(QList<int>() << 7 << 2);
       attack0DegFrames.append(QList<int>() << 7 << 2);
       attack0DegFrames.append(QList<int>() << 8 << 1);
       attack0DegFrames.append(QList<int>() << 8 << 0);

       Animation *attack0Deg = new Animation(spriteSheet, 48,48, attack0DegFrames, 150, true);

       attackAnims.append(attack0Deg);

       QList<QList<int>> attack45DegFrames;
       attack45DegFrames.reserve(6);
       attack45DegFrames.append(QList<int>() << 6 << 4);
       attack45DegFrames.append(QList<int>() << 6 << 3);
       attack45DegFrames.append(QList<int>() << 6 << 2);
       attack45DegFrames.append(QList<int>() << 6 << 2);
       attack45DegFrames.append(QList<int>() << 6 << 3);
       attack45DegFrames.append(QList<int>() << 6 << 4);

       Animation *attack45Deg = new Animation(spriteSheet, 48,48, attack45DegFrames, 150, true);

       attackAnims.append(attack45Deg);

       QList<QList<int>> attack90DegFrames;
       attack90DegFrames.reserve(6);
       attack90DegFrames.append(QList<int>() << 5 << 0);
       attack90DegFrames.append(QList<int>() << 5 << 1);
       attack90DegFrames.append(QList<int>() << 5 << 2);
       attack90DegFrames.append(QList<int>() << 5 << 2);
       attack90DegFrames.append(QList<int>() << 5 << 1);
       attack90DegFrames.append(QList<int>() << 5 << 0);

       Animation *attack90Deg = new Animation(spriteSheet, 48,48, attack90DegFrames, 150, true);

       attackAnims.append(attack90Deg);

       QList<QList<int>> attack135DegFrames;
       attack135DegFrames.reserve(6);
       attack135DegFrames.append(QList<int>() << 8 << 0);
       attack135DegFrames.append(QList<int>() << 8 << 1);
       attack135DegFrames.append(QList<int>() << 8 << 2);
       attack135DegFrames.append(QList<int>() << 8 << 2);
       attack135DegFrames.append(QList<int>() << 8 << 1);
      attack135DegFrames.append(QList<int>() << 8 << 0);

       Animation *attack135Deg = new Animation(spriteSheetFlipped, 48,48, attack135DegFrames, 150, true);

       attackAnims.append(attack135Deg);

       QList<QList<int>> attack180DegFrames;
       attack180DegFrames.reserve(4);
       attack180DegFrames.append(QList<int>() << 14-8 << 0);
       attack180DegFrames.append(QList<int>() << 14-8 << 1);
       attack180DegFrames.append(QList<int>() << 14-7 << 2);
       attack180DegFrames.append(QList<int>() << 14-7 << 2);
       attack180DegFrames.append(QList<int>() << 14-8 << 1);
       attack180DegFrames.append(QList<int>() << 14-8 << 0);

       Animation *attack180Deg = new Animation(spriteSheetFlipped, 48,48, attack180DegFrames, 150, true);

       attackAnims.append(attack180Deg);

       QList<QList<int>> attack225DegFrames;
       attack225DegFrames.reserve(4);
       attack225DegFrames.append(QList<int>() << 14-8 << 0);
       attack225DegFrames.append(QList<int>() << 14-8 << 1);
       attack225DegFrames.append(QList<int>() << 14-8 << 2);
       attack225DegFrames.append(QList<int>() << 14-8 << 2);
       attack225DegFrames.append(QList<int>() << 14-8 << 1);
       attack225DegFrames.append(QList<int>() << 14-8 << 0);

       Animation *attack225Deg = new Animation(spriteSheetFlipped, 48,48, attack225DegFrames, 150, true);

       attackAnims.append(attack225Deg);

       QList<QList<int>> attack270DegFrames;
       attack270DegFrames.reserve(6);
       attack270DegFrames.append(QList<int>() << 9 << 0);
       attack270DegFrames.append(QList<int>() << 9 << 1);
       attack270DegFrames.append(QList<int>() << 9 << 2);
       attack270DegFrames.append(QList<int>() << 9 << 2);
       attack270DegFrames.append(QList<int>() << 9 << 1);
       attack270DegFrames.append(QList<int>() << 9 << 0);

       Animation *attack270Deg = new Animation(spriteSheet, 48,48, attack270DegFrames, 150, true);

       attackAnims.append(attack270Deg);

       QList<QList<int>> attack315DegFrames;
       attack315DegFrames.reserve(6);
       attack315DegFrames.append(QList<int>() << 8 << 0);
       attack315DegFrames.append(QList<int>() << 8 << 1);
       attack315DegFrames.append(QList<int>() << 8 << 2);
       attack315DegFrames.append(QList<int>() << 8 << 2);
       attack315DegFrames.append(QList<int>() << 8 << 1);
       attack315DegFrames.append(QList<int>() << 8 << 0);

       Animation *attack315Deg = new Animation(spriteSheet, 48,48, attack315DegFrames, 150, true);

       attackAnims.append(attack315Deg);


       //death animation

       QList<QList<int>> deathFrames;
       deathFrames.reserve(6);
       deathFrames.append(QList<int>() << 10 << 0);
       deathFrames.append(QList<int>() << 11 << 0);
       deathFrames.append(QList<int>() << 10 << 1);
       deathFrames.append(QList<int>() << 11 << 1);
       deathFrames.append(QList<int>() << 10 << 2);
       deathFrames.append(QList<int>() << 11 << 2);

       Animation *death = new Animation(spriteSheet, 48,48, deathFrames, 150, false);

       deathAnims.append(death);

       setCurrentAnimation(walk270Deg);
}

QRectF Footman::boundingRect() const {
    return QRectF(32,32,36,36);
}
