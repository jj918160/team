//
//  Manager_Player_Cache.h
//  1507demo
//
//  Created by mac on 15-7-29.
//
//

#ifndef ___507demo__Manager_Player_Cache__
#define ___507demo__Manager_Player_Cache__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
class Base_Soilder;
class Base_Build;


class Manager_Player_Cache{
public:
  
    //记录你拥有的兵，这个的更新来源于BuildingScene
    Vector<Sprite*>VforS;
    
        //这个记录你的建筑信息
    //BuildingScene每次对建筑的移动操作都要响应更新这个Vector。
    Vector<Sprite*>VforB;
    
        //这个记录你可以建筑的建筑数量和类型,和你的等级有关。
    ValueMapIntKey MforB;
    
    //这个记录当前建筑数量和类型,每次新增建筑都要响应更新这个ValueMapIntKey
    ValueMapIntKey MforBed;
    
    virtual bool init();
    static Manager_Player_Cache* getInstance();
    
private:
    Manager_Player_Cache();
    ~Manager_Player_Cache();
    static Manager_Player_Cache* _cacheInstance; //cache instance
    std::string name;
    int ID;
    //以及一堆自己的属性。
    
    
    
};
#endif /* defined(___507demo__Manager_Player_Cache__) */
