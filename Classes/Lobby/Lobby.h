#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class Lobby : public cocos2d::Layer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    void onEnterTransitionDidFinish();
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* scene();
    
    // a selector callback
    void playGameCallback(Object* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(Lobby);
};

#endif // __HELLOWORLD_SCENE_H__
