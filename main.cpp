#include<iostream>
#include<string.h>
using namespace std;

void welcome(void), menu(void), enter(void), choosing(void);

int main(){
    // intro
    welcome();

    // print menu
    menu();

    // search seat to reserve and how many (loop for how many you want)
    // check if it is avaiable if yes then continue if not then say
    
    enter();
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
    char menu[6][6] = {{' ', '1', '2', '3', '4', '5'},
                       {'A', 'O', 'O', 'O', 'O', 'O'},
                       {'B', 'O', 'O', 'O', 'O', 'O'},
                       {'C', 'O', 'O', 'O', 'O', 'O'},
                       {'D', 'O', 'O', 'O', 'O', 'O'},
                       {'E', 'O', 'O', 'O', 'O', 'O'}};

    char *menuPointer;
    // menuPointer = menu;

    cout << "\nBelow are the available seats for today: " << endl;

    for (int x = 0; x < 6; x++){
        cout << "\n                 ";
        for(int y = 0; y < 6; y++){
            cout << menu[x][y] << " ";
        }
    }
}

void enter(){
    int r, c;
        cout << "\n\nPlease search for a seat number\n Enter your desired row: ";
        cin >> r;
        cout << " Enter your desired column: ";
        cin >> c;
    cout << "You entered " << menu[r][c];
}

void choosing(){
    // dito i seset kung i rereserve ba or hindi
}



/* PROBLEMS: 
    char array
    pointers
*/