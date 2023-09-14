#include <iostream>
using namespace std;

class Car {

private:
    int speed; 
    int gear;
    string color;

public:
    Car(int s, int g, string c) {
        speed = s;
        gear = g;
        color = c;
    }

    void speedUp() { 
        speed += 10;
    }
    void speedDown() { 
        speed -= 10;
    }
    void setColor(string c) {
        color = c;
    }
    void setSpeed(int s) {
        speed = s;
    }
    int getSpeed() {
        return speed;
    }
    void setGear(int g) {
        gear = g;
    }
    int getGear() {
        return gear;
    }
};

int main() {
    Car car(50, 3, "Black");
    car.speedUp();
    int s = car.getSpeed();
    cout << "speed: " << s << endl;
}
