#include "../inc/Text.h"

// Default constructor
Text::Text() : text("") {}

Text::Text(const std::string& st) : text(st) {}

int Text::countWords() const {
    std::istringstream iss(text);
    std::string word;
    int count = 0;
    while (iss >> word) {
        count++;
    }
    return count;
}

int Text::countA() const {
    int count = 0;
    for (char c : text) {
        if (std::toupper(c) == 'A') {
            count++;
        }
    }
    return count;
}

void Text::normalize() {
    // Remove leading and trailing whitespace
    size_t start = text.find_first_not_of(" \t");
    size_t end = text.find_last_not_of(" \t");
    text = (start == std::string::npos) ? "" : text.substr(start, end - start + 1);

    // Replace multiple spaces with a single space
    std::string normalized;
    bool inSpace = false;
    for (char c : text) {
        if (std::isspace(c)) {
            if (!inSpace) {
                normalized += ' ';
                inSpace = true;
            }
        } else {
            normalized += c;
            inSpace = false;
        }
    }
    text = normalized;
}

std::string Text::getText() const {
    return text;
}
