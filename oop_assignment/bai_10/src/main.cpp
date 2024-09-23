#include <iostream>
#include "../inc/Text.h"

int main() {
    Text txt("         Hello, I'm Chu Manh Tien. I'm from Vietnam. Vietnam is the best.             ");

    std::cout << "Original Text: \"" << txt.getText() << "\"\n";
    std::cout << "Number of words: " << txt.countWords() << "\n";
    std::cout << "Number of 'A' characters: " << txt.countA() << "\n";

    txt.normalize();
    std::cout << "Normalized Text: \"" << txt.getText() << "\"\n";

    return 0;
}
