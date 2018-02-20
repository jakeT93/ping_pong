//
// Created by kijato993 on 20/2/18.
//

#include "PingPongBall.h"

PingPongBall::PingPongBall(float ballVelocity):
ppb_deltaVal(ballVelocity)
{
    ppb_boundingRect.setRect(0,0,0,0);

    ppb_deltaX = ppb_deltaVal/2;
    ppb_deltaY = ppb_deltaX;

    ppb_deltaX *= rand()%2? -1.0f: 1.0f;
    ppb_deltaY *= rand()%2? -1.0f: 1.0f;
}

PingPongBall::~PingPongBall() {

}

PingPongBall* PingPongBall::create(float ballVelocity)
{
    PingPongBall* retPtr = new PingPongBall(ballVelocity);
    if (retPtr && retPtr->initWithFile("pingpong_ball.png"))
    {
        retPtr->setColor(GetRandomColor());
        retPtr->scheduleUpdate();
        retPtr->autorelease();
        return retPtr;
    }
    CC_SAFE_DELETE(retPtr);
    return nullptr;
}

Color3B PingPongBall::GetRandomColor() {
    /*
    const Color3B Color3B::WHITE  (255, 255, 255);
    const Color3B Color3B::YELLOW (255, 255,   0);
    const Color3B Color3B::GREEN  (  0, 255,   0);
    const Color3B Color3B::BLUE   (  0,   0, 255);
    const Color3B Color3B::RED    (255,   0,   0);
    const Color3B Color3B::MAGENTA(255,   0, 255);
    const Color3B Color3B::BLACK  (  0,   0,   0);
    const Color3B Color3B::ORANGE (255, 127,   0);
    const Color3B Color3B::GRAY   (166, 166, 166);
    */

    enum ColorName
    {
        color_WHITE = 0,
        color_YELLOW,
        color_GREEN,
        color_BLUE,
        color_RED,
        color_MAGENTA,
        color_ORANGE
    };
    int randIndex = rand()%8;

    switch((ColorName)randIndex)
    {
        case color_WHITE:
        {
            return Color3B::WHITE;
        }
        case color_YELLOW:
        {
            return Color3B::YELLOW;
        }
        case color_GREEN:
        {
            return Color3B::GREEN;
        }
        case color_BLUE:
        {
            return Color3B::BLUE;
        }
        case color_RED:
        {
            return Color3B::RED;
        }
        case color_MAGENTA:
        {
            return Color3B::MAGENTA;
        }
        default:
            return Color3B::WHITE;
    }

}

void PingPongBall::update(float delta)
{
    Sprite::update(delta);
    log("PingPongBall update: %f", delta);

    this->setPositionY(this->getPositionY() + ppb_deltaY);
    this->setPositionX(this->getPositionX()+ ppb_deltaX);

    if (ppb_boundingRect.size.height > 0 || ppb_boundingRect.size.width >0)
    {
        Vec2 currPos = this->getPosition();
        float textureWidth = this->getBoundingBox().size.width;
        float textureHeight = this->getBoundingBox().size.height;

        if((currPos.x + textureWidth/2) >= ppb_boundingRect.getMaxX() || (currPos.x - textureWidth/2) <= ppb_boundingRect.getMinY() )
        {
            ppb_deltaX *= -1.0f;
            this->setColor(GetRandomColor());
        }

        if((currPos.y) >= ppb_boundingRect.getMaxY() || (currPos.y - textureHeight) <= ppb_boundingRect.getMinY() )
        {
            ppb_deltaY *= -1.0f;
            this->setColor(GetRandomColor());
        }
    }

}

void PingPongBall::SetBounds(Rect& boundingRect)
{
    ppb_boundingRect = boundingRect;
}