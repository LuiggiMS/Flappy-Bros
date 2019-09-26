#include "MainMenuScene.h"
#include "GameScene.h"
#include "Definitions.h"
#include "Nivel.h"
USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto backgroundSprite = Sprite::create( "Backgroun Main Scene2.png" );
    backgroundSprite->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y ) );
    
    this->addChild( backgroundSprite );
        
    auto playItem = MenuItemImage::create( "play_button.png", "play_button_clicked.png", CC_CALLBACK_1( MainMenuScene::GoToGameScene, this ) );
    playItem->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y ) );
    
    auto menu = Menu::create( playItem, NULL );
    menu->setPosition( Point::ZERO );
    
    this->addChild( menu );
    
    CocosDenshion::SimpleAudioEngine::getInstance( )->stopBackgroundMusic();
    CocosDenshion::SimpleAudioEngine::getInstance( )->playBackgroundMusic("Sounds/intro_main_scene.m4a");
    
    return true;
}

void MainMenuScene::GoToGameScene( cocos2d::Ref *sender )
{
        
    Lista<Nivel*> niveles;
    niveles.insertarFinal(new Nivel(3.0, 5));
    niveles.insertarFinal(new Nivel(2.0, 10));
    niveles.insertarFinal(new Nivel(1.8, 11));
    niveles.insertarFinal(new Nivel(1.6, 12));
    niveles.insertarFinal(new Nivel(1.5, 13));
    niveles.insertarFinal(new Nivel(1.4, 14));
    niveles.insertarFinal(new Nivel(1.3, 20));
    niveles.insertarFinal(new Nivel(1.2, 20));
    
    auto scene = GameScene::createScene(niveles, 0);
    
    Director::getInstance( )->replaceScene( TransitionFade::create( TRANSITION_TIME, scene ) );
}
