#include <iostream>

using namespace std;

int main() {
    int num1, num2, product;
    cout << "Enter the first integer: ";
    cin >> num1;
    cout << "Enter the second integer: ";
    cin >> num2;
    
    product = num1 * num2;
    
    cout << "The product of " << num1 << " and " << num2 << " is " << product << ".";
    
    return 0;
}