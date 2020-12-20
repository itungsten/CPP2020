// Created by tungsten on 11/22/2020.
//

#ifndef SPRITE_SPRITE_H
#define SPRITE_SPRITE_H

#include "acllib.h"
#include "Object.h"

class Sprite:public Object{
protected:
    double tarX,tarY;
    int type;
public:
    int getType();
    Sprite(int Score,int Width,int Height,int Velocity,int Type);
    virtual ~Sprite(){

    }
    virtual void spell(){

    }
    virtual void walk();
};


#endif //SPRITE_SPRITE_H
