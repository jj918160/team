//
//  CityScene.h
//  1507demo
//
//  Created by mac on 15-7-29.
//
//

#ifndef ___507demo__CityScene__
#define ___507demo__CityScene__

#include <stdio.h>
using namespace cocos2d;
class CityScene:public Layer{
public:

    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(CityScene);
    void callback1(Ref*pSender);
    void callback2(Ref*pSender);
     void callback3(Ref*pSender);
};

#endif /* defined(___507demo__CityScene__) */
