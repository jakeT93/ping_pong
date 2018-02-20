//
// Created by kijato993 on 20/2/18.
//

#include "GamePlayScene.h"
#include "PingPongBall.h"

USING_NS_CC;

Scene* GamePlayScene::createScene()
{
    return GamePlayScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

void GamePlayScene::CreateAndAddRandomPingPongBall(Vec2 origin, cocos2d::Size visibleSize)
{
    auto ball = PingPongBall::create(rand()%10);
    ball->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    Rect visibleRect = Rect(0,0,visibleSize.width, visibleSize.height);
    ball->SetBounds(visibleRect);
    ball->setScale(0.5f);
    this->addChild(ball);
}

// on "init" you need to initialize your instance
bool GamePlayScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            CC_CALLBACK_1(GamePlayScene::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    CreateAndAddRandomPingPongBall(origin, visibleSize);

    auto listener1 = EventListenerTouchOneByOne::create();

// trigger when you push down
    listener1->onTouchBegan = [](Touch* touch, Event* event){
        // your code
        return true; // if you are consuming it
    };

// trigger when moving touch
    listener1->onTouchMoved = [](Touch* touch, Event* event){
        // your code
    };

// trigger when you let up
    listener1->onTouchEnded = [=](Touch* touch, Event* event){
        CreateAndAddRandomPingPongBall(origin, visibleSize);
    };

// Add listener
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, this);


    return true;
}


void GamePlayScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->popScene();

}