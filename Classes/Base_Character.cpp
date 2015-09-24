//
//  Base_Character.cpp
//  1507demo
//
//  Created by mac on 15-7-29.
//
//

#include "Base_Character.h"
bool Base_Character::init(){
    if (!Sprite::init()) {
        return false;
    }
    
    return true;
}