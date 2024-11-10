#include <iostream>
#include <cctype>
#include <string>

void countLetters(const std::string& str, int& numLetters, int& numDigits) {
    numLetters = 0;
    numDigits = 0;
    for (int i= 0 ; i < str.size(); i++) 
    {
        if (std::isalpha(str[i])) {
            ++numLetters;
        } else if (std::isdigit(str[i])) {
            ++numDigits;
        }
    }
}

int main() {
    std::string str = "aaaa123";
    int letters, digits;
    countLetters(str, letters, digits);
    std::cout << "Letters: " << letters << ", Digits: " << digits << std::endl;
    return 0;
}