//
// Created by tungsten on 12/18/2020.
//
#ifndef SPRITE_WATERSPRITE_H
#define SPRITE_WATERSPRITE_H
#include"Sprite.h"

class WaterSprite:public Sprite{
private:
    int ttl;
public:
    static ACL_Image self;
    static void initSelfPic();
    WaterSprite();
    virtual ~WaterSprite();
    virtual void draw() override;
    virtual void timeChange() override;
    virtual void spell() override;
    int timeToLive(){
        return ttl;
    }
};
#endif //SPRITE_WATERSPRITE_H
