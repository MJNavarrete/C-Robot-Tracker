#ifndef ROBOLIST_H
#define ROBOLIST_H

#include "Robot.h"

using namespace std;

class RoboList
{
    private:
        class Node{
            public:
                Robot* val;
                Node* next;
        };
        Node* head = NULL;
        int SIZE = 0;

    public:
        Robot* findRobot(string target);
        void printDistances();
        void printList();
        void ins(string);
        void del(string);
        ~RoboList();
};

#endif // ROBOTLIST_H
