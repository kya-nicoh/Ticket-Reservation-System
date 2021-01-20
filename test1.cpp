#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
using namespace std;

void quit(void), change(void), database(void), menuName(void);

int main(){
    system("cls");
    menuName();

    return 0;
}

void menuName(void){
    struct mainSeat{
    const char *upuan[6][6] = {{"   ", "A", "B", "C", "D", "E"},
                               {"1 |", "O", "O", "O", "O", "O"},
                               {"2 |", "O", "O", "O", "O", "O"},
                               {"3 |", "O", "O", "O", "O", "O"},
                               {"4 |", "O", "O", "O", "O", "O"},
                               {"5 |", "O", "O", "O", "O", "O"}};
    };
    mainSeat *ms, s;
    ms = &s;
    char name[6] = {};

    for (int x = 0; x < 6; x++){
        cout << "\n                 ";
        for(int y = 0; y < 6; y++){
            cout << (*ms).upuan[x][y] << " ";
        }
    }
    cout << "\n\n                           Legend: O = Available";
    cout << "\n                                   X = Taken";


}

void change(void){
    fstream my_file;
    my_file.open("Reserved Database.txt", ios::out);
    
    char text = ' ';
    my_file << text << endl;
    my_file.close();
}

void database(void){
    /* int row = 1;
    char column = 'a';
    string reservedSeat = to_string(row) + column;
    cout << "Output: " << reservedSeat << endl; */

    // add to text file
    fstream my_file;
    my_file.open("Reserved Database.txt", ios::out | ios::in);
        // make name to uppercases only
    cout << "\nFile created successfully!";
    cout << "\nenter something for the txt file" << endl;
    char text[1000];
    cin.getline(text, sizeof(text));
    // writing on a file
    my_file << text << endl;

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
    delete1 == 'y' ? change() : exit(0);
    
    my_file.close();
}