#include <iostream>

using namespace std;

int main() {
    int room_length {0};
    cout << "Enter the length of the room." << endl;
    cin >> room_length;
    
    int room_width {0};
    cout << "Enter the width of the room." << endl;
    cin >> room_width;
    
    cout << "Area: " << room_length * room_width << " unit squared";
    
    return 0; 
}