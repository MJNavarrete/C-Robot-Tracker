#include <iostream>
#include <ctype.h>

using namespace std;

//Robot struct.
struct Robot{
    int xAxis = 0;
    int yAxis = 0;
    char lastCommand = 'a';
    int currentSpeed = 1;
    int distance = 0;
    string name = " ";
};

//Prototype functions.
void move(Robot*, int);
void menu(Robot**, char&, int);
int findRobot(Robot*, string, int);
void sortDistance(Robot**, int);
Robot** makeBotList(int);

int main()
{
    char menuChoice = 'a';
    int numOfRobots = 0;

    //Enter the number of robots you want to track.
    cout << "How many robots do you want to track?" << endl;
    cin >> numOfRobots;
    //Creation of the array of robot pointers.
    Robot **robotList = makeBotList(numOfRobots);

    //Enter the names of the robots that you want to track.
    cout << "Please enter the names of the " << numOfRobots << " robots." << endl;
    for(int i = 0; i < numOfRobots; i++){
        cin >> robotList[i]->name;
    }

    //Infinite menu for choosing options. Only quits when user decides to.
    cout << "Welcome to MultiRobot Guider." << endl;
    do{
        cout << "Please select:" << endl;
        cout << "  M- move one robot" << endl;
        cout << "  D- print the distance each robot has moved" << endl;
        cout << "  Q- quit the program" << endl;
        cin >> menuChoice;
        menu(robotList, menuChoice, numOfRobots);
    }while(menuChoice != 'q' && menuChoice != 'Q');

    delete [] robotList;

    return 0;
}

void move(Robot *robotList[], int index){
    char moveChoice = 'a';

    cout << "Please select: " << endl;
    cout << "   U- up" << endl;
    cout << "   D- down" << endl;
    cout << "   R- right" << endl;
    cout << "   L- left" << endl;
    cin >> moveChoice;

    //Controls speedup of the robot. If last command is equal to current command,
    //increase speedup or do nothing.
    if(toupper(robotList[index]->lastCommand) == toupper(moveChoice)){
        //If the current speed is less than 4, keep increasing the speed.
        if(robotList[index]->currentSpeed < 4){
            robotList[index]->currentSpeed++;
        }
    }
    else{
        //If last command is not the same as current command, reset speed to 1.
        robotList[index]->currentSpeed = 1;
    }

    robotList[index]->lastCommand = moveChoice;

    //Switch statement updating movement and tracking total distance.
    switch (moveChoice){
        case 'u':
        case 'U': robotList[index]->yAxis += robotList[index]->currentSpeed;
                  robotList[index]->distance += robotList[index]->currentSpeed;
        break;
        case 'd':
        case 'D': robotList[index]->yAxis -= robotList[index]->currentSpeed;
                  robotList[index]->distance += robotList[index]->currentSpeed;
        break;
        case 'r':
        case 'R': robotList[index]->xAxis += robotList[index]->currentSpeed;
                  robotList[index]->distance += robotList[index]->currentSpeed;
        break;
        case 'l':
        case 'L': robotList[index]->xAxis -= robotList[index]->currentSpeed;
                  robotList[index]->distance += robotList[index]->currentSpeed;
        break;
        default: cout << "Invalid direction" << endl;
        break;
    }
}

//Function to find robots by name.
int findRobot(Robot *robotList[], string robotName, int numOfRobots){
    for(int i = 0; i < numOfRobots; i++){
        if(robotList[i]->name == robotName){
            return i;
        }
    }
    return -1;

}

//Main menu handling function. Switch statement used to handle user input.
void menu(Robot *robotList[], char &menuChoice, int numOfRobots){
    string robotName = " ";
    int index = 0;

    switch (menuChoice){
        case 'm':
        case 'M': cin >> robotName;
                  index = findRobot(robotList, robotName, numOfRobots);
                  if(index == -1){
                    cout << "Robot not in list." << endl;
                  }
                  else{
                    move(robotList, index);
                    cout << robotList[index]->name << "'s position is ";
                    cout << robotList[index]->xAxis << ", " << robotList[index]->yAxis << endl;
                  }
        break;
        case 'd':
        case 'D': sortDistance(robotList, numOfRobots);
                  for(int k = 0; k < numOfRobots; k++){
                      cout << robotList[k]->name << " " << robotList[k]->distance << endl;
                  }
        break;
        case 'q':
        case 'Q': cout << "Goodbye" << endl;
        break;
        default: cout << "Invalid command" << endl;
        break;
    }
}

void sortDistance(Robot *robotList[], int numOfRobots){
    bool swap;
    Robot temp;
    do{
        swap = false;
        for(int j = 0; j < (numOfRobots - 1); j++){
            if(robotList[j]->distance < robotList[j + 1]->distance){
                temp = *robotList[j];
                *robotList[j] = *robotList[j + 1];
                *robotList[j + 1] = temp;
                swap = true;
            }
        }
    }while(swap);
}

//Creates the dynamically allocated array of robot pointers
Robot** makeBotList(int SIZE){
    Robot** botList = new Robot*[SIZE];
    for(int i = 0; i < SIZE; i++){
        botList[i] = new Robot;
    }
    return botList;
}
