//
//  BuildScene.h
//  1507demo
//
//  Created by mac on 15-7-29.
//
//

#ifndef ___507demo__BuildScene__
#define ___507demo__BuildScene__

#include <stdio.h>
#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC_EXT;
using namespace cocos2d;
class BuildScene:public Layer{
public:
  
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(BuildScene);
    //可以建筑的，每次升级更新，来源于BS_MforB
    Vector<Sprite*>BS_VforB;
   //已经建筑的,来源于玩家
    Vector<Sprite*>BS_VforallBed;
  //数据表，记录你可以建筑的数量
    ValueMapIntKey BS_MforB;
    //数据表，记录你已经建筑的数量
    ValueMapIntKey BS_MforBed;
   // void callback1(Ref*pSender);
 //   void callback2(Ref*pSender);
    
    void loading_massage();
    void draw_bulid_massage();

    //标示建筑类型
    int type;
    //退出场景，更新玩家内部数据
    virtual void onExit();
};
#endif /* defined(___507demo__BuildScene__) */
