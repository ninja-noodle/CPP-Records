#include <iostream>

using namespace std;

int main() {
    const double rate {0.31};
    
    cout << "Malaysian Ringgit to Singapore Dollar Converter" << endl;
    cout << "Exchange rate: " << rate << " [24-06-2026]" << endl;
 
    double myr {0};
    cout << endl << "Enter MYR amount (e.g. 30.50): ";
    cin >> myr;
    cout << endl;
    cout << "SGD: " << myr * rate;
    return 0;
}