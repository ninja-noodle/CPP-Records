#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int day;
    float fine;
    
    cout << "Enter number of days late: ";
    cin >> day;
    
    if (day < 3)
        fine = 0.00;
    else if (day >= 3 && day <= 7)
        fine = 6.00;
    else if (day > 7 && day <= 10)
        fine = 10.00;
    else if (day > 10)
        fine = 20.00;
        
    cout << "Your late return fee is RM" << fixed << setprecision(2) << fine;
    return 0;
}