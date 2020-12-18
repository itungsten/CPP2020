//
// Created by tungsten on 11/22/2020.
//

#ifndef SPRITE_CONFIG_H
#define SPRITE_CONFIG_H

#define WINDOW_WIDTH 960
#define WINDOW_HEIGHT 640
#define WINDOW_TITLE "Pokemon GoGoGo!"

#define PIC_SIZE 60

#define FRESH_INTERVAL 30
#define BIRTH_INTERVAL 2*1000

#define  MASTER_V 10

#define BIRTH_TIMER 2
#define FRESH_TIMER 1
#define SECOND_TIMER 0

#define BACK_MUSIC "./source/you.mp3"
#define POINT_MUSIC "./source/point.ogg"
#define MASTER_PIC "./source/master.bmp"
#define CRAZY_PIC "./source/crazy.bmp"
#define WIND_PIC "./source/wind.bmp"
#define FIRE_PIC "./source/fire.bmp"
#define WEL_PIC "./source/wel.jpg"
#define OVER_PIC "./source/over.jpg"
#define THUNDER_PIC "./source/thunder.bmp"
#define WATER_PIC "./source/water.bmp"
#define BACKGROUND_PIC "./source/background.jpg"
#define LIGHT_PIC "./source/light.bmp"

#define IS_REPEAT 1

#define BUF_LEN 25

#define FONT_SIZE 15

#define INIT_SUM 8

#define FONT_NAME "新宋体"

#define CRAZY_HP 1
#define CRAZY_SCORE 1
#define CRAZY_WIDTH PIC_SIZE
#define CRAZY_HEIGHT PIC_SIZE
#define CRAZY_VELOCITY 6

#define WIND_HP 1
#define WIND_SCORE 3
#define WIND_WIDTH PIC_SIZE
#define WIND_HEIGHT PIC_SIZE
#define WIND_VELOCITY 4

#define THUNDER_HP 1
#define THUNDER_SCORE 3
#define THUNDER_WIDTH PIC_SIZE
#define THUNDER_HEIGHT PIC_SIZE
#define THUNDER_VELOCITY 4
#define THUNDER_CD 8
#define THUNDER_SLEEP 3

#define FIRE_HP 1
#define FIRE_SCORE 5
#define FIRE_WIDTH PIC_SIZE
#define FIRE_HEIGHT PIC_SIZE
#define FIRE_VELOCITY 4
#define FIRE_DAMAGE 1
#define FIRE_CD 1

#define WATER_HP -1
#define WATER_SCORE 5
#define WATER_WIDTH PIC_SIZE
#define WATER_HEIGHT PIC_SIZE
#define WATER_VELOCITY 4
#define WATER_DAMAGE 1
#define WATER_TTL 10

#define MAXN 20

#define THUNDER_TIMER_OFFSET MAXN

#define LUCK_NUM 23

#define FACTOR_THRESHOLD 10.0
#define FACTOR_RATIO 30.0

#define SCORE_MAX 999

#define MASTER_HP 5

enum{
    CRAZY=0,WIND,THUNDER,FIRE,WATER,KIND
};

#endif //SPRITE_CONFIG_H
