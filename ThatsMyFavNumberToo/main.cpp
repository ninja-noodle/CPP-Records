#include <iostream>

int main() {
    int fav_number;
    std::cout << "Tell me your favorite number: ";
    std::cin >> fav_number;
    
    std::cout << "Oh! it's " << fav_number << "? That's my favorite number too!\n" << std::endl;
    std::cout << "No, for real, " << fav_number << " is my favourite number!" << std::endl;
    return 0;
    
}