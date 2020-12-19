//
// Created by tungsten on 11/22/2020.
//
#include "Sprite.h"
#include "acllib.h"
#include "config.h"
#include <cmath>
using namespace  std;
Sprite::Sprite(int Score,int Width,int Height,int Velocity,int Hp)
: Object(Score,Width,Height,Velocity), type(Hp)
{
    tarX=(rand()%LUCK_NUM)+1;
    tarY=(rand()%LUCK_NUM)+1;
    double tar=sqrt(tarX*tarX+tarY*tarY);
    tarX/=tar,tarY/=tar;
}
void Sprite::walk() {
    //virtual base
    if(posX==0||posX==getWidth()-width)tarX*=-1;
    if(posY==0||posY==getHeight()-height)tarY*=-1;
    move(vMax*tarX*getFactor(),getFactor()*vMax*tarY);
}