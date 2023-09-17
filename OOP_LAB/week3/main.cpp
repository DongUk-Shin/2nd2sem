#include "tower.h"
#include "pgm.h"

int main() {
	Tower myTower;
	Tower seoulTower(100);

	cout << "Height: " << myTower.getHeight() << "m" << endl; 
	cout << "Height: " << seoulTower.getHeight() << "m" << endl;
	return 0;
}