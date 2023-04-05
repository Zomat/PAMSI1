#include <iostream>
#include "include/Palindrom.h"

int main() {
    std::cout << "Czy poniższe wyrazy to palindromy?" << std::endl;
    std::cout << "kajak: " << (jestPal("kajak") ? "TAK" : "NIE") << std::endl;
    std::cout << "kamilslimak: " <<  (jestPal("kamilslimak") ? "TAK" : "NIE") << std::endl;
    std::cout << "pamsi: " <<  (jestPal("pamsi") ? "TAK" : "NIE") << std::endl;
    return 0;
}
