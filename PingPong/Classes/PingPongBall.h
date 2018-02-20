//
// Created by kijato993 on 20/2/18.
//

#ifndef PROJ_ANDROID_STUDIO_PINGPONGBALL_H
#define PROJ_ANDROID_STUDIO_PINGPONGBALL_H

#include "cocos2d.h"

USING_NS_CC;

class PingPongBall: public Sprite
{
private:
    float ppb_deltaVal;
    float ppb_deltaY;
    float ppb_deltaX;
    Rect ppb_boundingRect;

    static Color3B GetRandomColor();

    PingPongBall(float ballVelocity);
    ~PingPongBall();
public:
    static PingPongBall* create(float ballVelocity);
    void update(float delta);
    void SetBounds(Rect& boundingRect);

};


#endif //PROJ_ANDROID_STUDIO_PINGPONGBALL_H
