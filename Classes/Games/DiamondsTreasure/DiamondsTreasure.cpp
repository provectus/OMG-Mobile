#include "DiamondsTreasure.h"
#include "../../UI/Header.h"
USING_NS_CC;

bool DiamondsTreasure::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    
    Sprite* background = Sprite::create("Games/DiamondsTresure/background.png");
    background->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    background->setScale(visibleSize.width/background->getContentSize().width);
    
    Header* header = new Header();
    header->setPosition(Point(header->getContentSize().width/2, visibleSize.height - header->getContentSize().height/2));
    
    this->addChild(background, 0);
    this->addChild(header);
    
    return true;
}