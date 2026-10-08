#include <iostream>

using namespace std;

int main() {
    int sum = 0, num = 0;
    for (int i = 1; i < 6; i++) {
        cout << "Enter a number: ";
        cin >> num;
        sum += num;
    }
    cout << sum;
    return 0;
}