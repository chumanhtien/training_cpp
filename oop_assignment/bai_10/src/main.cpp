#include <iostream>
#include "../inc/Text.h"
using namespace std;

int main() {
    // Text txt("         Hello, I'm Chu Manh Tien. I'm from Vietnam. Vietnam is the best.             ");
    std::string txtTest;
    cout << "Input text: ";
    getline(cin, txtTest);

    Text txt(txtTest);

    std::cout << "Original Text: \"" << txt.getText() << "\"\n";
    std::cout << "Number of words: " << txt.countWords() << "\n";
    std::cout << "Number of 'A' characters: " << txt.countA() << "\n";

    txt.normalize();
    std::cout << "Normalized Text: \"" << txt.getText() << "\"\n";

    return 0;
}
