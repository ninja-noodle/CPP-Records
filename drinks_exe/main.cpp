#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    char drink_code;
    std::string drink;
    int  quantity;
    double price=0, total_cost=0, total_paid=0, change=0;
    
    cout << "Our Menu: " << endl 
    << "A - Soya RM 2.00" << endl 
    << "B - Coke RM 2.40" << endl
    << "C - Lychee RM 1.80" << endl
    << "D - Chocolate RM 2.50" << endl << endl
    << "Pleae select your drink: ";
    
    cin >> drink_code;
    
    cout << "Quantity: ";
    cin >> quantity;
    
    switch (drink_code) {
        case 'A':
        case 'a':
            price = 2.00;
            drink = "Soya";
            break;
        
        case 'B':
        case 'b':
            price = 2.40;
            drink = "Coke";
            break;
            
        case 'C':
        case 'c':
            price = 1.80;
            drink = "Lychee";
            break;
            
        case 'D':
        case 'd':
            price = 2.50;
            drink = "Chocolate";
            break;
        
        default:
            cout << "Invalid choice!";
    }
    
    total_cost = price * quantity;
    
    cout << "Order details: " << endl 
    << drink << " x" << quantity << endl 
    << "Total: " << fixed << setprecision(2) << total_cost << endl; 
    
    cout << "Enter amount paying: ";
    cin >> total_paid;
    
    if (total_paid >= total_cost) {
        change = total_paid - total_cost;
        cout << "Change: " << fixed << setprecision(2) << change;
    } else {
        cout << "Insufficient amount!";
    }
    return 0;
}