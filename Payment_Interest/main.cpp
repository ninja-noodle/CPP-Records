#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double house_price,total_price, monthly_repayment, interest, interest_rate = 0;
    int years_of_term;
    
    cout << "-------------------------------------------------------------------------"
    << endl << "                   Iskandar Medini Consultant Co Ltd                  "
    << endl << "-------------------------------------------------------------------------"
    << endl << "                       Home Loan Auto Calculator                       "
    << endl << "-------------------------------------------------------------------------"
    << endl << endl;
    
    cout << "Enter property price (eg. 912500): RM ";
    cin >> house_price;
    cout << endl;
    
    cout << "Enter years of term applied (eg. 10): ";
    cin >> years_of_term;
    cout << endl;
    
    if (years_of_term >= 25)
        interest_rate = 0.075;
        
    else if (years_of_term >= 20)
        interest_rate = 0.065;
        
    else if (years_of_term >= 15)
        interest_rate = 0.055;
        
    else if (years_of_term >= 10)
        interest_rate = 0.045;
        
    else if (years_of_term < 10)
        interest_rate = 0.04;
        
    interest = house_price * interest_rate;
    total_price = house_price + interest;
    monthly_repayment = total_price / years_of_term;
    
    cout << "-------------------------------------------------------------------------"
    << endl << "Detailed Breakdown:"
    << endl << "Interest rate: " << interest_rate
    << endl << "Total interest: " << house_price << " x " << interest_rate << " = RM " << interest
    << endl << endl << "Total price: RM " << total_price
    << endl << endl << fixed <<  "Monthly repayment: RM " << setprecision(2) << monthly_repayment;
    
    cout << endl;
    return 0;
}