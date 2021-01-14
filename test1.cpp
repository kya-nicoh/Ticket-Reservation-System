#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main(){
    int row = 1;
    char column = 'a';
    string reservedSeat = to_string(row) + column;

    cout << "Output: " << reservedSeat;

    // add to text file
    
    return 0;
}