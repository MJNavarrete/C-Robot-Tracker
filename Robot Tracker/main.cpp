#include "Robot.h"
#include "RoboList.h"
#include <iostream>

using namespace std;

//Prototype functions.
//void menu(Robot**, char&, int);
//int findRobot(Robot*, string, int);
//void sortDistance(Robot**, int);
//Robot** makeBotList(int);

int main()
{
    cout << "Welcome to MultiRobo Guider!" << endl;
    cout << "How many robots are you tracking: ";
    int numBots;
    cin >> numBots;
    //Robot** botList = makeBotList(numBots);
    RoboList botList;

    cout << "Please enter names for the " << numBots << " robots." << endl;
    for(int i = 0; i < numBots; i++){
        string name;
        cin >> name;
        //botList[i]->setName(name);
        botList.ins(name);
    }

    bool programRunning = true;

    while(programRunning){
        char menuChoice, directionChoice;
        string roboName, newName;
        //int roboIndex;
        Robot* roboPtr;

        cout << "Please select: " << endl;
        cout << "  M- move" << endl;
        cout << "  D- distance" << endl;
        cout << "  U- update list" << endl;
        cout << "  R- rename" << endl;
        cout << "  Q- quit" << endl;
        cin >> menuChoice;

        switch(menuChoice){
            case 'm':
            case 'M':
                cin >> roboName;
                //roboIndex = findRobot(botList, numBots, roboName);
                roboPtr = botList.findRobot(roboName);
                //if(roboIndex == -1)
                if(roboPtr == NULL)
                    cout << "That robot does not exist." << endl;
                else{
                    cin >> directionChoice;
                    //botList[roboIndex]->moveRobot(directionChoice);
                    roboPtr->move(directionChoice);
                }
                break;
            case 'd':
            case 'D':
                // for (int i = 0; i < numBots; i++){
                //     cout << botList[i].name << '\t' << botList[i].distance
                //         << endl;
                // }
                //printDistances(botList, numBots);
                botList.printDistances();
                break;
            case 'r':
            case 'R':
                cin >> roboName >> newName;
                //roboIndex = findRobot(botList, numBots, roboName);
                roboPtr = botList.findRobot(roboName);
                //botList[roboIndex]->setName(newName);
                roboPtr->setName(newName);
                break;
            case 'u':
            case 'U':
                cin >> directionChoice;
                switch(directionChoice){
                    case 'a':
                    case 'A':
                        cin >> roboName;
                        botList.ins(roboName);
                        break;
                    case 'd':
                    case 'D':
                        cin >> roboName;
                        botList.del(roboName);
                        break;
                    default:
                        cout << "Invalid choice to update." << endl;
                }
                break;
            case 'q':
            case 'Q':
                cout << "Goodbye." << endl;
                programRunning = false;
                break;
            default:
                cout << "Command not recognized." << endl;
        }
    }
    return 0;
}

//Function to find robots by name.
//int findRobot(Robot *robotList[], string robotName, int numOfRobots){
//for(int i = 0; i < numOfRobots; i++){
//       if(robotList[i]->getName() == robotName){
//            return i;
//        }
//    }
//    return -1;
//
//}

//Main menu handling function. Switch statement used to handle user input.
//void menu(Robot *robotList[], char &menuChoice, int numOfRobots){
//    string robotName = " ";
//    int index = 0;
//
//    switch (menuChoice){
//        case 'm':
//        case 'M': cin >> robotName;
//                 index = findRobot(robotList, robotName, numOfRobots);
//                  if(index == -1){
//                    cout << "Robot not in list." << endl;
//                  }
//                  else{
//                    char moveChoice = 'a';
//
//                    cout << "Please select: " << endl;
//                    cout << "   U- up" << endl;
//                    cout << "   D- down" << endl;
//                    cout << "   R- right" << endl;
//                    cout << "   L- left" << endl;
//                   cout << "   S- stop or start moving" << endl;
//                    cin >> moveChoice;
//
//                    robotList[index]->move(moveChoice);
//                   cout << robotList[index]->getName() << "'s position is ";
//                    cout << robotList[index]->getxAxis() << ", " << robotList[index]->getyAxis() << endl;
//                  }
//       break;
//        case 'd':
//        case 'D': sortDistance(robotList, numOfRobots);
//                  for(int k = 0; k < numOfRobots; k++){
//                     cout << robotList[k]->getName() << " " << robotList[k]->getDistance() << endl;
//                 }
//        break;
//        case 'r':
//        case 'R': cout << "Enter the name of the robot you want to rename:" << endl;
//                  cin >> robotName;
//                 index = findRobot(robotList, robotName, numOfRobots);
//                  if(index == -1){
//                    cout << "Robot not in list." << endl;
//                  }
//                 else{
//                    string newName;
//                    cout << "Enter new name: ";
//                    cin >> newName;
//                    robotList[index]->setName(newName);
//                 }
//        break;
//        case 'q':
//        case 'Q': cout << "Goodbye" << endl;
//        break;
//        default: cout << "Invalid command" << endl;
//        break;
//    }
//}

//void sortDistance(Robot *robotList[], int numOfRobots){
//bool swap;
//    Robot temp;
//    do{
//        swap = false;
//        for(int j = 0; j < (numOfRobots - 1); j++){
//            if(robotList[j]->getDistance() < robotList[j + 1]->getDistance()){
//                temp = *robotList[j];
//                *robotList[j] = *robotList[j + 1];
//                *robotList[j + 1] = temp;
//                swap = true;
//            }
//        }
//    }while(swap);
//}

//Creates the dynamically allocated array of robot pointers
//Robot** makeBotList(int SIZE){
//    Robot** botList = new Robot*[SIZE];
//    for(int i = 0; i < SIZE; i++){
//        botList[i] = new Robot;
//    }
//   return botList;
//}
