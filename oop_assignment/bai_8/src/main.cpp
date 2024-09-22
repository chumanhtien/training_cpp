#include <iostream>
#include <memory>
#include "../inc/CardManager.h" 

int main() {
    CardManager cardManager;

    // Tạo một số sinh viên
    Student student1("Chu Manh Tien", 20, "CNTT");
    Student student2("Nguyen Van B", 21, "KTMT");

    // Tạo một số thẻ mượn sách
    std::unique_ptr<Card> card1 = std::make_unique<Card>(1, 20240901, 20240915, "BK001", student1);
    std::unique_ptr<Card> card2 = std::make_unique<Card>(2, 20240902, 20240920, "BK002", student2);
    
    // Thêm thẻ mượn vào quản lý
    cardManager.addBorrowCard(std::move(card1));
    cardManager.addBorrowCard(std::move(card2));

    // Hiển thị thông tin tất cả thẻ mượn
    std::cout << "All Borrow Cards:\n";
    cardManager.displayAllBorrowCards();

    // Thử thêm thẻ với cùng CardID
    auto card3 = std::make_unique<Card>(2, 20240903, 20240926, "BK003", student1);
    cardManager.addBorrowCard(std::move(card3)); // sẽ thông báo lỗi nếu thẻ đã tồn tại và chưa hết hạn

    // Hiển thị lại thông tin thẻ mượn
    cardManager.displayAllBorrowCards();

    // Xóa một thẻ mượn
    cardManager.removeBorrowCard((uint) 1);
    std::cout << "After Removing Card ID 1:\n";
    cardManager.displayAllBorrowCards();

    return 0;
}
