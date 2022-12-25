//
//  Enemy.cpp
//  CastleTowers
//
//  Created by Ahmed Nezar on 03/12/2022.
//

#include "Enemy.hpp"
using namespace std;

Enemy::Enemy() {}


Enemy::Enemy(int spawnRegion) {
    id = rand();
    distance = 0;
    damage = 2;
    health = 100;
    priority = 0;
    switch (spawnRegion) {
        case 0:
            r = A_REG;
            break;
        case 1:
            r = B_REG;
            break;
        case 2:
            r = C_REG;
            break;
        case 3:
            r = D_REG;
            break;
        default:
            r = A_REG;
    }
}

void Enemy::move() {
    distance++;
}

void Enemy::fight() {
    Castle::castles[r].damage(damage);
    cout << "Damage: " << r << " - Health: " << Castle::castles[r].getHealth() << endl;
}

void Enemy::kill(int d) {
    health -= d;
    if(health < 0) Castle::castles[r].removeEnemy();
    else cout << "Damage: " << id << " - Health: " << health << " - Priority: " << getPriority() << endl;
}

int Enemy::getID() {
    return id;
}

int Enemy::getDistance() {
    return distance;
}

int Enemy::getRegion() {
    return r;
}

int Enemy::getHealth() {
    return health;
}

int Enemy::getPriority() {
    return priority;
}

void Enemy::setWinDamage() {
    damage = 1;
}
