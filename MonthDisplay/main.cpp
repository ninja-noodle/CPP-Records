#include <iostream>

using namespace std;

int main() {
    std::string month;
    int num = 0, loop = 1;
    
    while (loop != 0) {
        cout << "Enter a number between 1 and 12.\nYour number: ";
        cin >> num;
        if (num >= 1 && num <= 12) 
            loop -= 1;
        else
            cout << "Number must be between 1 and 12!" << endl << endl;
    }
    
    switch (num) {
        case 1:
            month = "January";
            break;
        case 2:
            month = "February";
            break;
        case 3:
            month = "March";
            break;
        case 4:
            month = "April";
            break;
        case 5:
            month = "May";
            break;
        case 6:
            month = "June";
            break;
        case 7:
            month = "July";
            break;
        case 8:
            month = "August";
            break;
        case 9:
            month = "September";
            break;
        case 10:
            month = "October";
            break;
        case 11:
            month = "November";
            break;
        case 12:
            month = "December";
            break;
    }
    
    cout << endl << "Month based on number: " << month << endl;
    
    return 0;
}