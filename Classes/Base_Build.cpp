//
//  Base_Build.cpp
//  1507demo
//
//  Created by mac on 15-7-29.
//
//

#include "Base_Build.h"
#include "Base_Soilder.h"
#include "Base_Character.h"
#include "Animation_itools.h"
#include "FightScene.h"
bool Base_Build::init(){
    if (!Base_Character::init()) {
        return false;
    }
    _atk=20;
    Loading_Animation();
    attack=false;
    attack_distance=100;
    _hp=300;
    scheduleUpdate();
    return true;
}

//重要函数1；该函数实现一个运动逻辑；
void Base_Build::Action_Logic(Vector<Sprite*>BS_Sor){
    auto it=BS_Sor.begin();
    for(;it!=BS_Sor.end();it++){
        float Dis=this->getPosition().getDistance((*it)->getPosition());
      //  CCLOG("dis:%f",Dis);
        if(Dis<attack_distance){
           
            Destination=(*it)->getPosition();
           
            AnimationCache* ac=AnimationCache::getInstance();
           
            Animation *a=ac->getAnimation("sleft");
          
            Animate* animate=Animate::create(a);
            this->runAction(animate);
            attack=true;
            return;
        }
    }
    attack=false;
}
//重要函数2;该函数将要用到的动画传入缓存；
void Base_Build::Loading_Animation(){
    load_move_animation("s");
}

void Base_Build::load_move_animation(const std::string name){
    AnimationCache* ac=AnimationCache::getInstance();
    std::string pic_name;
    pic_name=name+"_melee.png";
    Animation*left=itool->makeAnimationfrommixpicture(pic_name,4,4,1,2,4,2,0.2f,true,-1);
    ac->addAnimation(left,name+"left");
    
}

void Base_Build::update(float dt){
   // CCLOG("X:%f,Y:%f",Destination.x,Destination.y);
    //每桢更新目标
    if(attack==true)
        return;
    auto pa=(FightScene*)this->getParent();
    Action_Logic(pa->vc_put);
    //
   
   }
