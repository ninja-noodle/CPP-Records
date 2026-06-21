#include <iostream>

using namespace std;

int main() {
    int num1;
    double num2;
    
    cout << "Type in two numbers(one whole and one float): ";
    // Try inputting a float for the first number. eg 10.5, 10 will be num1 and .5 will be num2
    cin >> num1 >> num2;
    cout << "Integer: " << num1 << endl;
    cout << "Float: " << num2 << endl;
    
    //cout << "Answer: " << num1 + num2;
    
    return 0;
}