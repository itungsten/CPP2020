#include "acllib.h"
#include "Master.h"
#include "config.h"
#include "CrazySprite.h"
#include "WindSprite.h"
#include "ThunderSprite.h"
#include "FireSprite.h"

#include<ctime>

void startTimer(int timerID, int timeinterval);
void cancelTimer(int timerID);
Object* arr[MAXN+1];
int cnt;

ACL_Sound backSound;
ACL_Sound getPoint;
ACL_Image background;

void timerCallBack(int timerID);
void keyboardCallBack(int key,int event);
void initPic();
void initObjs();
void rePaint();
void printWelcome();
void genSprite();

int Setup()
{
    cnt=0;
    srand(time(NULL));
    initPic();
	initWindow(WINDOW_TITLE,DEFAULT,DEFAULT,WINDOW_WIDTH,WINDOW_HEIGHT);
	initObjs();

    loadSound(BACK_MUSIC, &backSound);
    loadSound(POINT_MUSIC,&getPoint);
    playSound(backSound,IS_REPEAT);

    registerTimerEvent(timerCallBack);
    registerKeyboardEvent(keyboardCallBack);

	beginPaint();
	setTextBkColor(RGB(152,226,239));
    setTextSize(FONT_SIZE);
    setTextFont(FONT_NAME);
    printWelcome();
	endPaint();

	return 0;
}
void timerCallBack(int timerID){
    switch(timerID){
        case SECOND_TIMER:
            for(int i=0;i<cnt;++i){
                if(arr[i])arr[i]->timeChange();
            }
            break;
        case FRESH_TIMER:
            rePaint();
            break;
        case BIRTH_TIMER:
            genSprite();
            break;
        default:
            break;
    }
}
void keyboardCallBack(int key,int event){
    static bool up=0,down=0,left=0,right=0;
    if(event==KEY_DOWN){
        switch(key){
            case VK_UP:
                up=1;
                break;
            case VK_DOWN:
                down=1;
                break;
            case VK_LEFT:
                left=1;
                break;
            case VK_RIGHT:
                right=1;
                break;
        }
    }
    if(event==KEY_UP){
        switch(key){
            case VK_UP:
                up=0;
                break;
            case VK_DOWN:
                down=0;
                break;
            case VK_LEFT:
                left=0;
                break;
            case VK_RIGHT:
                right=0;
                break;
            case VK_RETURN:
                startTimer(SECOND_TIMER,1000);
                startTimer(FRESH_TIMER,FRESH_INTERVAL);
                startTimer(BIRTH_TIMER,BIRTH_INTERVAL);
                break;
        }
    }
    Master* tmp=(Master* )arr[0];
    if(!tmp->getSleep())tmp->move(right-left,down-up);
}
void initPic(){
    loadImage(BACKGROUND_PIC,&background);
    Master::initSelfPic();
    CrazySprite::initSelfPic();
    WindSprite::initSelfPic();
    ThunderSprite::initSelfPic();
    FireSprite::initSelfPic();
}
void printWelcome(){
    ACL_Image page;
    loadImage(WEL_PIC,&page);
    putImageScale(&page,0,0,getWidth(),getHeight());
}
void initObjs(){
    arr[cnt++]=new Master(PIC_SIZE + 10, PIC_SIZE + 10, MASTER_V);
    arr[cnt++]=(Object*)new CrazySprite();
    arr[cnt++]=(Object*)new WindSprite();
    arr[cnt++]=(Object*)new ThunderSprite();
    arr[cnt++]=(Object*)new FireSprite();
}
void rePaint(){
    beginPaint();
//            clearDevice();
    putImageScale(&background,0,0,getWidth(),getHeight());
    for(int i=1;i<MAXN+1;++i){
        if(!arr[i])continue;
        if(arr[0]->isConflict(arr[i])){
            if(((Master* )arr[0])->getSleep())break;
            playSound(getPoint,0);
            arr[0]->incScore(arr[i]->getScore());
            free(arr[i]);
            arr[i]=nullptr;
            --cnt;
        }
    }
    for(int i=1;i<MAXN+1;++i){
        if(!arr[i])continue;
        ((Sprite*) arr[i])->walk();
        arr[i]->draw();
    }
    arr[0]->draw();
    endPaint();
}
void genSprite(){
    if(cnt==MAXN+1)return;
    for(int i=1;;++i){
        if(!arr[i]){
            int deci=rand()%KIND;
            switch(deci){
                case CRAZY:
                    arr[i]=new CrazySprite();
                    break;
                case WIND:
                    arr[i]=new WindSprite();
                    break;
                case THUNDER:
                    arr[i]=new ThunderSprite();
                    break;
                case FIRE:
                    arr[i]=new FireSprite();
            }
            ++cnt;
            return;
        }
    }
}