#include <iostream>

using namespace std;

int main() {
    int count = 0, positive = 0, negative = 0, number;
    
    while (count < 30) {
        cout << "Enter a number: ";
        cin >> number;
        if (number < 0) {
            negative += 1;
        } else if (number > 0) {
            positive += 1;
        }
        count++;
    }
    cout << "Total positive numbers: " << positive << endl;
    cout << "Total negative numbers: " << negative << endl;
    
    return 0;
}