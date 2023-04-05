#include "Palindrom.h"

bool jestPal(std::string word) {
    if (word.length() <= 1) {
        return true;
    }

    if (word[0] != word[word.length()-1]) {
        return false;
    }

    return jestPal(word.substr(1, word.length()-2));
}
