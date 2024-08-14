#include <iostream>

int days_in_year(int Y) {
    if (Y % 4 != 0) {
        return 365;
    } else if (Y % 100 != 0) {
        return 366;
    } else if (Y % 400 == 0) {
        return 366;
    } else {
        return 365;
    }
}

int main() {
    int Y;
    std::cin >> Y;
    std::cout << days_in_year(Y) << std::endl;
    return 0;
}