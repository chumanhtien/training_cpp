#include "../inc/Card.h"

// Constructor
Card::Card(uint cardId, uint borrowDate, uint returnDate, const std::string& bookId, const Student& student)
    : cardId(cardId), borrowDate(borrowDate), returnDate(returnDate), bookId(bookId), student(student) {}

// Getters
uint Card::getCardId() const {
    return cardId;
}

uint Card::getBorrowDate() const {
    return borrowDate;
}

uint Card::getReturnDate() const {
    return returnDate;
}

std::string Card::getBookId() const {
    return bookId;
}

Student Card::getStudent() const {
    return student;
}

std::string Card::getInfo() const {
    std::string str;
    str += "Card ID: " + std::to_string(cardId) + "\n";
    str += "Borrow Date: " + std::to_string(borrowDate) + "\n";
    str += "Return Date: " + std::to_string(returnDate) + "\n";
    str += "Book ID: " + bookId + "\n";
    str += "Student Name: " + student.getName() + "\n";
    str += "Age: " + std::to_string(student.getAge()) + "\n";
    str += "Class: " + student.getClassName() + "\n";
    return str;
}
