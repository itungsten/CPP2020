//
// Created by tungsten on 12/18/2020.
//

#ifndef SPRITE_FIRESPRITE_H
#define SPRITE_FIRESPRITE_H
#include"Sprite.h"
class FireSprite:public Sprite {
private:
    int cd=0;
public:
    static ACL_Image self;
    static void initSelfPic();
    FireSprite();
    virtual ~FireSprite();
    virtual void draw() override;
    virtual  void walk() override ;
    virtual void timeChange() override;
    virtual void spell() override;
};


#endif //SPRITE_FIRESPRITE_H
