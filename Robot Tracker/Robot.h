//Specification file for class.
#ifndef ROBOT_H
#define ROBOT_H
#include <iostream>

using namespace std;

//Robot class declaration.
class Robot{
    private:
        int xAxis = 0;
        int yAxis = 0;
        char lastCommand = 'a';
        int currentSpeed = 1;
        int distance = 0;
        string name = " ";
    public:
        Robot(string);
        void setName(string);
        int getDistance();
        string getName();
        void move(char);
};

#endif // ROBOT_H
