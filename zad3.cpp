#include <iostream>
#include <string>

int Potega(int x, int p) {
    if (p == 0) return 1;
    if (p == 1) return x;
    int tmp = Potega(x, p / 2);
    int result = tmp * tmp;
    if (p % 2 == 1) result *= x;
    return result;
}

int Silnia(int x) {
    return x <= 1 ? 1 : x * Silnia(x - 1);
}

int main() {
    std::cout << "Potęga: 2^10 = "<<Potega(2, 10) << std::endl;
    std::cout << "Silnia: 5! = "<<Silnia(5) << std::endl;
    return 0;
}
