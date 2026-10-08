#include <iostream>
using namespace std;

double avgArray(const int arr[], int size);

int main() {
    const int SIZE = 10;
    int userNums[SIZE];

    cout << "Enter 10 numbers: " << endl;
    for (int count = 0; count < SIZE; count++){
        cout << "->" << " ";
        cin >> userNums[count]; 
    }
    cout << "The average of those numbers is ";
    cout << avgArray(userNums, SIZE) << endl;
    return 0;
}

double avgArray(const int arr[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}


//#include <iostream>
//using namespace std;
//
//int main() {
//    char letter[10];
//
//    cout << "Enter 10 characters: ";
//    
//    for (int i = 0; i < 10; i++) {
//        cin >> letter[i];
//    }
//
//    cout << "The characters in reverse order: ";
//    for (int i = 9; i >= 0; i--) {
//        cout << letter[i] << " ";
//    }
//    cout << endl;
//
//    return 0;
//}


//#include <iostream>
//using namespace std;
//
//int main() {
//    const int SIZE = 10;
//    int num[SIZE];
//
//    cout << "Enter 10 numbers: ";
//    
//    for (int i = 0; i < SIZE; i++) {
//        cin >> num[i];
//    }
//
//    cout << "The numbers are: ";
//    for (int i = 0; i < SIZE; i++) {
//        cout << num[i] << " ";
//    }
//    cout << endl;
//
//    return 0;
//}