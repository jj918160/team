//
//  ListView_SceneTest.cpp
//  1507demo
//
//  Created by mac on 15-8-6.
//
//

#include "ListView_SceneTest.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace ui;
using namespace cocostudio::timeline;

Scene* ListView_SceneTest::createScene()
{
    
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = ListView_SceneTest::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool ListView_SceneTest::init()
{
    //    Widget;
    //    Button;
    //    Text;
    //    TextField;
    //    CheckBox;
    //    ImageView;
    //    LoadingBar;
    //    Slider;
    //    Layout;
    //    ScrollView;
    //    ListView;
    //    PageView
    //////////////////////////////
    // 1. super init first
    
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("Scene.csb");
    
    addChild(rootNode,0,1);
    
 //Scale9Sprite
    
 
    
 // list=static_cast<ListView*>(rootNode->getChildByTag(5));
    
    ListView*list=static_cast<ListView*>(rootNode->getChildByTag(5));
    
    
      Button*but=static_cast<Button*>(rootNode->getChildByTag(6));
    
     ImageView*img=static_cast<ImageView*>(rootNode->getChildByTag(7));
   
    
    list->setItemModel(but);
    
    for (int i=0; i<10; i++) {
        list->pushBackDefaultItem();
    }
    CCLOG("in");
       list->setItemModel(img);
    list->pushBackDefaultItem();
    list->pushBackDefaultItem();
    list->pushBackDefaultItem();
   // list->pushBackCustomItem((Widget*)img);
     CCLOG("in");
   // list->pushBackCustomItem(img);
    
    list->addEventListener([=](Ref*pSender,ListView::EventType type){
        switch (type) {
            case ListView::EventType::ON_SELECTED_ITEM_START:
            {
                //ListView*listview=static_cast<ListView*>(pSender);
                CCLOG("index:%zd",list->getCurSelectedIndex());
            }
                break;
            case ListView::EventType::ON_SELECTED_ITEM_END:
            {
               // ListView*listview=static_cast<ListView*>(pSender);
                CCLOG("index2:%zd",list->getCurSelectedIndex());
            }

                
            default:
                break;
        }
    });
   
    
    return true;
}
