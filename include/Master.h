#ifndef MASTER_H
#define MASTER_H
#include "acllib.h"
#include "Object.h"

class Master : public Object{
private:
    int sleepTime;
    static ACL_Image self;
    static ACL_Image light;

public:
    static void initSelfPic();
    void setSleep(int time);
    int getSleep(){
        return sleepTime;
    }
    virtual void timeChange() override;
    Master(int Width,int Height,int Velocity);
    virtual void draw() override ;
    virtual ~Master();
};

#endif
