#include "../inc/Town.h"
#include <iostream>

Town::Town() : familyCount(0), capacity(2) {
    families = new std::unique_ptr<Family>[capacity];
}

Town::~Town() {
    delete[] families;
    std::cout << "Town destructor is called\n";
}

void Town::resize() {
    capacity  = capacity < 50 ? (capacity<<1) : (capacity + 10);
    auto newFamilies = new std::unique_ptr<Family>[capacity];
    for (uint i = 0; i < familyCount; ++i) {
        newFamilies[i] = std::move(families[i]);
    }
    delete[] families;
    families = newFamilies;
}

void Town::addFamily(std::unique_ptr<Family> family) {
    if (familyCount >= capacity) {
        resize();
    }
    families[familyCount++] = std::move(family);
}

void Town::displayFamilies() const {
    for (uint i = 0; i < familyCount; ++i) {
        std::cout << families[i]->toString() << std::endl;
    }
}
