//
//  Balloon.cpp
//  CastleTowers
//
//  Created by Ahmed Nezar on 24/12/2022.
//

#include "Balloon.hpp"

Balloon::Balloon() {}

Balloon::Balloon(int spawnRegion) {
    id = rand();
    distance = 0;
    damage = 20;
    health = 200;
    priority = 1;
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
