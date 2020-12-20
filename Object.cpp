//
// Created by tungsten on 11/22/2020.
//
#include <cmath>
#include "Object.h"
#include "config.h"
extern Object* arr[MAXN+1];
void Object::move(int dX,int dY){
    moveTo(posX+ dX * vBase, posY + dY * vBase);
}
void Object::moveTo(int X,int Y){
    posX=X;
    posY=Y;
    if(posX<0)posX=0;
    if(posX+width>getWidth())posX=getWidth()-width;
    if(posY<0)posY=0;
    if(posY+height>getHeight())posY=getHeight()-height;
}

int Object::getScore() {
    return score;
}

void Object::decScore(int sub) {
    score-=sub;
//    if(score<0)score=0;
}
void Object::incScore(int add) {
    score+=add;
    if(score>SCORE_MAX)score=SCORE_MAX;
}
void Object::getPos(int *ptrX, int *ptrY) {
    *ptrX=posX,*ptrY=posY;
}

Object::Object(int s,int x,int y,int w,int h,int v)
        : score(s), posX(x), posY(y), width(w), height(h), vBase(v)
{
}
Object::Object(int s,int w,int h,int v)
        : score(s), width(w), height(h), vBase(v)
{
    int winWidth=getWidth(),winHeight=getHeight();
    int toX=(winWidth/6)+rand()%(int((winWidth*2/3-width)));
    int toY=(winHeight/6)+rand()%(int((winHeight*2/3-height)));
    moveTo(toX,toY);
}
Object::~Object(){

}

bool Object::isConflict(Object *other) {
    int oX,oY;other->getPos(&oX,&oY);
    oX-=posX,oY-=posY;
    double dis=sqrt(oX*oX+oY*oY);
    return dis <= PIC_SIZE / 2;
}
double Object::getFactor() {
    Object* master=arr[0];
    int score=master->score;
    if(score<=FACTOR_THRESHOLD){
        return 1;
    }
    else return (score-FACTOR_THRESHOLD)/FACTOR_RATIO+1;
}