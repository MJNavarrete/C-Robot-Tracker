#include <iostream>

using namespace std;

struct Robot{
    int xAxis = 0;
    int yAxis = 0;
    char lastCommand = 'a';
    int currentSpeed = 0;
    int distance = 0;
    string name = " ";
};
void move(Robot&, char&);
void menu(char);

int main()
{
    Robot r;
    char menuChoice = 'A';
    char moveChoice = 'a';
    int numOfRobots = 0;

    cout << "How many robots do you want to track?" << endl;
    cin >> numOfRobots;
    Robot roboList[numOfRobots];

    //
    cout << "Please enter the names of the " << numOfRobots << "robots." << endl;
    for(int i = 0; x < numOfRobots; x++){
        cin >> roboList[i].name;
    }

    do{
        cout << "Robot's Position is " << r.xAxis << ", " << r.yAxis << endl;
        cout << "Please select: " << endl;
        cout << "   U- up" << endl;
        cout << "   D- down" << endl;
        cout << "   R- right" << endl;
        cout << "   L- left" << endl;
        cout << "   Q- quit" << endl;
        cin >> moveChoice;
        move(r, moveChoice);
    }while(moveChoice != 'q' && moveChoice != 'Q');

    return 0;
}

void move(Robot &r, char &moveChoice){
          switch (moveChoice){
            case 'u':
            case 'U': r.yAxis++;
            break;
            case 'd':
            case 'D': r.yAxis--;
            break;
            case 'r':
            case 'R': r.xAxis++;
            break;
            case 'l':
            case 'L': r.xAxis--;
            break;
            case 'q':
            case 'Q': cout << "Goodbye";
            break;
            default: cout << "Invalid command" << endl;
            break;
          }
}

void menu(char menuChoice){
    switch (menuChoice){
        case 'm':
        case 'M':
        break;
        case 'd':
        case 'D':
        break;
        case 'q':
        case 'Q':
        break;
}
