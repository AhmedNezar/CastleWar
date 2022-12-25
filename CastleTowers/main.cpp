//
//  main.cpp
//  CastleTowers
//
//  Created by Ahmed Nezar on 03/12/2022.
//

#include <iostream>
//#include <unistd.h>
#include <thread>
#include <chrono>
#include "Battle.hpp"
#include "GUI.hpp"

using namespace std;

Castle Castle::castles[4] = {Castle(A_REG), Castle(B_REG), Castle(C_REG), Castle(D_REG)};

int main(int argc, const char * argv[]) {
    GUI gui;
    while(gui.isRunning()) {
        
        gui.update();
        
        gui.render();
        
        
    }
    
    return 0;
}
