#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    int birth_day;
    string birth_month;
    cout << "Type in your date of birth :D (eg. 6 June)" << endl;
    
    // Assigning different types of input from one single input into different types of variables
    // ORDER MATTERS BTW (doesn't work if the user input is June 6)
    cin >> birth_day >> birth_month;
    
    cout << "Birth Day: " << birth_day << endl;
    cout << "Birth Month: " << birth_month << endl;
    
    return 0;
}