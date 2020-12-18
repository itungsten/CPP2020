//
// Created by tungsten on 12/18/2020.
//

#include "WaterSprite.h"
#include "config.h"
#include "acllib.h"
#include "master.h"
#include <cmath>
using namespace std;
extern Object* arr[MAXN+1];
ACL_Image WaterSprite::self;
void WaterSprite::initSelfPic() {
    loadImage(WATER_PIC,&self);
}
WaterSprite::WaterSprite()
        :Sprite(WATER_SCORE,WATER_WIDTH,WATER_HEIGHT,WATER_VELOCITY,WATER_HP),ttl(WATER_TTL)
{

}
WaterSprite::~WaterSprite()
{

}
void WaterSprite::draw(){
    putImageTransparent(&self,posX,posY,width,height,RGB(255,255,255));
}
void WaterSprite::spell() {
    Master* master=(Master*)arr[0];
    master->decScore(WATER_DAMAGE);
}
void WaterSprite::timeChange(){
    if(ttl)--ttl;
}