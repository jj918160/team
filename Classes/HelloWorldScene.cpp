#include "HelloWorldScene.h"
#include "CityScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Manager_Player_Cache.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
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
    
    count=0;
    auto rootNode = CSLoader::createNode("MainScene.csb");

    addChild(rootNode,0,1);
    
   //  LoadingBar*load=(LoadingBar*)rootNode->getChildByTag(3);
    
    scheduleUpdate();

    return true;
}
void  HelloWorld::update(float dt){
    if (count>=100) {
        Director::getInstance()->replaceScene(TransitionFade::create(0.5,CityScene::createScene()));
    }
     LoadingBar*load=(LoadingBar*)this->getChildByTag(1)->getChildByTag(3);
    load->setPercent(count++);
   
}