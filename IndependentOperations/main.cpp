#include <iostream>

using namespace std;

int main() {
    int operation = 1;
    
    while (operation <= 8) {
        int data1 = 3, data2 = 6, data3 = 10, data4 = 15;
        int result = 0;

        switch (operation) {
            case 1:
                cout << "(1) data1 += 5                 -> ";
                result = (data1 += 5);
                break;
            case 2:
                cout << "(2) data1 = data1 + 2          -> ";
                result = (data1 = data1 + 2);
                break;
            case 3:
                cout << "(3) data2 += data1             -> ";
                result = (data2 += data1);
                break;
            case 4:
                cout << "(4) data2 = data2 + data1--    -> ";
                result = (data2 = data2 + data1--);
                break;
            case 5:
                cout << "(5) data3 -= 2 * --data2       -> ";
                result = (data3 -= 2 * --data2);
                break;
            case 6:
                cout << "(6) data3 *= data3 - 1         -> ";
                result = (data3 *= data3 - 1);
                break;
            case 7:
                cout << "(7) data4 -= data3++           -> ";
                result = (data4 -= data3++);
                break;
            case 8:
                cout << "(8) data4 = data4 * ++data3    -> ";
                result = (data4 = data4 * ++data3);
                break;
        }

        cout << result << endl;
        operation++;
    }
    
    return 0;
}