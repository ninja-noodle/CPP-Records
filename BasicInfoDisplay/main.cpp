#include <iostream>

int main() {
    std::string name;
    int age;
    std::string fav_color;
    int fav_number;
    
    std::cout << "What's your name?\n";
    // for getting input with multiple whitespaces
    std::getline(std::cin, name);
    
    std::cout << "How old are you?\n";
    std::cin >> age;
    
    // cin >> the newline character (\n) from when we hit Enter is left sitting in the input buffer
    
    /* 
     without the code below, the subsequent getline() will read that newline and skip user input
     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    */
    
    std::cout << "Your favorite color?\n";
    // std::ws flushes leading whitespaces and leftover newlines to prevent skipping
    std::getline(std::cin >> std::ws, fav_color);
    // std::cin first, recognizes it as the input stream, and then looks at the >> operator to see what it should do to that stream
    
    std::cout << "Your favorite number?\n";
    std::cin >> fav_number;
    
    std::cout << "Here's your information:" << std::endl;
    std::cout << "Your name: " << name << std::endl;
    std::cout << "Your age: " <<  age << std::endl;
    std::cout << "Your favorite color: " <<  fav_color << std::endl;
    std::cout << "Your favorite number: " <<  fav_number << std::endl;
    
    return 0;
}