//
// Created by tungsten on 12/18/2020.
//

#include "FireSprite.h"
#include "config.h"
#include "acllib.h"
#include "master.h"
#include <cmath>
using namespace std;
extern Object* arr[MAXN+1];
ACL_Image FireSprite::self;
void FireSprite::initSelfPic() {
    loadImage(FIRE_PIC,&self);
}
FireSprite::FireSprite()
        :Sprite(FIRE_SCORE,FIRE_WIDTH,FIRE_HEIGHT,FIRE_VELOCITY,FIRE_HP)
{

}
FireSprite::~FireSprite()
{

}
void FireSprite::draw(){
    putImageTransparent(&self,posX,posY,width,height,RGB(255,255,255));
}
void FireSprite::spell() {
    cd=FIRE_CD;
    Master* master=(Master*)arr[0];
    master->decScore(FIRE_DAMAGE);
}
void FireSprite::walk(){
    int oX,oY;arr[0]->getPos(&oX,&oY);
    double dx=oX-posX,dy=oY-posY;
    double dis=(int)sqrt(dx*dx+dy*dy);
    if(dis <= PIC_SIZE*2&&!cd)spell();
    Sprite::walk();
}
void FireSprite::timeChange(){
    if(cd)--cd;
}