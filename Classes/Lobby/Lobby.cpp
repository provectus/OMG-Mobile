#include "Lobby.h"
#include "../UI/Header.h"
#include "../Games/DiamondsTreasure/DiamondsTreasure.h"


USING_NS_CC;

Scene* Lobby::scene()
{
    // 'scene' is an autorelease object
    Scene *scene = Scene::create();
    
    // 'layer' is an autorelease object
    Lobby *layer = Lobby::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Lobby::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    Sprite* background = Sprite::create("Lobby/HelloWorld.png");

    background->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    Header* header = new Header();
    header->setPosition(Point(header->getContentSize().width/2, visibleSize.height - header->getContentSize().height/2));
    this->addChild(background, 0);
    this->addChild(header);
    
    return true;
}

void Lobby::onEnterTransitionDidFinish()
{
    Size size = Director::getInstance()->getVisibleSize();
    MenuItemImage *closeItem = MenuItemImage::create(
                                                     "Preview/DTPreview.png",
                                                     "Preview/DTPreviewPressed.png",
                                                     CC_CALLBACK_1(Lobby::playGameCallback, this));
    
	closeItem->setPosition(Point(size.width/2, size.height/2));
    
    Menu* menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    closeItem->setPosition(Point(size.width/2,size.height/2));
    closeItem->setOpacity(0);
    closeItem->setScale(0);
    
    ActionInterval* scale = ScaleTo::create(0.5, 1);
    ActionInterval* scale_ease_inout2 = EaseElasticInOut::create(scale, 0.9f);
    FiniteTimeAction* seq2 = CCSequence::create( (ActionInterval*)scale_ease_inout2,DelayTime::create(0.3), NULL);
    closeItem->runAction(seq2);
    closeItem->runAction(FadeTo::create(0.3,255));
}


void Lobby::playGameCallback(Object* pSender)
{
    TransitionFade * page = TransitionFade::create(1, BaseGame::scene<DiamondsTreasure>());
	Director::getInstance()->replaceScene(page);
}
