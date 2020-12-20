//
// Created by tungsten on 11/22/2020.
//
#include "Sprite.h"
#include "acllib.h"
#include "config.h"
#include <cmath>
using namespace  std;
Sprite::Sprite(int Score,int Width,int Height,int Velocity,int Type)
: Object(Score,Width,Height,Velocity), type(Type)
{
    tarX=(rand()%LUCK_NUM)+5;
    tarY=(rand()%LUCK_NUM)+5;
    double tar=sqrt(tarX*tarX+tarY*tarY);
    tarX/=tar,tarY/=tar;
}
void Sprite::walk() {
    //virtual base
    if(posX==0||posX==getWidth()-width)tarX*=-1;
    if(posY==0||posY==getHeight()-height)tarY*=-1;
    move(vBase * tarX * getFactor(), getFactor() * vBase * tarY);
}

int Sprite::getType() {
    return type;
}
