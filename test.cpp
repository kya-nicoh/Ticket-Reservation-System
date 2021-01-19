#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
using namespace std;

void welcome(void), menu(void), options(void), enter(void), removeFromFile(void), reviewTheFile(void), quit(void);
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
    system("cls");
    char dash[] = "-------------------------------------------------\n";
    cout << "\n\n"<< dash << "          BARRIOS Reservation Services!\n" << dash;
}

void menu(void){

    char (*menuPointer)[6];
    menuPointer = upuan;

    cout << "\n\n| Below are the available seats for today: " << endl;

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
    system("cls");
    welcome();
    int option;
    cout << "\n| 1. Reserve a seat\n| 2. Delete a reservation"
    <<      "\n| 3. Review the reservation\n| 4. Quit\n" << endl;
    
    cin >> option;

    if(option == 1) enter();
    else if(option == 2) removeFromFile();
    else if(option == 3) reviewTheFile();
    else if(option == 4) quit();
    else cout << "Please enter a valid value";
    option = 0;
}

void enter(){
    system("cls");
    menu();
    int r;
    char c;
        cout << "\n\n| Please search for a seat number\n Enter your desired row: ";
        cin >> r;
        cout << " Enter your desired column: ";
        cin >> c;

    cout << "\n| You entered seat: " << r << c;
    choosing(r,c);
}

void choosing(int row, char column){
    int newColumn;
    char toReserve;
    
    column = toupper(column);

    if(column == 'A') newColumn = 1;
    if(column == 'B') newColumn = 2;
    if(column == 'C') newColumn = 3;
    if(column == 'D') newColumn = 4;
    if(column == 'E') newColumn = 5;

    // dito i seset kung i rereserve ba or hindi
    string reservedSeat = to_string(row) + column;

    if(upuan[row][newColumn] == 'O'){
        cout << "\n This seat is available!\n Would you like to reserve it? (y/n)\n";
        // enter y/n to continue then run addToFile
        cin >> toReserve;

        if(toReserve == 'y'){
            upuan[row][newColumn] = 'X';
            string name;
            cout << " Enter your name: ";
            cin >> name;
            addToFile(name, reservedSeat);
        }else enter();
    }
    else if (upuan[row][newColumn] == 'X'){
        cout << "\n I'm sorry but this seat is already taken.\n Would you like to reserve somewhere else? (y/n)";
        cin >> toReserve;
        if(toReserve == 'y'){
            enter();
        }else options();
    }
}

void addToFile(string name, string reservedSeat){
    system("cls");
    int question;
    // add to txt file
    fstream file;

    file.open(name + "'s Reservation", ios::out | ios::app);
    file << reservedSeat << endl;
    file.close();
    cout << "\n| 1. Reserve more\n| 2. Go back to options" << endl;
    cin >> question;
    question == 1 ? enter() : options();
}

void removeFromFile(){
    system("cls");
    string name;
    cout << "| Please enter the name of the reservation holder" << endl;
    cin >> name;

    fstream file;
    file.open(name + "'s Reservation", ios::out);
    // this deletes everything
    file << " " << endl;
    file.close();

    cout << "....Processing\n...Processing Complete\nReservation has been deleted" << endl; 

    char another;
    cout << "\n Would you like to delete another reservation? (y/n)" << endl;
    cin >> another;
    another == 'y' ? removeFromFile() : options();
}

void reviewTheFile(){
    system("cls");
    string name;
    cout << "| Please enter the name of the reservation holder" << endl;
    cin >> name;
    cout << "Seats reserved under the name: " << name << endl;

    fstream file;
    file.open(name + "'s Reservation", ios::in);
    while(!file.eof()){
        string readText;

        file >> readText;
        cout << readText << endl;
    }
    file.close();
    char another;
    cout << "\n Would you like to view another reservation? (y/n)" << endl;
    cin >> another;
    another == 'y' ? reviewTheFile() : options();
}

void quit(void){
    system("cls");
    cout << "Thank you for using BARRIOS Reservation Services!\n\n" << endl;
    exit(0);
}

/* 
    PROBLEMS: 
    deleting by name deletes everything inside
        possible solution dito is ipapasearch ung user ng seat na gusto tanggalin tas if same dun sa naka write then delete un

    when deleting the x na nasa array ay dapat maging dot din
    revamp the delete function to enter which seat you want to delete
    pointers

    1.	Menu: Name with seat number, Search seat if available to reserve, Delete Reservation Record, Reserve seat individual and by group, View Record, Exit.
    2.	Input Data: Name and seat number
    3.	Calculated data change status if reserve or not
    4.	Calculated behavior is checking for continuous seats  e.g. 2 seats, 3 seats, 4 seats, etc.
    5.	Data for system should be saved on a flat file e.g. text file or txt files.
    6.	System can accept multiple reservation.
    7.	Design your own Menu.

*/