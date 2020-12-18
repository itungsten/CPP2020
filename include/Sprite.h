// Created by tungsten on 11/22/2020.
//

#ifndef SPRITE_SPRITE_H
#define SPRITE_SPRITE_H

#include "acllib.h"
#include "Object.h"

class Sprite:public Object{
protected:
    double tarX,tarY;

public:
    int hp;
    Sprite(int Score,int Width,int Height,int Velocity,int Hp);
    virtual ~Sprite(){

    }
    virtual void spell(){

    }
    virtual void walk();
};


#endif //SPRITE_SPRITE_H
