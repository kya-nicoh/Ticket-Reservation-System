#include<iostream>
using namespace std;

void welcome(void), menu(void), pick(void);

char seats[36] = {' ', '1', '2', '3', '4', '5',
                    'A', 'O', 'O', 'O', 'O', 'O',
                    'B', 'O', 'O', 'O', 'O', 'O',
                    'C', 'O', 'O', 'O', 'O', 'O',
                    'D', 'O', 'O', 'O', 'O', 'O',
                    'E', 'O', 'O', 'O', 'O', 'O'};

int main(){
    // intro
    welcome();

    // print menu
    
                       
    char *seatsPointer;
    seatsPointer = seats;


        cout << "\n                 ";
        for(int y = 0; y < 6; y++){
            cout << seats[y] << " ";
        }


    // search seat to reserve and how many (loop for how many you want)
    // check if it is avaiable if yes then continue if not then say
    int row, column;
        cout << "\n\nPlease search for a seat number\n Enter your desired row: ";
        cin >> row;
        cout << "Enter your desired column: ";
        cin >> column;

    cout << "You chose seat ";
        pick(row, column);

    // delete reservation

    // reserve seat by individual or by group

    // Do you want to view record and exit or continue reservation
    // view record and exit. (View record is txt file)

    return 0;
}

void welcome(void){
    char dash[] = "-------------------------------------------------\n";
    cout << dash << "          BARRIOS Reservation Services!\n" << dash;
}

void menu(void){
    
}

void pick(int row, int column){
    seats[row][column];
}

/* PROBLEMS: 
    char array
    pointers
*/