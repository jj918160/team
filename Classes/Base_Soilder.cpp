//
//  Base_Soilder.cpp
//  1507demo
//
//  Created by mac on 15-7-29.
//
//

#include "Base_Soilder.h"
#include "Animation_itools.h"
#include "Base_Build.h"
#include "FightScene.h"

//重要函数1；该函数实现一个运动逻辑；
void Base_Soilder::Action_Logic(Vector<Sprite*>&BS_Build){
 
    auto it=BS_Build.begin();
    //老目标不变
      Vec2 NewDestination=Destination;
    for(;it!=BS_Build.end();it++){
        float  Dis=this->getPosition().distance((*it)->getPosition());
        
        if(Dis<nearnest){
            nearnest=Dis;
            NewDestination=(*it)->getPosition();
            obj=(*it);
           
        }
    }
    if (NewDestination!=Destination) {
       move=false;
        Destination=NewDestination;
    }
}


//重要函数2;该函数将要用到的动画传入缓存；
void Base_Soilder::Loading_Animation(){
    load_move_animation("xh");
}

void Base_Soilder::load_move_animation(const std::string name){
    AnimationCache* ac=AnimationCache::getInstance();
    std::string pic_name;
    pic_name=name+".png";
    Animation*left=itool->makeAnimationfrommixpicture(pic_name,4,4,1,2,4,2,0.2f,true,-1);
    ac->addAnimation(left,name+"left");
    Animation*up=itool->makeAnimationfrommixpicture(pic_name,4,4,1,1,4,1,0.2f,true,-1);
    ac->addAnimation(up,name+"up");

}

bool Base_Soilder::init(){
    if (!Sprite::init()) {
        return false;
    }
    Loading_Animation();
    AnimationCache* ac=AnimationCache::getInstance();
    Animation *a=ac->getAnimation("xhleft");
    Animate* animate=Animate::create(a);
    this->runAction(animate);
    _atk=5;
    nearnest=2000;
    move=false;
    attack=false;
    scheduleUpdate();
    
    return true;
}

void Base_Soilder::UpDate(){
    scheduleUpdate();
}
void Base_Soilder::update(float dt){
    //每桢更新目标
   
    auto pa=(FightScene*)this->getParent();
    //拆完，胜利
    if (pa->Vcbforalreadybuild.size()==0) {
        stopAllActions();
        return;
    }
 Base_Build*bb=(Base_Build*)obj;
   
    
    Action_Logic(pa->Vcbforalreadybuild);
     float  Dis=this->getPosition().distance(Destination);
    
    
    
  //到距离内时，开始进攻。
    if (Dis<=20&&!attack) {
        attack=true;
        //停止移动，攻击
        this->stopAllActions();
        
        AnimationCache* ac=AnimationCache::getInstance();
        Animation *a=ac->getAnimation("xhup");
        Animate* animate=Animate::create(a);
        this->runAction(animate);
        schedule(
                     schedule_selector(Base_Soilder::attack_back)
                     ,0.1f);
        
        return;
    }
    //移动过程中，如果目标被摧毁，更换目标
    if (move==true) {
        return;
    }
    else{
        //this->stopAction(_moveto);
        this->stopAllActions();
        AnimationCache* ac=AnimationCache::getInstance();
        Animation *a=ac->getAnimation("xhleft");
        Animate* animate=Animate::create(a);
        this->runAction(animate);
        _moveto=CCMoveTo::create(Dis/50, Destination);
        this->runAction(_moveto);
        move=true;
    }
}

void Base_Soilder::attack_back(float dt){
  //  CCLOG("5");
    Base_Build*bb=(Base_Build*)obj;
    
    CCLOG("Hp:%d",bb->get_hp());
    
     // CCLOG("BSATK:%d",bb->get_atk());
    bb->set_hp(bb->get_hp()-this->get_atk());
     auto pa=(FightScene*)this->getParent();
    if (bb->get_hp()<=0) {
    pa->Vcbforalreadybuild.eraseObject(obj);
    pa->removeChild(obj);
    attack=false;
    move=false;
    nearnest=10000;
        unschedule(schedule_selector(Base_Soilder::attack_back));
    }
}