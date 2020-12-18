#include "acllib.h"
#include "config.h"
#include "Master.h"
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<ctime>
using namespace  std;

ACL_Image Master::self;
ACL_Image Master::light;
extern int hp;

void Master::draw() {
    putImageTransparent(&self,posX,posY,width,height,RGB(255,255,255));
    if(sleepTime)putImageTransparent(&light,posX,posY,width,height,RGB(255,255,255));
    char buf[BUF_LEN];
    sprintf(buf,"Your Score: %d \t Your HP: %d",score,hp);
    paintText(10,10,buf);
}

void Master::setSleep(int time) {
    sleepTime=sleepTime>time?sleepTime:time;
}
void Master::timeChange(){
    if(sleepTime){
        --sleepTime;
    }
}
Master::Master(int wid, int hei, int vel)
:Object(0,wid,hei,vel),sleepTime(0)
{

}
Master::~Master() {

}

void Master::initSelfPic(){
    loadImage(MASTER_PIC,&self);
    loadImage(LIGHT_PIC,&light);
}