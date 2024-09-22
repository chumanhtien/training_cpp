
#include "../inc/Family.h"
#include <memory>

Family::Family(uint memberCount, uint houseNumber)
    : memberCount(0), houseNumber(houseNumber), capacity(4) {
    members = new std::unique_ptr<Person>[capacity]; // Khởi tạo mảng với sức chứa ban đầu
}

Family::~Family() {
    delete[] members;
}

uint Family::getHouseNumber() const {
    return houseNumber;
}

uint Family::getMemberCount() const {
    return memberCount;
}

void Family::setHouseNumber(uint houseNumber) {
    this->houseNumber = houseNumber;
}

void Family::setMemberCount(uint memberCount) {
    this->memberCount = memberCount;
}

void Family::resize() {
    uint newCapacity = capacity < 50 ? (capacity<<1) : (capacity + 10);
    std::unique_ptr<Person>* newMembers = new std::unique_ptr<Person>[newCapacity];

    for (uint i = 0; i < memberCount; ++i) {
        newMembers[i] = std::move(members[i]);
    }

    delete[] members;
    members = newMembers;
    capacity = newCapacity;
}

void Family::addMember(std::unique_ptr<Person> person) {
    if (memberCount >= capacity) {
        resize(); // Mở rộng mảng nếu cần
    }
    members[memberCount++] = std::move(person); // Thêm thành viên mới
}

std::string Family::toString() const {
    std::string str;
    str += "House Number: " + std::to_string(houseNumber) + "\nMembers:\n";
    for (uint i = 0; i < memberCount; ++i) {
        str += members[i]->toString() + "\n"; 
    }
    return str;
}
