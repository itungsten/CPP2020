//
// Created by tungsten on 11/22/2020.
//

#include "ThunderSprite.h"
#include "config.h"
#include "acllib.h"
#include "master.h"
#include <cmath>
using namespace std;
extern Object* arr[MAXN+1];
ACL_Image ThunderSprite::self;
void ThunderSprite::initSelfPic() {
    loadImage(THUNDER_PIC,&self);
}
ThunderSprite::ThunderSprite()
:Sprite(THUNDER_SCORE,THUNDER_WIDTH,THUNDER_HEIGHT,THUNDER_VELOCITY,THUNDER),cd(0)
{

}
ThunderSprite::~ThunderSprite()
{

}
void ThunderSprite::draw(){
    putImageTransparent(&self,posX,posY,width,height,RGB(255,255,255));
}
void ThunderSprite::spell() {
    cd=THUNDER_CD;
    ((Master*)arr[0])->setSleep(THUNDER_SLEEP);
}
void ThunderSprite::walk(){
    int oX,oY;arr[0]->getPos(&oX,&oY);
    double dx=oX-posX,dy=oY-posY;
    double dis=(int)sqrt(dx*dx+dy*dy);
    if(dis <= 1.5*PIC_SIZE && cd == 0)spell();
    Sprite::walk();
}
void ThunderSprite::timeChange(){
    if(cd)--cd;
}