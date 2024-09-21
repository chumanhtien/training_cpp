#include "../inc/ManagerOfficer.h"

ManagerOfficer::ManagerOfficer() : size(0), capacity(1) {
    officers = new Officer*[capacity];
}

ManagerOfficer::ManagerOfficer(uint capacity): size(0), capacity(capacity) {
    officers = new Officer*[capacity];
}

ManagerOfficer::~ManagerOfficer() {
    for(uint i = 0; i < size; i++) {
        delete officers[i];
    }
    delete[] officers;
}

// getter and setter
uint ManagerOfficer::getSize() const {
    return size;
}
void ManagerOfficer::setSize(uint size) {
    this->size = size;
}

uint ManagerOfficer::getCapacity() const {
    return capacity;
}
void ManagerOfficer::setCapacity(uint size) {
    this->capacity = capacity;
}

void ManagerOfficer::add(Officer* officer) {
    if (size == capacity) {
        resize();
    }
    officers[size++] = officer;
}

void ManagerOfficer::resize() {
    uint newCapacity = capacity < 1000 ? capacity<<1 : capacity + 20;
    Officer** newOfficers = new Officer*[newCapacity];
    
    // Sao chép các phần tử từ mảng cũ sang mảng mới
    for (uint i = 0; i < size; i++) {
        newOfficers[i] = officers[i];
    }

    // Giải phóng mảng cũ
    delete[] officers;

    // Cập nhật lại con trỏ officers và dung lượng mới
    officers = newOfficers;
    capacity = newCapacity;
}

std::pair<Officer**, uint> ManagerOfficer::searchByName(std::string name) {
    Officer** foundOfficers = new Officer*[size]; // Giả sử tất cả đều tìm thấy
        uint count = 0; // Đếm số lượng Officer tìm thấy

        for (uint i = 0; i < size; i++) {
            if (officers[i]->getFullName().find(name) != std::string::npos) {
                foundOfficers[count++] = officers[i]; // Thêm vào mảng tìm thấy
            }
        }

    return std::make_pair(foundOfficers, count); // Trả về mảng và số lượng tìm thấy
}

void ManagerOfficer::showListInfor() {
    for (uint i = 0; i < size; i++) {
        std::cout << officers[i]->toString() << '\n';
    }
}

