//
// Created by kijato993 on 20/2/18.
//

#ifndef PROJ_ANDROID_STUDIO_GAMEPLAYSCENE_H
#define PROJ_ANDROID_STUDIO_GAMEPLAYSCENE_H

#include "cocos2d.h"

class GamePlayScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(GamePlayScene);
};


#endif //PROJ_ANDROID_STUDIO_GAMEPLAYSCENE_H
