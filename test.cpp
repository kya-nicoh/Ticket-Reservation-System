#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>
using namespace std;

void welcome(void), menu(void), options(void), search(void), removeFromFile(void), quit(void);
void reserve(int row, char column);
void addToFile(string name, string reservedSeat);
fstream file;

// try to put this inside a function
const char *upuan[6][6] = {{"   ", "A", "B", "C", "D", "E"},
                           {"1 |", "O", "O", "O", "O", "O"},
                           {"2 |", "O", "O", "O", "O", "O"},
                           {"3 |", "O", "O", "O", "O", "O"},
                           {"4 |", "O", "O", "O", "O", "O"},
                           {"5 |", "O", "O", "O", "O", "O"}};
// void seatMain(){
//     int r, c;

//     return upuan[r][c];
// }
int main(){
    do{
        options();
    }
    while(true);

    return 0;
}

void welcome(void){
    system("cls");
    char dash[] = "-------------------------------------------------\n";
    cout << "\n\n"<< dash << "          BARRIOS Reservation Services!\n" << dash;
}

void menu(void){
    cout << "\n\n| Below are the available seats for today: " << endl;
    for (int x = 0; x < 6; x++){
        cout << "\n                 ";
        for(int y = 0; y < 6; y++){
            cout << upuan[x][y] << " ";
        }
        if(x==0) continue;
        cout << "| " << x;
    }
    cout << "\n\n                           Legend: O = Available";
    cout << "\n                                   X = Taken";
}

void options(void){
    system("cls");
    welcome();
    int option;
    cout << "\n| 1. Search a seat\n| 2. Reserve a seat"
    <<      "\n| 3. Cancel the reservation\n| 4. Quit\n" << endl;
    
    cin >> option;

    if(option == 1) search();
    else if(option == 2) search();
    else if(option == 3) removeFromFile();
    else if(option == 4) quit();
    else cout << "Please enter a valid value";
    option = 0;
}

void search(){
    system("cls");
    menu();
    int r;
    char c;
        cout << "\n\n| Please search for a seat number\n Enter your desired row: ";
        cin >> r;
        cout << " Enter your desired column: ";
        cin >> c;

    cout << "\n| You entered seat: " << r << c;
    reserve(r,c);
}

void reserve(int row, char column){
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
 
    if(upuan[row][newColumn] == "O"){
        cout << "\n This seat is available!\n Would you like to reserve it? (y/n)\n";
        // enter y/n to continue then run addToFile
        cin >> toReserve;

        if(toReserve == 'y'){
            upuan[row][newColumn] = "X";
            string name;
            cout << " Enter your name: ";
            cin >> name;
            addToFile(name, reservedSeat);
        }else search();
    }
    else if (upuan[row][newColumn] == "X"){
        cout << "\n I'm sorry but this seat is already taken.\n Would you like to reserve somewhere else? (y/n)";
        cin >> toReserve;
        if(toReserve == 'y'){
            search();
        }else options();
    }
}

void addToFile(string name, string reservedSeat){
    system("cls");
    int question;
    // add to txt file
    file.open(name + "'s Reservation", ios::out | ios::app);
    file << "Customer Name: " << name << "\nSeat: "<< reservedSeat << endl;
    file.close();
    cout << "\n| 1. Reserve more\n| 2. Go back to options" << endl;
    cin >> question;
    question == 1 ? search() : options();
}

void removeFromFile(){
    system("cls");
    string name;
    cout << "| Please enter the name of the reservation holder" << endl;
    cin >> name;
    
    cout << "\n "<< name << "'s Reservation is: " << endl;
        file.open(name + "'s Reservation", ios::in);
        string laman;
        while(file.good()){
            getline(file, laman);
            cout << "  "<< laman << endl;
            
        }
        file.close();

    char toDelete;
    cout << "| Would you like to cancel your reservation? (y/n)" << endl;
    char cancel;
        cin >> cancel;
    cancel = toupper(cancel);
    if(cancel=='Y'){
        file.open(name + "'s Reservation", ios::out);
        file << " " << endl;
        file.close();

        cout << "....Processing\n...Processing Complete\nReservation has been deleted" << endl; 
    }
    char another;
    cout << "\n Main menu (y/n)" << endl;
    cin >> another;
    another == 'y' ? options() : removeFromFile();
}
void quit(void){
    system("cls");
    cout << "Thank you for using BARRIOS Reservation Services!\n\n" << endl;
    exit(0);
}
/* 
    PROBLEMS: 
    struct

    1.	Menu: 
    Search - seat if available to reserve, 
    Reserve - input your name and the selected seat number, Reserve seat individual and by group (enter names based on the number of seats).
    Cancel/Delete Reservation Record – remove the name and the seat should be available again.
    View Record - names, seat number
    Exit.
    2.	Input Data: Name and seat number
    3.	Calculated data change status if reserve or not
    4.	Calculated behavior is checking for continuous seats  e.g. 2 seats, 3 seats, 4 seats, etc.
    5.	Data for system should be saved on a flat file e.g. text file or txt files.
    6.	System can accept multiple reservation.
    7.	Design your own Menu.

*/