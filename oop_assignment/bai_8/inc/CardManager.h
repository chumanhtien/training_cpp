#ifndef CARDMANAGER_H
#define CARDMANAGER_H

#include <unordered_map>
#include <memory>
#include "Card.h"

class CardManager {
private:
    std::unordered_map<uint, std::unique_ptr<Card>> borrowCards;

public:
    void addBorrowCard(std::unique_ptr<Card> card);
    void removeBorrowCard(uint cardId);
    void displayAllBorrowCards() const;
};

#endif // CARDMANAGER_H
