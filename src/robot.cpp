#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Robot {
protected:
    string name;
    float power;
public:
    Robot() : name(""), power(0) {}
    Robot(string name, float power) : name(name), power(power) {}
    Robot(float power) : power(power), name("") {}
    Robot(string name) : name(name), power(0) {}
    float getPower() {return power;}
    string getName() {return name;}
    void setPower(float power) {this -> power = power;}
    void setName(string name) {this -> name = name;}
    virtual void print() {
        cout << "Robot " << name << " with power " << power << '\n';
    }
};

class SimpleRobot : public Robot {
public:
    SimpleRobot() : Robot() {}
    SimpleRobot(string name, float power) : Robot(name, power) {}
};

class CombiRobot : public Robot {
public:
    CombiRobot(Robot* r1, Robot* r2) : Robot(2 * max(r1 -> getPower(), r2 -> getPower()) + min(r1 -> getPower(), r2 -> getPower())) {
        if (r1 -> getPower() < r2 -> getPower()) swap(r1, r2);
        Robot::name = r1 -> getName() + "_" + r2 -> getName();
    }
    CombiRobot() : Robot() {}
};

int inputWhichType() {
    cout << "\nInput robot type: ";
    int type;
    cin >> type;
    return type;
}

Robot* input1SimpleRobot() {
    string name; int power;
    cout << "\nInput name: ";
    cin >> name; 
    cout << "\nInput power: ";
    cin >> power;
    Robot* temp = new SimpleRobot(name, power);
    return temp;
}

Robot* input1CombiRobot() {
    cout << "\nInput the first robot: ";
    Robot* r1 = input1SimpleRobot();
    cout << "\nInput the second robot: ";
    Robot* r2 = input1SimpleRobot();
    Robot* temp = new CombiRobot(r1, r2);
    return temp;
}

void inputNRobots(int n, Robot* r[]) {
    int type;
    for (int i = 0; i < n; i++) {
        type = inputWhichType();
        if (type) r[i] = input1CombiRobot();
        else r[i] = input1SimpleRobot();
    }
}

int main() {
    int N;
    cout << "\nInput N: ";
    cin >> N;
    Robot* r[N];
    inputNRobots(N, r);
    for (int i = 0; i < N; i++) r[i] -> print();
    return 0;
}
