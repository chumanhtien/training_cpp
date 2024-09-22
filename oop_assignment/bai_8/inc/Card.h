#ifndef CARD_H
#define CARD_H

#include <string>
#include "Student.h"

class Card {
private:
    uint cardId;
    uint borrowDate;
    uint returnDate;
    std::string bookId;
    Student student;

public:
    Card(uint cardId, uint borrowDate, uint returnDate, const std::string& bookId, const Student& student);

    // Getters
    uint getCardId() const;
    uint getBorrowDate() const;
    uint getReturnDate() const;
    std::string getBookId() const;
    Student getStudent() const;

    std::string getInfo() const;
};

#endif // CARD_H
