//
// Created by tungsten on 12/18/2020.
//
#ifndef SPRITE_BOMBSPRITE_H
#define SPRITE_BOMBSPRITE_H
#include"Sprite.h"

class BombSprite: public Sprite{
private:
    int ttl;
public:
    static ACL_Image self;
    static void initSelfPic();
    BombSprite();
    virtual ~BombSprite();
    virtual void draw() override;
    virtual void timeChange() override;
    virtual void spell() override;
    int timeToLive(){
        return ttl;
    }
};
#endif //SPRITE_BOMBSPRITE_H
