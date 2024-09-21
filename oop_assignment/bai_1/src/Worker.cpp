#include "../inc/Worker.h"

Worker::Worker() : 
    Officer(), level(0) {}
Worker::Worker(std::string fullName, uint age, uint gender, std::string address, uint level) : 
    Officer(fullName, age, gender, address), level(level) {}

Worker::~Worker() {
    std::cout << "Worker destructor is called\n";
}

// getter and setter
uint Worker::getLevel() const {
    return level;
}

void Worker::setLevel(uint level) {
    this->level = level;
}

std::string Worker::toString() const {
    return Officer::toString() +  ", Level: " + std::to_string(level);
}
