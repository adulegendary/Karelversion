#include <iostream>
#include <string>
using namespace std;
int const ROW = 6;
int const COLUMN = 8;
int row = 0;
int column = 0;
int direction = 0;
string command;
string direct = "";


void TurnLeft() {
    direction = direction + 1;     //0east  1north  2west 3south
    if (direction == 4) {
        direction = 0;
    }
    if (direction == 0) {
        direct = "east";
    }
    else if (direction == 1) {
        direct = "north";
    }
    else if (direction == 2) {
        direct = "west";
    }
    else if (direction == 3) {
        direct = "south";
    }
    cout << "Karel is at location (" << row << column << ")facing " << direct << ".";
}
void move() {

    if (direction == 0) {
        column = column + 1;// 1112 13 14 15-> 16 17 18
        cout << "Karel is at location (" << row << column << ")facing east." << endl;
    }
    else if (direction == 1) {    //21 22 23 24 25   26 27 28
        row = row - 1;
        cout << "Karel is at location (" << row << column << ")facing north." << endl;
    }
    else if (direction == 2) {
        column = column - 1;
        cout << "Karel is at location (" << row << column << ")facing west." << endl;
    }
    else if (direction == 3) {
        row = row + 1;
        cout << "Karel is at location (" << row << column << ")facing south." << endl;
    }

    if (!(row >= 0 && row < ROW)) {
        cout << "Karel tried to move to location(" << row << column << ")Karel has crashed!" << endl;
        exit(0);

    }
    if (!(column >= 0 && column < COLUMN)) {
        cout << "Karel tried to move to location(" << row << column << ")Karel has crashed!" << endl;
        exit(0);
    }
}

int main() {

    while (true) {
        cout << "Please enter a command: \n ";
        cin >> command;

        while (command != "move" && command != "turnLeft" && command != "quit") {
            cout << "Invalid command! \n";
            cout << "Please enter a command: \n";
            cin >> command;
        }
        if (command == "move") {
            move();
        }
        else if (command == "turnLeft") {
            TurnLeft();

        }
        else {
            if (direction == 0) {
                direct = "east";
            }
            else if (direction == 1) {
                direct = "north";
            }
            else if (direction == 2) {
                direct = "west";
            }
            else if (direction == 3) {
                direct = "south";
            }
            cout << "Karel finished at location (" << row << column << ")facing" << direct << ". Thank you for not crashing Karel!" << endl;
            return 0;
        }
    }
    return 0;
}



//the karel version 0.1