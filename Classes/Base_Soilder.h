//
//  Base_Soilder.h
//  1507demo
//
//  Created by mac on 15-7-29.
//
//

#ifndef ___507demo__Base_Soilder__
#define ___507demo__Base_Soilder__

#include <stdio.h>
#include "Base_Character.h"
USING_NS_CC;
enum class Soilder_ID{
    A,
    B,
    C,
};//强枚举类型；

class Base_Soilder:public Sprite{
public:
    //接口函数
  inline  Soilder_ID get_ID(){
      return _ID;
  }
  inline  Soilder_ID set_ID(Soilder_ID ID){
        this->_ID=ID;
    }
    
 
    inline  void set_atk(int atk){
        this->_atk=atk;
    }
    
    inline  int get_atk(){
        return _atk;
    }
    
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
//
    
    //*重要函数1；该函数实现一个运动逻辑；参数和返回值严格固定。
    virtual void Action_Logic(Vector<Sprite*>&BS_Build);
    
       
    //*重要函数2;该函数将要用的动画全部传入缓存，后续将写在开始界面和LoadingBar配合读取缓存
    virtual void Loading_Animation();
    //重要函数更新
    void UpDate();
    //这个函数将一个动画添加到缓存,可以自己写
    virtual void load_move_animation(const std::string filename);
    
    Vec2 Destination;
    
    float nearnest;
  
    CREATE_FUNC(Base_Soilder);
    virtual bool init();
    virtual void update(float dt);
    void attack_back(float dt);
    
    
    
private:
    
    std::string name;
    int _hp;
    MoveTo*_moveto;
    //防止Move多次
    bool move;
    bool attack;
    float speed;
    Soilder_ID _ID;
    int _atk;
    Animation_itools*itool;
    //目标精灵。
    Sprite*obj;
   // bool change_obj;
    
    
};
#endif /* defined(___507demo__Base_Soilder__) */
