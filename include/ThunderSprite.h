//
// Created by tungsten on 11/22/2020.
//

#ifndef SPRITE_THUNDERSPRITE_H
#define SPRITE_THUNDERSPRITE_H
#include "Sprite.h"

class ThunderSprite:public Sprite {
private:
    int cd;
public:
    static ACL_Image self;
    static void initSelfPic();
    ThunderSprite();
    virtual ~ThunderSprite();
    virtual void draw() override;
    virtual  void walk() override ;
    virtual void timeChange() override;
    virtual void spell() override;
};

#endif //SPRITE_THUNDERSPRITE_H
