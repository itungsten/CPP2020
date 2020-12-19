//
// Created by tungsten on 12/18/2020.
//

#include "BombSprite.h"
#include "config.h"
#include "acllib.h"
#include "master.h"
#include <cmath>
using namespace std;
extern Object* arr[MAXN+1];
ACL_Image BombSprite::self;
void BombSprite::initSelfPic() {
    loadImage(BOMB_PIC,&self);
}
BombSprite::BombSprite()
        :Sprite(BOMB_SCORE,BOMB_WIDTH,BOMB_HEIGHT,BOMB_VELOCITY,BOMB),ttl(BOMB_TTL)
{

}
BombSprite::~BombSprite()
{

}
void BombSprite::draw(){
    putImageTransparent(&self,posX,posY,width,height,RGB(255,255,255));
}
void BombSprite::spell() {
    Master* master=(Master*)arr[0];
    master->decScore(BOMB_DAMAGE);
}
void BombSprite::timeChange(){
    if(ttl)--ttl;
}