//
//  Base_Build.h
//  1507demo
//
//  Created by mac on 15-7-29.
//
//

#ifndef ___507demo__Base_Build__
#define ___507demo__Base_Build__

#include <stdio.h>
#include "Base_Character.h"
USING_NS_CC;
enum class Build_ID{
    A1,
    B1,
    C1,
};//强枚举类型；


class Base_Build:public Base_Character{
public:
    //接口函数
    inline  Build_ID get_ID(){
        return _ID;
    }
    inline  Build_ID set_ID(Build_ID ID){
        this->_ID=ID;
    }
    
    
    inline  void set_atk(int atk){
        this->_atk=atk;
    }
    
    inline  int get_atk(){
        return _atk;
    }
  

    
    
    //*重要函数1；该函数实现一个运动逻辑；
    virtual void Action_Logic(Vector<Sprite*>BS_Sor);
    //*重要函数2;该函数将要用到的动画传入缓存；
    virtual void Loading_Animation();
    //这个函数将一个动画添加到缓存,可以自己写
    virtual void load_move_animation(const std::string filename);
    //这个变量临时记录攻击点
    Vec2 Destination;
    //这个是建筑的攻击距离
    float attack_distance;
    //这个是是否在攻击的标示符
    bool attack;
    
    CREATE_FUNC(Base_Build);
    virtual bool init();
    virtual void update(float dt);
    
private:
   
    Build_ID _ID;
    int _atk;
    Animation_itools*itool;
};

#endif /* defined(___507demo__Base_Build__) */
