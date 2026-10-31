#include <iostream>
#include <iomanip> 
#include <string>
#include <limits>

using namespace std;

// function to clear the terminal screen
void clearScreen() {
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#else
    system("clear");
#endif
}

// function to calc total base price for a given clothes code
double calcPrice(char clothesCode, int quantity) {
    double unitPrice = 0.0;
    
    switch (toupper(clothesCode)) {
        case 'A': // classic T-Shirt
            unitPrice = 45.00;
            break;
        case 'B': // denim jeans
            unitPrice = 120.00;
            break;
        case 'C': // winter jacket
            unitPrice = 180.00;
            break;
        case 'D': // knitted sweater
            unitPrice = 95.00;
            break;
        case 'E': // casual shorts
            unitPrice = 60.00;
            break;
        default:
            unitPrice = 0.0;
            break;
    }
    
    return unitPrice * quantity;
}

// function to get the unit price for a single item
double getUnitPrice(char clothesCode) {
    switch (toupper(clothesCode)) {
        case 'A': return 45.00;
        case 'B': return 120.00;
        case 'C': return 180.00;
        case 'D': return 95.00;
        case 'E': return 60.00;
        default:  return 0.00;
    }
}


// function to get discount percentage
double getDiscount(double totalBasePrice) {
    double discount = 0.0;
    
    if (totalBasePrice >= 200.00) {
        discount = 0.15;
    } else if (totalBasePrice >= 100.00) {
        discount = 0.10;
    } else {
        discount = 0.0;
    }
    
    return discount;
}

// function to calc discount
double calculateDiscount(double totalBasePrice, double discount) {
    double discountAmount = 0.0;
    
    if (totalBasePrice >= 200.00) {
        discountAmount = totalBasePrice * discount;
    } else if (totalBasePrice >= 100.00) {
        discountAmount = totalBasePrice * discount;
    } else {
        discountAmount = 0.0;
    }
    
    return discountAmount;
}

// function to get the clothing name
string getClothesName(char clothesCode) {
    switch (toupper(clothesCode)) {
        case 'A': return "Polo Shirt";
        case 'B': return "Baggie Jeans";
        case 'C': return "Vintage Hoodie";
        case 'D': return "Knitted Sweater";
        case 'E': return "Casual Shorts";
        default:  return "Unknown Item";
    }
}

// function to output receipt
void printReceipt(string customerName, const string itemNames[], const int itemQuantities[], const double itemPrices[], int cartSize, double totalBasePrice, double discountPercent, double discount, double finalPrice) {
    // helper lambda or inline printing to console and file cleanly
    auto writeReceipt = [&](ostream &out) {
        out << "========================================\n"
             << "         CLOTHING SHOP RECEIPT          \n"
             << "========================================\n"
             << "Customer Name : " << customerName << "\n"
             << "----------------------------------------\n"
             << "Purchased Items:\n";
             
        for (int i = 0; i < cartSize; ++i) {
            out << "  - " << itemNames[i] << "\n"
                 << "    Qty: " << itemQuantities[i] << " | Subtotal: RM " << fixed << setprecision(2) << itemPrices[i] << "\n";
        }
        
        out << "----------------------------------------\n"
             << fixed << setprecision(2)
             << "Total Price   : RM " << totalBasePrice << "\n"
             
             << "Discount      : RM " << discount << " (" << discountPercent * 100 << "%)" <<"\n"
             << "Final Price   : RM " << finalPrice << "\n"
             << "========================================\n\n";
    };

    // print to screen
    writeReceipt(cout);
}

int main() {
    char continueSession = 'Y';
    bool firstRun = true;

    while (toupper(continueSession) == 'Y') {
        if (!firstRun) {
            clearScreen();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        firstRun = false;

        // display store header
        cout << "\n========================================\n";
        cout << "         URBAN THREADS BOUTIQUE         \n";
        cout << "========================================\n";
        cout << "Available Clothing Items:\n";
        cout << "  [A] Polo Shirt       - RM 45.00\n";
        cout << "  [B] Baggie Jeans     - RM 120.00\n";
        cout << "  [C] Vintage Hoodie   - RM 180.00\n";
        cout << "  [D] Knitted Sweater  - RM 95.00\n";
        cout << "  [E] Casual Shorts    - RM 60.00\n";
        cout << "----------------------------------------\n";

        string customerName;
        
        cout << "Enter customer name: ";
        getline(cin, customerName);
        while (customerName.empty()) {
            cout << "Oh no! Name cannot be empty.\nPlease re-enter customer name: ";
            getline(cin, customerName);
        }

        // arrays to hold the user shopping cart for current session
        const int MAX_CART_ITEMS = 100;
        string cartItemNames[MAX_CART_ITEMS];
        int cartQuantities[MAX_CART_ITEMS];
        double cartItemPrices[MAX_CART_ITEMS];
        int cartSize = 0;
        
        double grandTotalBasePrice = 0.0;

        char addMore = 'Y';
        while (toupper(addMore) == 'Y' && cartSize < MAX_CART_ITEMS) {
            char clothesCode;
            int quantity = 0;

            cout << "\nEnter clothes code (A-E): ";
            cin >> clothesCode;
            // clothes code validation
            while (toupper(clothesCode) < 'A' || toupper(clothesCode) > 'E') {
                cout << "Oh no! Invalid code\nPlease enter a valid clothes code (A-E): ";
                cin >> clothesCode;
            }

            // quantity validation
            while (true) {
                cout << "Enter quantity purchased: ";
                if (cin >> quantity) {
                    if (quantity > 0) {
                        break;
                    } else {
                        cout << "Oh no! Quantity must be greater than 0 :(\n";
                    }
                } else {
                    cout << "Oh no! Invalid input! Please enter numbers only :(\n";
                    // clearing the fail error caused in cin by invalid inputs
                    cin.clear();
                    // clearing the input cin so that it can be looped and stopped at cin line
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

            // calculate item price and store into cart arrays
            double itemTotalPrice = calcPrice(clothesCode, quantity);
            string itemName = getClothesName(clothesCode);

            cartItemNames[cartSize] = itemName;
            cartQuantities[cartSize] = quantity;
            cartItemPrices[cartSize] = itemTotalPrice;
            cartSize++;

            grandTotalBasePrice += itemTotalPrice;

            // prompt to add more items to cart
            cout << "Would you like to add another clothing item to your cart? (Y/N): ";
            cin >> addMore;
            while (toupper(addMore) != 'Y' && toupper(addMore) != 'N') {
                cout << "Invalid choice! Please enter Y or N: ";
                cin >> addMore;
            }
        }

        // calculate discount on the combined grand total base price
        double discountPercent = getDiscount(grandTotalBasePrice);
        double discount = calculateDiscount(grandTotalBasePrice, discountPercent);
        double finalPrice = grandTotalBasePrice - discount;

        // print itemized combined receipt and save to file
        cout << "\n";
        printReceipt(customerName, cartItemNames, cartQuantities, cartItemPrices, cartSize, grandTotalBasePrice, discountPercent, discount, finalPrice);

        // ask if they want to start a brand new customer session
        cout << "Do you want to start a new customer session? (Y/N): ";
        cin >> continueSession;
        while (toupper(continueSession) != 'Y' && toupper(continueSession) != 'N') {
            cout << "Invalid choice! Please enter Y or N: ";
            cin >> continueSession;
        }
    }

    cout << "\nThank you for shopping with Urban Threads!\n";
    return 0;
}