#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
using namespace std;

void quit(void), change(void);
// testing out read and write stuff
int main(){
    /* int row = 1;
    char column = 'a';
    string reservedSeat = to_string(row) + column;
    cout << "Output: " << reservedSeat << endl; */

    // add to text file
    fstream my_file;
    my_file.open("Reserved Database.txt", ios::out);
        // make name to uppercases only
    cout << "\nFile created successfully!";
    cout << "\nenter something for the txt file" << endl;
    char text[100];
    cin.getline(text, sizeof(text));
    // writing on a file
    my_file << text << endl;

    my_file.close();


    my_file.open("Reserved Database.txt", ios::in);
    
    // reading on a file
    
    while(!my_file.eof()){
        string readText;

        my_file >> readText;

        cout << readText << endl;
    }
    // another way of reading files
        // while(getline (my_file, readText)){
        //     cout << readText;
        // }
    char delete1;
    cout << "delete?" << endl;
    cin >> delete1;
    delete1 == 'y' ?  change() : exit(0);
    
    my_file.close();
    return 0;
}

void change(void){
    fstream my_file;
    my_file.open("Reserved Database.txt", ios::out);
    
    char text = ' ';
    my_file << text << endl;
}