//
//  Manager_Player_Cache.cpp
//  1507demo
//
//  Created by mac on 15-7-29.
//
//

#include "Manager_Player_Cache.h"
#include "Base_Soilder.h"
#include "Base_Build.h"
using namespace std;
Manager_Player_Cache* Manager_Player_Cache::_cacheInstance=nullptr;


Manager_Player_Cache* Manager_Player_Cache::getInstance(){
    if (!_cacheInstance) {
        _cacheInstance=new Manager_Player_Cache();
        _cacheInstance->init();
    }
    return _cacheInstance;
}

bool Manager_Player_Cache::init(){
    for (int i=0; i<10; i++) {
        Base_Build *b=Base_Build::create();
        b->initWithFile("26.2");
        b->setPosition(100*i,50*i);
        VforB.pushBack(b);
    }
    for (int i=0; i<10; i++) {
        Base_Soilder*b=Base_Soilder::create();
        b->initWithFile("27.1");
        VforS.pushBack(b);
    }
    
    
    ValueMapIntKey lv1;
    lv1[0]=Value(1);
    lv1[1]=Value(2);
     lv1[2]=Value(3);
    ValueMapIntKey lv2;
    lv2[0]=Value(2);
    lv2[1]=Value(3);
    lv2[2]=Value(5);
    
    MforB[0]=lv1;
    MforB[1]=lv2;
    
    return true;
}

Manager_Player_Cache::Manager_Player_Cache(){
    
}
Manager_Player_Cache::~Manager_Player_Cache(){
    
}
//void Manager_Player_Cache::addSoilder(Base_Soilder s){
//    vecof_S.pushBack(s);
//}
//void Manager_Player_Cache::addBuild(Base_Build b){
//    vecof_B.pushBack(b);
//}