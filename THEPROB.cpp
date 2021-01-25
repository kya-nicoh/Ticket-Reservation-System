#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<fstream>
#include<stdlib.h>
using namespace std;

void menu(void), reserved(void);

struct mainSeat{
    const char *names[6][6] ={{"|  ", "     ", "     ", "     ", "     ", "     "},
                              {"|  ", "     ", "     ", "     ", "     ", "     "},
                              {"|  ", "     ", "     ", "     ", "     ", "     "},
                              {"|  ", "     ", "     ", "     ", "     ", "     "},
                              {"|  ", "     ", "     ", "     ", "     ", "     "},
                              {"|  ", "     ", "     ", "     ", "     ", "     "}};
};

mainSeat *ms, s;

int main(){
    system("cls");

    reserved();

    menu();
}

void menu(void){
    // itong line 32 na to ung problema ng buhay natin puta
    ms = &s;
    cout << "\n\n| Below are the available seats for today: \n" << endl;
    cout << "       ----------------------------------------------\n";
    cout << "       |                   SCREEN                   |\n";
    cout << "       ----------------------------------------------\n";
    for (int x = 0; x < 6; x++){
        for(int y = 0; y < 6; y++){
            cout << (*ms).names[x][y] << " ";
        }
        cout << "\n";
    }
}

void reserved(void){
    ms = &s;
    string name;
    menu();
    
    cout << " Enter your name: ";
        cin >> name;
    (*ms).names[1][1] = name.c_str();
}