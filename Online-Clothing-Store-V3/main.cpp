#include <iostream>
#include <fstream>
#include <iomanip> 
#include <string>
#include <limits>
#include <ctime>

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
        case 'A': // polo shirt
            unitPrice = 45.00;
            break;
        case 'B': // baggie jeans
            unitPrice = 120.00;
            break;
        case 'C': // vintage hoodie
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

// function to calculate discount amount directly based on total base price
double calculateDiscount(double totalBasePrice) {
    double discountAmount = 0.0;
    
    if (totalBasePrice >= 200.00) {
        discountAmount = totalBasePrice * 0.15; // 15% discount for RM200+
    } else if (totalBasePrice >= 100.00) {
        discountAmount = totalBasePrice * 0.10; // 10% discount for RM100+
    } else {
        discountAmount = 0.0;
    }
    
    return discountAmount;
}

// function to get discount percentage for display purposes
double getDiscountPercent(double totalBasePrice) {
    if (totalBasePrice >= 200.00) {
        return 0.15;
    } else if (totalBasePrice >= 100.00) {
        return 0.10;
    } else {
        return 0.0;
    }
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

// function to get current date and time as a formatted string
string getCurrentDateTime() {
    time_t now = time(0);
    char dt[80];
    tm *ltm = localtime(&now);
    strftime(dt, sizeof(dt), "%d-%m-%Y %H:%M:%S", ltm);
    return string(dt);
}

// function to output receipt to terminal and save to file simultaneously
void printReceipt(string customerName, const string itemNames[], const int itemQuantities[], const double itemPrices[], int cartSize, double totalBasePrice, double discountPercent, double discount, double finalPrice, string dateTime) {
    
    // open file for writing (appending logs)
    ofstream outFile("clothes_receipt.txt", ios::app);
    bool fileOpen = outFile.is_open();

    if (!fileOpen) {
        cout << "Error: unable to open receipt file for writing.\n";
    }

    // helper text block stream logic for both cout and ofstream
    // prints to terminal first, then saves to file if open
    
    // Header block
    cout << "========================================\n"
         << "                RECEIPT                 \n"
         << "========================================\n"
         << "Date & Time   : " << dateTime << "\n"
         << "Customer Name : " << customerName << "\n"
         << "----------------------------------------\n"
         << "Purchased Items:\n";

    if (fileOpen) {
        outFile << "========================================\n"
                << "                RECEIPT                 \n"
                << "========================================\n"
                << "Date & Time   : " << dateTime << "\n"
                << "Customer Name : " << customerName << "\n"
                << "----------------------------------------\n"
                << "Purchased Items:\n";
    }
         
    // items loop block
    for (int i = 0; i < cartSize; ++i) {
        cout << "  - " << itemNames[i] << "\n"
             << "    Qty: " << itemQuantities[i] << " | Subtotal: RM " << fixed << setprecision(2) << itemPrices[i] << "\n";
             
        if (fileOpen) {
            outFile << "  - " << itemNames[i] << "\n"
                    << "    Qty: " << itemQuantities[i] << " | Subtotal: RM " << fixed << setprecision(2) << itemPrices[i] << "\n";
        }
    }
    
    // footer totals block
    cout << "----------------------------------------\n"
         << fixed << setprecision(2)
         << "Total Price   : RM " << totalBasePrice << "\n"
         << "Discount      : RM " << discount << " (" << discountPercent * 100 << "%)" << "\n"
         << "Final Price   : RM " << finalPrice << "\n"
         << "========================================\n\n";

    if (fileOpen) {
        outFile << "----------------------------------------\n"
                << fixed << setprecision(2)
                << "Total Price   : RM " << totalBasePrice << "\n"
                << "Discount      : RM " << discount << " (" << discountPercent * 100 << "%)" << "\n"
                << "Final Price   : RM " << finalPrice << "\n"
                << "========================================\n\n";
                
        outFile.close();
        cout << "Receipt successfully saved to clothes_receipt.txt\n";
    }
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
                cout << "Enter quantity: ";
                if (cin >> quantity) {
                    if (quantity > 0) {
                        break;
                    } else {
                        cout << "Oh no! Quantity must be greater than 0\n";
                    }
                } else {
                    cout << "Invalid input! Please enter numbers only\n";
                    cin.clear();
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

        // calculate discount directly using calculateDiscount function
        double discount = calculateDiscount(grandTotalBasePrice);
        double discountPercent = getDiscountPercent(grandTotalBasePrice);
        double finalPrice = grandTotalBasePrice - discount;

        // get current system date and time
        string purchaseDateTime = getCurrentDateTime();

        // print itemized receipt to terminal and save to file automatically
        cout << "\n";
        printReceipt(customerName, cartItemNames, cartQuantities, cartItemPrices, cartSize, grandTotalBasePrice, discountPercent, discount, finalPrice, purchaseDateTime);

        // ask if user want to start a brand new customer session
        cout << "\nDo you want to start a new customer session? (Y/N): ";
        cin >> continueSession;
        while (toupper(continueSession) != 'Y' && toupper(continueSession) != 'N') {
            cout << "Invalid choice! Please enter Y or N: ";
            cin >> continueSession;
        }
    }

    cout << "\nThank you for shopping with Urban Threads Boutique :)\n";
    return 0;
}