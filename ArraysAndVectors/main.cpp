#include <iostream>

using namespace std;

int main() {
//    char vowels [5] {'a','e','i','o','u'};
//    cout << vowels[0] << endl;

    int num_set [5] {3,4,5,6,7};
/*
 * int num_set[5] = {3,4,5,6,7}; 
 * 
 * can also do like this but not recommended since it can cause
 * "narrowing conversion". The first method is preferred
 * (for example, it won't accidentally let you sneak a decimal float into an int array 
 * without throwing a compiler error)
*/

    cout << "Value at index[4]: " << num_set[4] << endl;
    cout << "Enter new value for index[4]: ";
    cin >> num_set[4];
//    num_set[4] = 24; 
    cout << "Value at index[4]: " << num_set [4];
    
    return 0;
}