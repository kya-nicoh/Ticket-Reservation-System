#include<iostream>
#include<string>
using namespace std;

void welcome(void), menu(void), options(void), enter(void), reviewTheFile(void), removeFromFile(void), quit(void);
void choosing(int row, char column);
void addToFile(string name, string reservedSeat);

// try to put this inside a function
char upuan[6][6] = {{' ', 'A', 'B', 'C', 'D', 'E'},
                    {'1', 'O', 'O', 'O', 'O', 'O'},
                    {'2', 'O', 'O', 'O', 'O', 'O'},
                    {'3', 'O', 'O', 'O', 'O', 'O'},
                    {'4', 'O', 'O', 'O', 'O', 'O'},
                    {'5', 'O', 'O', 'O', 'O', 'O'}};

int main(){
    // intro
    welcome();

    // print menu
    do{
        options();
    }
    while(true);
    // choose between the following
        // reserve
            // reserve seat by individual or by group (multiple reservations)

            // search seat to reserve and how many (loop for how many you want)
            // check if it is avaiable if yes then continue if not then say

        // remove
        // view
        // quit
    
    // Do you want to view record and exit or continue reservation

    // delete reservation
    
    // view record and exit. (View record is txt file)
    
    return 0;
}

void welcome(void){
    char dash[] = "-------------------------------------------------\n";
    cout << "\n\n"<< dash << "          BARRIOS Reservation Services!\n" << dash;
}

void menu(void){

    char (*menuPointer)[6];
    menuPointer = upuan;

    cout << "\n\nBelow are the available seats for today: " << endl;

    for (int x = 0; x < 6; x++){
        cout << "\n                 ";
        for(int y = 0; y < 6; y++){
            cout << menuPointer[x][y] << " ";
        }
    }
    cout << "\n\n                           Legend: O = Available";
    cout << "\n                                   X = Taken";
}

void options(void){
    int option;
    cout << "\n1. Reserve a seat\n2. Delete a reservation\n3. Review the reservation\n4. Quit\n" << endl;
    
    cin >> option;

    if(option == 1) enter();
    else if(option == 2) removeFromFile();
    else if(option == 3) reviewTheFile();
    else if(option == 4) quit();
    else cout << "Please enter a valid value";
    option = 0;
}

void reviewTheFile(){

}

void enter(){
    menu();
    int r;
    char c;
        cout << "\n\nPlease search for a seat number\n Enter your desired row: ";
        cin >> r;
        cout << " Enter your desired column: ";
        cin >> c;

    cout << "\nYou entered seat: " << r << c;
    choosing(r,c);
}

void choosing(int row, char column){
    int newColumn;
    char toReserve;
    
    if(column == 'A' || column == 'a') newColumn = 1;
    else if(column == 'B' || column == 'b') newColumn = 2;
    if(column == 'C' || column == 'c') newColumn = 3;
    if(column == 'D' || column == 'd') newColumn = 4;
    if(column == 'E' || column == 'e') newColumn = 5;

    // dito i seset kung i rereserve ba or hindi

    string reservedSeat = to_string(row) + column;

    if(upuan[row][newColumn] == 'O'){
        cout << "\n This seat is available!\n Would you like to reserve it?\n";
        // enter y/n to continue then run addToFile
        cin >> toReserve;

        if(toReserve == 'y'){
            upuan[row][newColumn] = 'X';
            string name;
            cout << "Enter your name: ";
            cin >> name;
            addToFile(name, reservedSeat);
        }else enter();
        
    }
    else if (upuan[row][newColumn] == 'X'){
        cout << "\n I'm sorry but this seat is already taken.\n Would you like to reserve something else?";
        cin >> toReserve;
        if(toReserve == 'y'){
            cout << "Enter your name: ";
        }else options();
    }
}

void addToFile(string name, string reservedSeat){
    int question;
    cout << "\nYou opened add to file bitch\n";
    cout << name << reservedSeat;

    // add to txt file


    cout << "\n1. Reserve more\n2. Go back to options" << endl;
    cin >> question;
    question==1?enter():options();
}

void removeFromFile(){

}

void quit(void){
    exit(0);
}

/* PROBLEMS: 
    view files
    add to files
    remove files
    pointers
*/