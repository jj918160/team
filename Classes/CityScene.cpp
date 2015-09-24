//
//  CityScene.cpp
//  1507demo
//
//  Created by mac on 15-7-29.
//
//

#include "CityScene.h"
#include "FightScene.h"
#include "BuildScene.h"
#include "ListView_SceneTest.h"
Scene* CityScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = CityScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool CityScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

    
    auto bg=Sprite::create("0.0.png");
    //this->setPosition(180,320);
    this->addChild(bg,0,1);
  
    
    auto menu=Menu::create();
    menu->setPosition(0,0);
    
    
    auto lable1=MenuItemFont::create("FightScene",CC_CALLBACK_1(CityScene::callback1,this));
    menu->addChild(lable1,1,1);
    
    auto lable2=MenuItemFont::create("BuildScene",CC_CALLBACK_1(CityScene::callback2,this));
    menu->addChild(lable2,1,2);
    
    auto lable3=MenuItemFont::create("ListView",CC_CALLBACK_1(CityScene::callback3,this));
    menu->addChild(lable3,1,3);
    
    auto lable4=MenuItemFont::create("英雄信息",CC_CALLBACK_1(CityScene::callback2,this));
    menu->addChild(lable4,1,4);
    
    for (int i=1; i<=4; i++) {
        MenuItemFont* item=(MenuItemFont*)menu->getChildByTag(i);
               item->setPosition(0,100*(i-2));
        
    }
    menu->setPosition(480,320);
    this->addChild(menu,1);
        return true;
}

void CityScene::callback1(Ref*pSender){
//    auto ng=NodeGrid::create();
//    this->addChild(ng,4,4);
//    auto bg=Sprite::create("0.0.png");
//    bg->setPosition(480,320);
//    ng->addChild(bg,0);
//    //ng->runAction(PageTurn3D::create(2.0f,Size(20,20)));
//    ng->runAction(Sequence::create(
//                                      WavesTiles3D::create(3.f, Size(20,20), 5, 5),
//                                      WavesTiles3D::create(3.f, Size(20,20), 5, 10),
//                                      WavesTiles3D::create(3.f, Size(20,20), 10, 10),
//                                   NULL)
//                                   );
//    
//   // ng->setPosition(-600,-400);
    
    
         Director::getInstance()->replaceScene(TransitionFade::create(1.5,FightScene::createScene()));
}
void CityScene::callback2(Ref*pSender){
         Director::getInstance()->replaceScene(TransitionFade::create(1.5,BuildScene::createScene()));
}
void CityScene::callback3(Ref*pSender){
    Director::getInstance()->replaceScene(TransitionFade::create(1.5,ListView_SceneTest::createScene()));
}




