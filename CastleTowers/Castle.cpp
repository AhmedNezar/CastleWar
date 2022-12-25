#include "Castle.hpp"
#include "Enemy.hpp"
#include "Balloon.hpp"
#include "Fighter.hpp"

Castle::Castle() {};

Castle::Castle(REGION r)
{
    health = 100;
    region = r;
    firePower = 5;
    killed = false;
}

double Castle::getHealth()const
{
	return health;
}
int Castle::getMaxNum()const
{
	return N;
}

int Castle::getFirePower()const
{
	return firePower;
}

void Castle::setHealth(double h)
{
	 health = h ;
}


void Castle::setNum(int rn)
{
	N = (rn > 0) ? rn : 5;//assuming default number is 5
}


void Castle::setFirePower(int fp)
{
	firePower = (fp > 0) ? fp : 10;//assuming the default fire power is 10
}

void Castle::damage(double x)
{
	health = health - x;

	if (health <= 0)
	{
        if(!killed) killed = true;
		health = 0;
	}
}


void Castle::kill(int d) {
    if(enemies.empty()) return;
    enemies.front()->kill(d);
}

void Castle::removeEnemy() {
    cout << "Enemy: " << enemies.front()->getID() << " Removed" << endl;
    enemies.dequeue();
}

bool Castle::isKilled() {
    return killed;
}


//bool Castle::isLoose() {
//	bool flag;
//	for (int i = 0; i <= NoOfRegions; i++) {
//		if (isDestroyed(i))
//			flag = true;
//		else flag = false;
//	}
//	return flag;
//}
