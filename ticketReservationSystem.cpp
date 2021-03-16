#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<fstream>
#include<ctime>
#include<stdlib.h>
using namespace std;

void welcome(void), menu(void), options(void), reserveActual(void), removeFromFile(void), quit(void);
void reserve(int type, int seatAmount);
void search(int seatAmount), view(int version);
fstream file;

struct mainSeat{
    const char *upuan[6][6] = {{"   ", "A", "B", "C", "D", "E"},
                               {"1 |", "O", "O", "O", "O", "O"},
                               {"2 |", "O", "O", "O", "O", "O"},
                               {"3 |", "O", "O", "O", "O", "O"},
                               {"4 |", "O", "O", "O", "O", "O"},
                               {"5 |", "O", "O", "O", "O", "O"}};

    string names[6][6] ={{"|  ", "     ", "     ", "     ", "     ", "     "},
                         {"|  ", "     ", "     ", "     ", "     ", "     "},
                         {"|  ", "     ", "     ", "     ", "     ", "     "},
                         {"|  ", "     ", "     ", "     ", "     ", "     "},
                         {"|  ", "     ", "     ", "     ", "     ", "     "},
                         {"|  ", "     ", "     ", "     ", "     ", "     "}};
};

mainSeat *ms, s;

int main(){
    do{
        options();
    }
    while(true);

    return 0;
}

void welcome(void){
    system("cls");
    char dash[] = "       -------------------------------------------------\n";
    cout << "\n\n"<< dash << "                 BARRIOS Reservation Services!\n" << dash;
}

void menu(void){
    ms = &s;
    cout << "\n\n| Below are the available seats for today: \n" << endl;
    cout << "       ----------------------------------------------\n";
    cout << "       |                   SCREEN                   |\n";
    cout << "       ----------------------------------------------\n";
    for (int x = 0; x < 6; x++){
        cout << "\n            ";
        for(int y = 0; y < 6; y++){
            cout << (*ms).names[x][y] << " ";
        }
            cout << "  |";
        cout << "\n          ";
        for(int y = 0; y < 6; y++){
            cout << (*ms).upuan[x][y] << "     ";
            if (x==0 && y==5)cout<<"\n            -------------------------------------";
        }
        if(x==0) continue;
        cout << "| " << x;
    }
    cout<<"\n            -------------------------------------";
    cout << "\n\n            Legend: O = Available        X = Taken";
}

void options(void){
    system("cls");
    welcome();
    int option;
    cout << "\n              | 1. Search a seat\n              | 2. Reserve a seat"
    <<      "\n              | 3. Cancel the reservation\n              | 4. View Reservation\n              | 5. Quit\n" << endl;
    cin >> option;
        if(option == 1) search(0);
        else if(option == 2) reserveActual();
        else if(option == 3) removeFromFile();
        else if(option == 4) view(1);
        else if(option == 5) quit();
        else cout << "Please enter a valid value";
    option = 0;
}

void reserveActual(){
    system("cls");
    int seatAmount = 0;
    cout << "\nHow many seats do you wish to reserve?" << endl;
    cin >> seatAmount;
    search(seatAmount);
}

void search(int seatAmount){
    system("cls");
    int r;
    char c;
    if(seatAmount == 0){
        menu();
        reserve(3, 0);
    }
    else if(seatAmount > 0){
        menu();
        reserve(1, seatAmount);
    }
}

