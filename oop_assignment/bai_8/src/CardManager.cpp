#include "../inc/CardManager.h"
#include <iostream>
#include <chrono>
#include <iomanip>
#include <ctime>

uint convertDateToInt(uint day, uint month, uint year) {
    return year * 10000 + month * 100 + day;
}

void CardManager::addBorrowCard(std::unique_ptr<Card> card) {
    uint cardID = card->getCardId();
    // Kiểm tra nếu CardID đã tồn tại và ngày trả lớn hơn ngày hiện tại
    // Lấy thời gian hiện tại
    auto now = std::chrono::system_clock::now();
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
    std::tm* now_tm = std::localtime(&now_time_t);

    // Lấy ngày, tháng, năm
    uint day = now_tm->tm_mday;
    uint month = now_tm->tm_mon + 1; // Tháng bắt đầu từ 0
    uint year = now_tm->tm_year + 1900; // Năm bắt đầu từ 1900

    // Chuyển đổi sang định dạng YYYYMMDD
    uint currentDate = convertDateToInt(day, month, year);

    auto it = borrowCards.find((uint) cardID);
    if (it != borrowCards.end()) {
        // Nếu tồn tại, lấy thông tin về ngày trả
        if (it->second->getReturnDate() > currentDate) {
            std::cout << "Error: Card ID " << cardID << " already exists and is not expired.\n";
            return;
        }
    }
    borrowCards[cardID] = std::move(card);
}

void CardManager::removeBorrowCard(uint cardId) {
    borrowCards.erase(cardId);
}

void CardManager::displayAllBorrowCards() const {
    for (const auto& pair : borrowCards) {
        std::cout << pair.second->getInfo();
        std::cout << "---------------------\n";
    }
}
