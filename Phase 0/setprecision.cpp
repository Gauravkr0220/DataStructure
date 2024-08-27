#include <iostream>
#include <iomanip>

int main() {
    double number = 123.456789;
    
    // Set precision to 5 digits in total
    std::cout <<std:: fixed<< std::setprecision(5) << number << std::endl;  // Output might be in scientific notation for large numbers

    return 0;
}
