#include <iostream>
#include <ctype.h>

using namespace std;

//Robot struct.
class Robot{
    private:
        int xAxis = 0;
        int yAxis = 0;
        char lastCommand = 'a';
        int currentSpeed = 1;
        int distance = 0;
        string name = " ";
    public:
        void setName(string input){
            name = input;
        };
        int getDistance(){
            return distance;
        };
        string getName(){
            return name;
        };
        int getxAxis(){
            return xAxis;
        };
        int getyAxis(){
            return yAxis;
        };
        void move(char lastCommand);

};

//Prototype functions.
void menu(Robot**, char&, int);
int findRobot(Robot*, string, int);
void sortDistance(Robot**, int);
Robot** makeBotList(int);

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

    //make lastCommand equal to last user input
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
}

int main()
{
    char menuChoice = 'a';
    int numOfRobots = 0;
    string name;

    //Enter the number of robots you want to track.
    cout << "How many robots do you want to track?" << endl;
    cin >> numOfRobots;
    //Creation of the array of robot pointers.
    Robot **robotList = makeBotList(numOfRobots);

    //Enter the names of the robots that you want to track.
    cout << "Please enter the names of the " << numOfRobots << " robots." << endl;
    for(int i = 0; i < numOfRobots; i++){
        cin >> name;
        robotList[i]->setName(name);
    }

    //Infinite menu for choosing options. Only quits when user decides to.
    cout << "Welcome to MultiRobot Guider." << endl;
    do{
        cout << "Please select:" << endl;
        cout << "  M- move one robot" << endl;
        cout << "  D- print the distance each robot has moved" << endl;
        cout << "  R- rename one robot" << endl;
        cout << "  Q- quit the program" << endl;
        cin >> menuChoice;
        menu(robotList, menuChoice, numOfRobots);
    }while(menuChoice != 'q' && menuChoice != 'Q');

    delete [] robotList;

    return 0;
}

//Function to find robots by name.
int findRobot(Robot *robotList[], string robotName, int numOfRobots){
    for(int i = 0; i < numOfRobots; i++){
        if(robotList[i]->getName() == robotName){
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
                    char moveChoice = 'a';

                    cout << "Please select: " << endl;
                    cout << "   U- up" << endl;
                    cout << "   D- down" << endl;
                    cout << "   R- right" << endl;
                    cout << "   L- left" << endl;
                    cout << "   S- stop or start moving" << endl;
                    cin >> moveChoice;

                    robotList[index]->move(moveChoice);
                    cout << robotList[index]->getName() << "'s position is ";
                    cout << robotList[index]->getxAxis() << ", " << robotList[index]->getyAxis() << endl;
                  }
        break;
        case 'd':
        case 'D': sortDistance(robotList, numOfRobots);
                  for(int k = 0; k < numOfRobots; k++){
                      cout << robotList[k]->getName() << " " << robotList[k]->getDistance() << endl;
                  }
        break;
        case 'r':
        case 'R': cout << "Enter the name of the robot you want to rename:" << endl;
                  cin >> robotName;
                  index = findRobot(robotList, robotName, numOfRobots);
                  if(index == -1){
                    cout << "Robot not in list." << endl;
                  }
                  else{
                    string newName;
                    cout << "Enter new name: ";
                    cin >> newName;
                    robotList[index]->setName(newName);
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
            if(robotList[j]->getDistance() < robotList[j + 1]->getDistance()){
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
