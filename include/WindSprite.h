//
// Created by tungsten on 11/22/2020.
//
#ifndef SPRITE_WINDSPRITE_H
#define SPRITE_WINDSPRITE_H
#include "Sprite.h"

class WindSprite:public Sprite {
private:
public:
    static ACL_Image self;
    static void initSelfPic();
    WindSprite();
    virtual ~WindSprite();
    virtual void draw() override;
    virtual  void walk() override ;
};
#endif //SPRITE_WINDSPRITE_H
