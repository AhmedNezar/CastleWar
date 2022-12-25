//
//  Battle.hpp
//  CastleTowers
//
//  Created by Ahmed Nezar on 03/12/2022.
//

#ifndef Battle_hpp
#define Battle_hpp

#include <stdio.h>
#include <iostream>
#include "List.hpp"
#include "Castle.hpp"

class Battle {
    
public:
    Battle();
    void update();
    Enemy * spawn();
    bool checkSpawn();
    List * getAllEnemies();
    void move(Enemy *);
    int getSpawnRegion();
    void castleKill();
    void test();
private:
    int time = 0;
    int totalEnemies = 0;
    int spawnRegion = 0;
    List allEnemies;
};

#endif /* Battle_hpp */
