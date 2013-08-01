#ifndef __BASE_GAME_H__
#define __BASE_GAME_H__

#include "cocos2d.h"

class BaseGame : public cocos2d::Layer
{
public:
    virtual bool init();

    template <class T>
    static cocos2d::Scene* scene()
	{
        cocos2d::Scene * scene = NULL;
		do
		{
			scene = cocos2d::Scene::create();
			CC_BREAK_IF(! scene);
			T *pRet = new T();
            
            if (pRet && pRet->init())
            {
                pRet->autorelease();
            }
            else
            {
                delete pRet;
                pRet = NULL;
            }       
			scene->addChild(pRet);
            
		} while (0);	
		return scene;
	}
    
};

#endif // __BASE_GAME_H__
