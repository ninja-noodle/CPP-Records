#include <iostream>

using namespace std;

int main() {
    int num;
    
    cout << "How many rows? ";
    cin >> num;
    
    for (int row=1; row <= num; row++) {
        for (int col=1; col <= row; col++) {
            cout << col << " ";
        }
        cout << endl;
    }
    
    return 0;
}