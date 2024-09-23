#ifndef TEXT_H
#define TEXT_H

#include <string>
#include <sstream>
#include <cctype>

class Text {
private:
    std::string text;

public:
    // Constructors
    Text();
    Text(const std::string& st);

    int countWords() const;

    // count 'A' characters (case insensitive)
    int countA() const;

    void normalize();

    std::string getText() const;
};

#endif // TEXT_H
