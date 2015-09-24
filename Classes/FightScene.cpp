//
//  FightScene.cpp
//  1507demo
//
//  Created by mac on 15-7-29.
//
//

#include "FightScene.h"
#include "Base_Build.h"
#include "Base_Soilder.h"
#include "Manager_Player_Cache.h"
using namespace cocos2d;

Scene* FightScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = FightScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}
bool FightScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto mp=Manager_Player_Cache::getInstance();
    //读取玩家建筑信息；
    Vcb=mp->VforB;
    //将建筑绘制到图上。
    auto it=Vcb.begin();
    vc_canput=mp->VforS;
    for (;it!=Vcb.end();it++) {
        Base_Build *t=(Base_Build*) *it;
        Base_Build* bb=Base_Build::create();
        bb->initWithFile("26.2.png");
        bb->setPosition(t->getPosition());
        Vcbforalreadybuild.pushBack(bb);
        this->addChild(bb);
    }
    
    CCLOG("out");
    auto touchEvt=EventListenerTouchOneByOne::create();
    
    touchEvt->onTouchBegan=[=](Touch*touch,Event*event){
        Vec2 p=touch->getLocation();
        if (vc_canput.size()>0) {
            Base_Soilder*s=Base_Soilder::create();
            s->initWithFile("27.2.png");
            s->setPosition(p);
            this->addChild(s);
            s->scheduleUpdate();
            s->scheduleUpdate();
            vc_put.pushBack(s);
            vc_canput.popBack();
        }
        return true;
    };
//    touchEvt->onTouchEnded=[=](Touch*touch,Event*event){
//        
//    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchEvt,this);
    //执行触摸事件
      CCLOG("out");
   // scheduleUpdate();
    return true;
}
//杀敌删除应该的写法。
//void FightScene::update(float dt){
//    for(auto i:Vcbforalreadybuild){
//        Base_Build*bb=(Base_Build*)i;
//        if (bb->get_atk()<=0) {
//            CCLOG("FIBBATK:%d",bb->get_atk());
//            this->removeChild(i);
//        }
//    }
//}

