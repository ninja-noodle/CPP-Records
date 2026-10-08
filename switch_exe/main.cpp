#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    char vCode;
    double vRate;
    double toll, distance;
    
    cout << "Insert vehicle code: ";
    cin >> vCode;
    
    cout << "Insert distance: ";
    cin >> distance;
    
    switch (vCode) {
        case 'C':
        case 'c':
            vRate = 0.5;
            break;
        case 'B':
        case 'b':
            vRate = 0.85;
            break;
        case 'T':
        case 't':
            vRate = 1;
            break;
        case 'M':
        case 'm':
            vRate = 0;
            break;
        default:
            cout << "Wrong vehicle code!";
    }
    
    toll = vRate * distance;
    cout << "Your toll fee: RM" << fixed << setprecision(2) << toll;
    
    
    return 0;
}