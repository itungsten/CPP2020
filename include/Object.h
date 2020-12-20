//
// Created by tungsten on 11/22/2020.
//

#ifndef SPRITE_OBJECT_H
#define SPRITE_OBJECT_H

#include "acllib.h"

class Object {
protected:
    int score;
    int posX, posY;
    int width, height;
    int vBase;
public:
    void moveTo(int x,int y);

    void move(int dx,int dy);

    virtual void draw()=0;
    void getPos(int *ptrX, int *ptrY);
    int getScore();
    void incScore(int add);
    void decScore(int sub);
    Object(int s,int x,int y,int w,int h,int v);
    Object(int s,int w,int h,int v);
    virtual ~Object();
    virtual void timeChange(){

    }
    bool isConflict(Object* other);
    double getFactor();
};


#endif //SPRITE_OBJECT_H
