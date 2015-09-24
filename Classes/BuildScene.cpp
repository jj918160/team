//
//  BuildScene.cpp
//  1507demo
//
//  Created by mac on 15-7-29.
//
//

#include "Manager_Player_Cache.h"
#include "BuildScene.h"
#include "Base_Build.h"

Scene* BuildScene::createScene()
{
    
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = BuildScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}
bool BuildScene::init()
{

    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    //这个函数记录你可以建筑的信息，出来后的BS_VforB就是你可以建筑的数量，渲染情况自己考虑
    loading_massage();
    
    type=0;
    
//绘制建筑信息，应该产生一个Layer，并通过Touch弹出
    draw_bulid_massage();
    
    auto touchEvt=EventListenerTouchOneByOne::create();
    
    touchEvt->onTouchBegan=[=](Touch*touch,Event*event){
       
        Vec2 p=touch->getLocation();
        for (int i=1; i<4; i++) {
            
        if (this->getChildByTag(i)->boundingBox().containsPoint(p)) {
            type=i;
            return false;
        }
    }

      
             Vec2 ptouch=touch->getLocation();
             switch (type) {
                 case 1:
                 {
                     auto it=BS_VforB.begin();
                     for (; it!=BS_VforB.end(); it++) {
                          Base_Build*p=(Base_Build*)(*it);
                         if (p->get_name()=="AA") {
                             Sprite*p=Sprite::create();
                         
                             p->initWithFile("1019.2.png");
                             p->setPosition(ptouch);
                             BS_VforB.erase(it);
                             this->addChild(p);
                             break;
                         }
                     }
                 }
                     break;
                     
                 case 2:
                 {
                     auto it=BS_VforB.begin();
                     for (; it!=BS_VforB.end(); it++) {
                         Base_Build*p=(Base_Build*)(*it);
                         if (p->get_name()=="BB") {
                             Sprite*p=Sprite::create();
                             p->initWithFile("1020.0.png");
                              p->setPosition(ptouch);
                             BS_VforB.erase(it);
                             this->addChild(p);
                             break;
                         }
                     }
                 }
                     break;
                 case 3:
                 {
                     auto it=BS_VforB.begin();
                     for (; it!=BS_VforB.end(); it++) {
                         Base_Build*p=(Base_Build*)(*it);
                         CCLOG("in1");
                         if (p->get_name()=="CC") {
                             Sprite*p=Sprite::create();
                             p->initWithFile("1020.1.png");
                              p->setPosition(ptouch);
                             BS_VforB.erase(it);
                             this->addChild(p);
                             break;
                         }
                     }
                 }
                     break;

                     
                 default:
                     break;
             }
             //type=0;
        

        return true;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchEvt,this);
    
    

    //    touchEvt->onTouchEnded=[=](Touch*touch,Event*event){
    //
    //    };

//auto listener=EventListenerTouchOneByOne::create();
//    listener->onTouchBegan=[](Touch*touch,Event*event){
//        auto target=static_cast<Sprite*>(event->getCurrentTarget());//获取事件源并强转成精灵，这种写法注定要绑定给精灵。
//        Vec2 locationInNode=target->convertToNodeSpace(touch->getLocation());//将触摸点转化为触发精灵上的模型坐标
////        //也可以这么写
////     Vec2 locationInLayer=this->convertToNodeSpace(touch->getLocation());
////        if (target->boundingBox().containsPoint(locationInLayer)) {
////            return true;
////        }
//        
//        Size s=target->getContentSize();//点到判断碰撞
//        Rect rect=Rect(0,0,s.width,s.height);
//        if (rect.containsPoint(locationInNode)) {
//            return  true;
//        }
//        return false;
//    };
//    listener->onTouchMoved=[&](Touch*touch,Event*event){
//        auto target=static_cast<Sprite*>(event->getCurrentTarget());
//        target->setPosition(target->getPosition()+touch->getDelta());//getDelta返回前后坐标差
//        //getLocation()-getPreviousLocation()
//    };
//    
//     Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener,getChildByTag(1));
//    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener->clone(),getChildByTag(2));
//    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener->clone(),getChildByTag(3));

    
    return true;
}

void BuildScene::loading_massage(){
    auto mp=Manager_Player_Cache::getInstance();
    
    
    //读取玩家数据，可以建筑的，和等级有关，固定的；
    BS_MforB=mp->MforB;
    //已经建筑的，来源于玩家单例；
    BS_MforBed=mp->MforBed;
    //取得等级1的建筑列表。
    ValueMapIntKey VM=BS_MforB.at(0).asIntKeyMap();
    int num1=VM.at(0).asInt();
    int num2=VM.at(1).asInt();
    int num3=VM.at(2).asInt();
    //根据列表将建筑放入可建筑列表
    for (int i=0; i<num1; i++) {
        Base_Build*p=Base_Build::create();
        // p->initWithFile("1019.2.png");
        p->set_name("AA");
        BS_VforB.pushBack(p);
    }
    for (int i=0; i<num2; i++) {
        Base_Build*p=Base_Build::create();
        // p->initWithFile("1020.0.png");
        p->set_name("BB");
        BS_VforB.pushBack(p);
    }
    for (int i=0; i<num3; i++) {
        Base_Build*p=Base_Build::create();
        //p->initWithFile("1020.1.png");
        p->set_name("CC");
        BS_VforB.pushBack(p);
    }
    //获取已经建筑的
    // BS_VforallBed=mp->VforB;
    auto it=BS_VforallBed.begin();
    //删除已经建过的
    for (;it!=BS_VforallBed.end();it++) {
        for (auto it2=BS_VforB.begin(); it2!=BS_VforB.end(); it2++) {
            {
                Base_Build*p=(Base_Build*)(*it);
                Base_Build*p2=(Base_Build*)(*it2);
                if (p->get_name()==p2->get_name()) {
                    BS_VforB.erase(it2);
                }
            }
        }
    }

}

//
void BuildScene::draw_bulid_massage(){
    auto mp=Manager_Player_Cache::getInstance();
    
    ValueMapIntKey VM=BS_MforB.at(0).asIntKeyMap();

    
    Sprite*p=Sprite::create();
    p->initWithFile("1019.2.png");
    p->setPosition(100,100);
    this->addChild(p,1,1);
    
    Sprite*p2=Sprite::create();
    p2->initWithFile("1020.0.png");
    p2->setPosition(300,100);
    this->addChild(p2,1,2);
    
    Sprite*p3=Sprite::create();
    p3->initWithFile("1020.1.png");
    p3->setPosition(500,100);
    this->addChild(p3,1,3);

}


void BuildScene::onExit(){
    Layer::onExit();
    //将你建筑更新后的信息传给player；
    //player应该有一个change函数响应，改变响相应的容器
}


