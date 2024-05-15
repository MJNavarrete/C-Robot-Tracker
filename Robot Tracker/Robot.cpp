//Implementaton file for the Robot class.
#include "Robot.h"
#include <ctype.h>

using namespace std;

Robot::Robot(string name){
   this->name = name;
}

void Robot::setName(string input){
    this->name = name;
}

int Robot::getDistance(){
    return distance;
}

string Robot::getName(){
    return name;
}

//Controls the movement of the robot with main menu for movement using a public
//member function of the class.
void Robot::move(char moveChoice){
    //logic control behind stop and start options.
     if(moveChoice == 's' || moveChoice == 'S'){
        if(currentSpeed != 0){
            currentSpeed = 0;
            cout << name << " is now stopped" << endl;
            return;
        }
        else{
            currentSpeed = 1;
            lastCommand = 'a';
            cout << name << " is now moving" << endl;
            return;
        }
    }

    //Prints message if user tries to move a stopped robot.
     if (currentSpeed == 0){
        cout << "A robot cannot move while stopped!" << endl;
        return;
    }

    //Controls speedup of the robot. If last command is equal to current command,
    //increase speedup or do nothing.
    if(toupper(lastCommand) == toupper(moveChoice)){
        //If the current speed is less than 4, keep increasing the speed.
        if(currentSpeed < 4){
            currentSpeed++;
        }
    }
    else{
        //If last command is not the same as current command, reset speed to 1.
        currentSpeed = 1;
    }

    //make lastCommand equal to last user input.
    lastCommand = moveChoice;

    //Switch statement updating movement and tracking total distance.
    switch (moveChoice){
        case 'u':
        case 'U': yAxis += currentSpeed;
                  distance += currentSpeed;
        break;
        case 'd':
        case 'D': yAxis -= currentSpeed;
                  distance += currentSpeed;
        break;
        case 'r':
        case 'R': xAxis += currentSpeed;
                  distance += currentSpeed;
        break;
        case 'l':
        case 'L': xAxis -= currentSpeed;
                 distance += currentSpeed;
        break;
        default: cout << "Invalid direction" << endl;
        break;
    }
    cout << name << "'s position is now " << xAxis << ", " << yAxis << endl;
    return;
}
