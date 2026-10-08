#include <iostream>

using namespace std;

double getLength();
double getWidth();
double getArea(double, double);
void displayData(double, double, double);

double getLength () {
    double l;
    cout << "Please enter length: ";
    cin >> l;
    return l;
}

double getWidth () {
    double w;
    cout << "Please enter width: ";
    cin >> w;
    return w;
}

double getArea(double length, double width) {
    double area;
    area = length * width;
    return area;
}

void displayData(double length, double width, double area) {
    cout << "[OUTPUT]"
    << endl << "Length: " << length
    << endl << "Width: " << width
    << endl << "Area: " << area;
}

int main() {
    double length, width, area;
    length = getLength();
    width = getWidth();
    area = getArea(length, width);
    displayData(length, width, area);
    return 0;
}

