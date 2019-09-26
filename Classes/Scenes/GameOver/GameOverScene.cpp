#include "GameOverScene.h"
#include "GameScene.h"
#include "MainMenuScene.h"
#include "Definitions.h"

USING_NS_CC;

int score;

Scene* GameOverScene::createScene( unsigned int tempScore )
{
    score = tempScore;
    
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameOverScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameOverScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto backgroundSprite = Sprite::create( "Background.png" );
    backgroundSprite->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y ) );
    
    this->addChild( backgroundSprite );
        
    auto mainMenuItem = MenuItemImage::create( "Menu Button.png", "Menu Button Clicked.png", CC_CALLBACK_1( GameOverScene::GoToMainMenuScene, this ) );
    mainMenuItem->setPosition( Point( visibleSize.width / 2 + origin.x, visibleSize.height / 4 ) );
    
    auto menu = Menu::create(mainMenuItem, NULL );
    menu->setPosition( Point::ZERO );
    
    this->addChild( menu );
    
    //------------------------------------------------------------------------------
    auto highScore = GameOverScene::recoverScore(); // Recuperar puntaje
    
    // Si el puntaje realizado es mayor al puntaje recuperado desde archivo
    if ( score > highScore )
    {
        highScore = score;
        GameOverScene::saveScore(score); // Guardar puntaje
    }
    //------------------------------------------------------------------------------

    __String *tempScore = __String::createWithFormat( "%i", score );
    
    auto currentScore = Label::createWithTTF( tempScore->getCString( ), "fonts/Marker Felt.ttf", visibleSize.height * SCORE_FONT_SIZE );
    currentScore->setPosition( Point( visibleSize.width * 0.25 + origin.x, visibleSize.height / 2 + origin.y ) );
    
    this->addChild( currentScore );
    
    __String *tempHighScore = __String::createWithFormat( "%i", highScore );
    
    auto highScoreLabel = Label::createWithTTF( tempHighScore->getCString( ), "fonts/Marker Felt.ttf", visibleSize.height * SCORE_FONT_SIZE );
    
    highScoreLabel->setColor( Color3B::YELLOW );
    highScoreLabel->setPosition( Point( visibleSize.width * 0.75 + origin.x, visibleSize.height / 2 + origin.y ) );

    this->addChild( highScoreLabel );
    
    return true;
}

void GameOverScene::saveScore(int score){
    __Dictionary *dictionary = __Dictionary::create();
    dictionary->setObject(__Integer::create(score), __String::create("keyScore")->getCString());
    
    __String *fileName = __String::create("scores.plist"); // Nombre de archivo
    __String *filePath = __String::createWithFormat("%s%s",FileUtils::getInstance()->getWritablePath().c_str(), fileName->getCString()); // Nombre de ruta de archivo
    
    dictionary->writeToFile(filePath->getCString());// Guardar diccionario en la ruta especificada
}

int GameOverScene::recoverScore(){
    __String *fileName = __String::create("scores.plist"); // Nombre de archivo
    __String *filePath = __String::createWithFormat("%s%s",FileUtils::getInstance()->getWritablePath().c_str(), fileName->getCString()); // Nombre de ruta de archivo
    
    __Dictionary *dictionary = __Dictionary::createWithContentsOfFile(filePath->getCString()); // Crear diccionario a partir del archivo de la ruta especificada
    int score = dictionary->valueForKey("keyScore")->intValue(); // Obtener el puntaje
    log("Puntaje recuperado: %i", score);
    return score;
}

void GameOverScene::GoToMainMenuScene( cocos2d::Ref *sender )
{
    auto scene = MainMenuScene::createScene( );
    
    Director::getInstance( )->replaceScene( TransitionFade::create( TRANSITION_TIME, scene ) );
}







