#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int i, day;
    double hour, salary, total = 0.0;

    do
    {
        cout << "How many working days for this week? ";
        cin >> day;
        
        if (day < 1 || day > 7) {
            cout << "Only 7 days a week." << endl;
        }
    }
    while(day < 1 || day > 7);

    for(i = 1; i <= day; i++)
    {
        cout << "Working hour Day " << i << ": ";
        cin >> hour;
        total += hour;
    }

    salary = total * 8.0;

    cout << "\nTotal hours : " << total << endl;
    cout << "Your salary : RM" << fixed << setprecision(2) << salary << endl;

    return 0;
}