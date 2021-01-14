#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
using namespace std;
// testing out read and write stuff
int main(){
    int row = 1;
    char column = 'a';
    string reservedSeat = to_string(row) + column;

    cout << "Output: " << reservedSeat << endl;

    // add to text file
    fstream my_file;
    my_file.open("nicoh Reservation Tickets", ios::out | ios::in);
        // make name to uppercases only
    cout << "\nFile created successfully!";

    cout << "\nenter something for the txt file" << endl;
    char text[100];
    cin.getline(text, sizeof(text));

    // writing on a file
    my_file << text << endl;

    // reading on a file
    my_file >> text;
    cout << text << endl;

    string readText;
    // another way of reading files
        while(getline (my_file, readText)){
            cout << readText;
        }

    my_file.close();
    return 0;
}