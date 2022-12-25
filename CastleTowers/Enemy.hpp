//
//  Enemy.hpp
//  CastleTowers
//
//  Created by Ahmed Nezar on 03/12/2022.
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include "Defs.h"
#include "Castle.hpp"

class Battle;

class Enemy {
protected:
    int id;
    int distance;
    int damage = 5;
    int health;
    int priority = 3;
    REGION r;
public:
    Enemy();
    Enemy(int);
    void move();
    void fight();
    void kill(int);
    int getID();
    int getDistance();
    int getRegion();
    int getHealth();
    int getPriority();
    void setWinDamage();
};

#endif /* Enemy_hpp */
