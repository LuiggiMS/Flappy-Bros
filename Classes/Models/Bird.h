#ifndef __BIRD_H__
#define __BIRD_H__

#include "cocos2d.h"
#include "audio/include/SimpleAudioEngine.h"
using namespace CocosDenshion;
using namespace cocos2d;

class Bird
{
public:
    Bird( Layer *layer );
    void Fall();
    void Fly();
    void StopFlying();
    
private:
    Size visibleSize;
    Vec2 origin;
    Sprite *flappyBird;
    bool isFalling;
};


#endif // __BIRD_H__
