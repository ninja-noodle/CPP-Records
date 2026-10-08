#include <iostream>

using namespace std;

int main() {
    int x = 3, y = 5;
    char code = 'A', code2 = 'S';
    bool p = false;
    bool q;
    cout << ((x + 3) > (y + 5)) << endl;
    cout << (((p != 0) + 10) && ((p + 10) == 10)) << endl;
    cout << ((code == 'C') || (code2 != 'S')) << endl;
    q = x - y;
    x = q + 1;
    cout << "The value of q is " << q << endl;
    cout << "The value of x is " << x << endl;
    return 0;
}