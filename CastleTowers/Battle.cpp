//
//  Battle.cpp
//  CastleTowers
//
//  Created by Ahmed Nezar on 03/12/2022.
//

#include "Battle.hpp"
//#include "Balloon.hpp"
//#include "Fighter.hpp"

using namespace std;

Battle::Battle() {
}

void Battle::update() {
    allEnemies.traverse(&Enemy::move);
    castleKill();
    time++;
}

//Enemy * Battle::spawn() {
//    if(checkSpawn()) {
//        spawnRegion = (spawnRegion == 4) ? 0 : spawnRegion;
//        Enemy * e;
//        int enemytype = rand() % 3 ;
//        switch (enemytype) {
//            case 0:
//                e = new Enemy(spawnRegion);
//                break;
//            case 1:
//                e = new Balloon(spawnRegion);
//                break;
//            case 2:
//                e = new Fighter(spawnRegion);
//                break;
//            default:
//                e = new Enemy(spawnRegion);
//                break;
//        }
//        totalEnemies++;
//        allEnemies.insertLast(e);
//        Castle::castles[spawnRegion].enemies.enqueue(e, e->getPriority());
//        spawnRegion++;
//        return e;
//    }
//    else return 0;
//}

bool Battle::checkSpawn() { //xxxxxxx
    return (time % 4 == 0 && allEnemies.nodeCount() < 8);
}

List * Battle::getAllEnemies() {
    return &allEnemies;
}

int Battle::getSpawnRegion() {
    return spawnRegion;
}

void Battle::castleKill() {
    for(int i = 0; i < 4; i++) {
        if(!Castle::castles[i].isKilled()) Castle::castles[i].kill(Castle::castles[i].getFirePower());
    }
    allEnemies.eraseEnemy();
}
