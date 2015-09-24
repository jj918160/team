//
//  Base_Character.h
//  1507demo
//
//  Created by mac on 15-7-29.
//
//

#ifndef ___507demo__Base_Character__
#define ___507demo__Base_Character__

#include <stdio.h>
USING_NS_CC;
class Base_Build;
class Base_Soilder;
class Animation_itools;
class Base_Character:public Sprite{
public:
    inline  void set_hp(int hp){
        this->_hp=hp;
    }
    
    inline  int get_hp(){
        return _hp;
    }
    
    inline  void set_name(std::string name){
        this->_name=name;
    }
    inline  std::string get_name(){
        return _name;
    }
  
    //重要函数;该函数将要用到的动画传入缓存；
  virtual void Loading_Animation()=0;
    virtual bool init();
    
    
protected:
    std::string name;
    int _hp;
};

#endif /* defined(___507demo__Base_Character__) */
