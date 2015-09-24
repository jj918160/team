//
//  FightScene.h
//  1507demo
//
//  Created by mac on 15-7-29.
//
//

#ifndef ___507demo__FightScene__
#define ___507demo__FightScene__

#include <stdio.h>
using namespace cocos2d;
class Base_Build;
class Base_Soilder;


class FightScene:public Layer{
public:
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(FightScene);
    //这个是用来初始化的数组
    Vector<Sprite*>Vcb;
    //这个是用来更新互动的数组
    Vector<Sprite*>Vcbforalreadybuild;
     //这个是用来初始化的数组
    Vector<Sprite*>vc_canput;
     //这个是用来更新互动的数组
    Vector<Sprite*>vc_put;
  
  //  void update(float dt);
  //  void callback1(Ref*pSender);
   // void callback2(Ref*pSender);
};
#endif /* defined(___507demo__FightScene__) */