void reserve(int type, int seatAmount){
    ms = &s;
    int newColumn, row;
    char toReserve, column;
    if(type==1){
        for(int x = 1; x <= seatAmount; x++){
            cout << "\n\n| Please enter seat #"<< x << "\n Enter your desired row (numbers): ";
            cin >> row;
            cout << " Enter your desired column (letters): ";
            cin >> column;
            cout << "\n| You entered seat: " << row << column;
            column = toupper(column);

            if(column == 'A') newColumn = 1;
            if(column == 'B') newColumn = 2;
            if(column == 'C') newColumn = 3;
            if(column == 'D') newColumn = 4;
            if(column == 'E') newColumn = 5;

            string reservedSeat = to_string(row) + column;
            if((*ms).upuan[row][newColumn] == "O"){
            cout << "\n This seat is available! Would you like to reserve it?\n   (Press y for yes, and n for no)\n";
                cin >> toReserve;
                toReserve = toupper(toReserve);
                if(toReserve == 'Y'){
                    (*ms).upuan[row][newColumn] = "X";
                    string name;
                    cout << " Enter your name: ";
                    cin >> name;
                    transform(name.begin(), name.end(), name.begin(), ::toupper);
                    (*ms).names[row][newColumn] = name;

                    file.open("Reservation Database", ios::out | ios::app);
                        file << "Customer Name: " << name << "\nSeat: "<< reservedSeat << endl;
                    file.close();
                }else options();
            }
            else if ((*ms).upuan[row][newColumn] == "X"){
                cout << "\n I'm sorry but this seat is already taken. Would you like to reserve somewhere else?\n   (Press y for yes, and n for no)\n";
                cin >> toReserve;
                toReserve = toupper(toReserve);
                if(toReserve == 'Y') reserveActual();
                else options();
            }
        }
    }
    else if(type == 2){
        for (int x = 1; x < 6; x++){
            for(int y = 1; y < 6; y++){
                if((*ms).upuan[x][y] == "X"){
                    (*ms).upuan[x][y] = "O";
                    (*ms).names[x][y] = "     ";
                }
            }
        }
    }
    else if(type == 3){
        int randomNumber = (rand() % 5) + 1;
        int seatLoop;
        char reservation, reverseColumn;
        newColumn = 1;
        cout << "\nHow many seats do you wish to reserve?" << endl;
            cin >> seatLoop;
        if(seatLoop > 20){
            cout << "You've reached the maximum reservation seat.\n If you wish to reserve more than 20 please contact the manager." << endl;
        }else{
            for(int x = 0; x < seatLoop; x++){
                if(newColumn == 1) reverseColumn = 'A';
                if(newColumn == 2) reverseColumn = 'B';
                if(newColumn == 3) reverseColumn = 'C';
                if(newColumn == 4) reverseColumn = 'D';
                if(newColumn == 5) reverseColumn = 'E';
                
                if((*ms).upuan[randomNumber][newColumn] == "O"){
                    cout << "Recommended seats are: " << endl;
                    cout << "  " << randomNumber << reverseColumn << endl;
                    newColumn++;
                }else if((*ms).upuan[randomNumber][newColumn] == "X"){
                    newColumn++;
                    --x;
                }else{
                    randomNumber++;
                    newColumn = 1;
                    x-=1;
                }
            }
        cout << "\nContinue to reservation?\n   (Press y for yes, and n for no)\n" << endl;
        cin >> reservation;
        reservation = toupper(reservation);
        reservation == 'Y' ? options() : search(0);
        }
    }
}

void removeFromFile(){
    system("cls");
    int r;
    char c, toDelete, cancel, another;
    file.open("Reservation Database", ios::in);
        string laman;
        if(file.good()){
            cout << "\n "<< "Your current reservation is: " << endl;
            while(file.good()){
                getline(file, laman);
                cout << "  "<< laman << endl;
            }
            cout << "| Would you like to cancel your reservation?\n   (Press y for yes, and n for no)\n" << endl;
                    cin >> cancel;
                cancel = toupper(cancel);
                    if(cancel=='Y'){
                        file.close();
                        remove("Reservation Database");
                        reserve(2, 0);
                        cout << "\n...Processing\n\n...Processing Complete\n\nReservation has been deleted" << endl; 
                    }else options();
                cout << "\n Go back to main menu?\n   (Press y for yes, and n for no)\n" << endl;
                    cin >> another;
                    another = toupper(another);
                another == 'Y' ? options() : removeFromFile();
        }else if(!file.good()){
            char blank;
            cout << "You have no reservation yet.\nPlease press q to go back and reserve." << endl;
            cin >> blank;
            file.close();
            options();
        }
}

void view(int version){
    string laman;
    char another;
        file.open("Reservation Database", ios::in);
            if(file.good()){
                welcome();
                cout << "\nHere is your receipt: \n" << endl;
                while(file.good()){
                    getline(file, laman);
                    cout << "  "<< laman << endl;
                }
            }else if(!file.good() && version == 1) cout << "You have no reservations yet" << endl;
        file.close();
    if (version == 1){
        cout << "\n Continue?\n   (Press y for yes, and n for no)\n" << endl;
            cin >> another;
            another = toupper(another);
        another == 'Y' ? options() : options();
    }else{
        cout << "\nThank you for using BARRIOS Reservation Services!\n\n" << endl;
        remove("Reservation Database");
        exit(0);
    }
}
void quit(void){
    system("cls");
    view(0);
}