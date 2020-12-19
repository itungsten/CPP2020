//
// Created by tungsten on 11/22/2020.
//

#include "WindSprite.h"
#include "config.h"
#include "acllib.h"
#include <cmath>
using namespace std;
extern Object* arr[MAXN+1];
ACL_Image WindSprite::self;
void WindSprite::initSelfPic() {
    loadImage(WIND_PIC,&self);
}
WindSprite::WindSprite()
:Sprite(WIND_SCORE,WIND_WIDTH,WIND_HEIGHT,WIND_VELOCITY,WIND)
{

}
WindSprite::~WindSprite()
{

}
void WindSprite::draw(){
    putImageTransparent(&self,posX,posY,width,height,RGB(255,255,255));
}
void WindSprite::walk(){
    int oX,oY;arr[0]->getPos(&oX,&oY);
    double dx=oX-posX,dy=oY-posY;
    double dis=(int)sqrt(dx*dx+dy*dy);
    if(dis >= PIC_SIZE * 2){
        Sprite::walk();
        return;
    }
    dx/=dis,dy/=dis;
    move(-1*vMax*dx*getFactor(),-1*vMax*dy*getFactor());
}