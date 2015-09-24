//
//  ListView_SceneTest.h
//  1507demo
//
//  Created by mac on 15-8-6.
//
//

#ifndef ___507demo__ListView_SceneTest__
#define ___507demo__ListView_SceneTest__

#include <stdio.h>

class ListView_SceneTest : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(ListView_SceneTest);
    

    
    
};

#endif /* defined(___507demo__ListView_SceneTest__) */
