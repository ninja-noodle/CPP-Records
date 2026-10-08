#include <iostream>

using namespace std;

// repetition using C++ do while loops
void repetition_do_while() {
    int i = 1;
    do {
        cout << i << ": " << "I love Programming" << endl;
        i++;
    } while (i < 31);
}

// repetition using C++ while loops
void repetition_while() {
    int i = 1;
    while (i < 31) {
        cout << i << ": " << "I love Programming" << endl;
        i++;
    }
}

// repetition using C++ for loops
void repetition_for_loop() {
    for (int i = 1; i < 31; i++) {
        cout << i << ": " << "I love Programming" << endl;
    }
}

int main() {
    cout << "Using do while loops" << endl;
    repetition_do_while();
    
    cout << endl << "Using while loops" << endl;
    repetition_while();
    
    cout << endl << "Using for loops" << endl;
    repetition_for_loop();
    return 0;
}