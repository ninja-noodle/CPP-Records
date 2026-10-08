#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    std::string food_item;
    int item_num, quantity = 0;
    float total, price = 0;
    
    cout << endl << "Welcome to MamiDurra Café"
    << endl 
    << endl << "Our Menu"
    << endl << "1. Nasi Dagang (RM 4.00)"
    << endl << "2. Nasi Lemak (RM 3.50)"
    << endl << "3. Nasi Beriani (RM 6.00)"
    << endl << "4. Nasi Minyak (RM 5.00)"
    << endl
    << endl << "What would you like to order? ";
    
    cin >> item_num;
    
    cout << "How many? ";
    cin >> quantity;
    
    switch (item_num) {
        case 1:
            food_item = "Nasi Dagang";
            price = 4.00;
            break;
        case 2:
            food_item = "Nasi Lemak";
            price = 3.50;
            break;
        case 3:
            food_item = "Nasi Beriani";
            price = 6.00;
            break;
        case 4:
            food_item = "Nasi Minyak";
            price = 5.00;
            break;
    }
    
    total = price * quantity;
    
    cout << "Thank you. You have ordered " << quantity << "x " << food_item << "."
    << endl << "Please pay RM " << fixed << setprecision(2) << total << "."
    << endl
    << endl << "Enjoy your meal." << endl;
    
    return 0;
}