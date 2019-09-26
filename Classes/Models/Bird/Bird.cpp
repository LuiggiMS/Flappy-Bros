#include "Bird.h"
#include "Definitions.h"

USING_NS_CC;

Bird::Bird( cocos2d::Layer *layer )
{
    // ------ Lambda Expresion ------
    auto calculateBodyCircleBird  = [] (float width){
        return width/2;
    };
    // ------ Lambda Expresion ------
    auto getBirdPos  = [] (float x, float y){
        return x / 2 + y;
    };
    
    visibleSize = Director::getInstance( )->getVisibleSize( );
    origin = Director::getInstance( )->getVisibleOrigin( );
    
    flappyBird = Sprite::create( "Bird.png" );
    flappyBird->setPosition( Point(getBirdPos(visibleSize.width, origin.x),  getBirdPos(visibleSize.height, origin.y)) );
    
    auto flappyBody = PhysicsBody::createCircle(calculateBodyCircleBird(flappyBird->getContentSize().width));
    flappyBody->setCollisionBitmask( BIRD_COLLISION_BITMASK );
    flappyBody->setContactTestBitmask( true );
    
    flappyBird->setPhysicsBody( flappyBody );
    
    layer->addChild( flappyBird, 100 );
    
    isFalling = true;
}

void Bird::Fall( )
{
    // ------ Lambda Expresion ------
    auto calculatePosX  = [] (float x, float y){
        return x/2 + y;
        
    };
    // ------ Lambda Expresion ------
    auto calculatePosY  = [] (float x, float y, bool isFalling){
        if (isFalling)
            return x - (BIRD_FALLING_SPEED *y);
        else
            return x + (BIRD_FALLING_SPEED *y);
    };
    
    if ( true == isFalling )
    {
        flappyBird->setPositionX( calculatePosX(visibleSize.width, origin.x) );
        flappyBird->setPositionY( calculatePosY(flappyBird->getPositionY(), visibleSize.height, isFalling));
    }
    else
    {
        flappyBird->setPositionX( calculatePosX(visibleSize.width, origin.x) );
        flappyBird->setPositionY( calculatePosY(flappyBird->getPositionY(), visibleSize.height, isFalling));
    }
}

void Bird::Fly( ) {
    CocosDenshion::SimpleAudioEngine::getInstance( )->playEffect( "Sounds/Wing.mp3" ); // Reproducir sonido de impulso
    isFalling = false;
}

void Bird::StopFlying( ) {
    isFalling = true;
}



