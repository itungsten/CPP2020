//
// Created by tungsten on 11/22/2020.
//
#include "config.h"
#include "acllib.h"
#include "CrazySprite.h"
ACL_Image CrazySprite::self;
void CrazySprite::initSelfPic() {
    loadImage(CRAZY_PIC,&self);
}
CrazySprite::CrazySprite()
:Sprite(CRAZY_SCORE,CRAZY_WIDTH,CRAZY_HEIGHT,CRAZY_VELOCITY,CRAZY)
{

}
CrazySprite::~CrazySprite()
{

}
void CrazySprite::draw(){
    putImageTransparent(&self,posX,posY,width,height,RGB(255,255,255));
}
void CrazySprite::walk() {
    int xflag=(rand()&1)?1:-1;
    int yflag=(rand()&1)?1:-1;
    int xabs=rand()%vMax;
    int yabs=rand()%vMax;
    move(xflag*xabs*getFactor(),yflag*yabs*getFactor());
}