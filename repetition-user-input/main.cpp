#include <iostream>

using namespace std;

void repetition_do_while(int);
void repetition_while(int);
void repetition_for_loop(int);

// repetition using C++ do while loops
void repetition_do_while(int num) {
    int i = 1, limit;
    limit = num + 1;
    do {
        cout << i << ": " << "I love Programming" << endl;
        i++;
    } while (i < limit);
}

// repetition using C++ while loops
void repetition_while(int num) {
    int i = 1, limit;
    limit = num + 1;
    while (i < limit) {
        cout << i << ": " << "I love Programming" << endl;
        i++;
    }
}

// repetition using C++ for loops
void repetition_for_loop(int num) {
    int limit;
    limit = num + 1;
    for (int i = 1; i < limit; i++) {
        cout << i << ": " << "I love Programming" << endl;
    }
}

int main() {
    int num;
    cout << "Enter number to be repeated: ";
    cin >> num;
    
    cout << "Using do while loops" << endl;
    repetition_do_while(num);
    
    cout << endl << "Using while loops" << endl;
    repetition_while(num);
    
    cout << endl << "Using for loops" << endl;
    repetition_for_loop(num);
    
    return 0;
}