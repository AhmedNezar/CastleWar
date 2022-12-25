#pragma once

#include "Defs.h"
#include "Queue.hpp"

class Castle
{
	double health;
	int N; // max number of elements tower can attack in time step
	double firePower;
    REGION region;
    bool killed;
//    Queue enemies;
	
public:
    Castle();
	Castle(REGION);
	//setter and getters..
	void setHealth(double h);
	double getHealth() const;
	void setNum(int);
	void setFirePower(int);
	int getMaxNum()const;
	int getFirePower()const;
    static Castle castles[NoOfRegions];
    void kill(int);
    void removeEnemy();
    Queue enemies;
    bool isKilled();
	//---------------------------------------------------------------------------------
	
	void damage(double);				//decrease castle health

	
	void setcastlesHealth(double h);
	void setcastlesNum(int n);
	void setcastleFirePower(int pow);
//	bool isDestroyed(int i);
	bool isLoose();
};


