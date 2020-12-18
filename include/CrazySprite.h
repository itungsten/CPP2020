//
// Created by tungsten on 11/22/2020.
//

#ifndef SPRITE_CRAZYSPRITE_H
#define SPRITE_CRAZYSPRITE_H
#include "Sprite.h"

class CrazySprite:public Sprite {
private:
public:
    static ACL_Image self;
    static void initSelfPic();
    CrazySprite();
    virtual ~CrazySprite();
    virtual void draw() override;
    virtual void walk() override;
};


#endif //SPRITE_CRAZYSPRITE_H
