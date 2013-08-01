#include "Header.h"

USING_NS_CC;

Header::Header()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Sprite* background = Sprite::create("Headers/header.png");
    float scale = visibleSize.width/background->getContentSize().width;
    background->setScale(scale);
    this->setContentSize(Size(visibleSize.width,background->getContentSize().height*scale));
    addChild(background);
}