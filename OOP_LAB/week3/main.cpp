
#include "tower.h"
#include "pgm.h"

int main() {
	Tower myTower;
	Tower seoulTower(100);

	cout << "���̴� " << myTower.getHeight() << "����" << endl; 
	cout << "���̴� " << seoulTower.getHeight() << "����" << endl;
	return 0;
}