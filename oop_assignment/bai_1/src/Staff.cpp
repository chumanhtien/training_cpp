#include "../inc/Staff.h"

Staff::Staff() : 
    Officer(), task("TASK NULL") {}
Staff::Staff(std::string fullName, uint age, uint gender, std::string address, std::string task) : 
    Officer(fullName, age, gender, address), task(task) {}

Staff::~Staff() {
    std::cout<<"Staff destructor is called\n";
}

std::string Staff::getTask() const {
    return task;
}

void Staff::setTask(std::string task) {
    this->task = task;
}

std::string Staff::toString() const {
    return Officer::toString() + ", Task: " + task;
}