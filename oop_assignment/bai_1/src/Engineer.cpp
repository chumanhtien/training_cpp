#include "../inc/Engineer.h"

Engineer::Engineer() : 
    Officer(), major("MAJOR NULL") {}
Engineer::Engineer(std::string fullName, uint age, uint gender, std::string address, std::string major) :
    Officer(fullName, age, gender, address), major(major) {}

Engineer::~Engineer() {
    std::cout<<"Engineer destructor is called\n";
}

std::string Engineer::getMajor() const {
    return major;
}

void Engineer::setMajor(std::string major) {
    this->major = major;
}

std::string Engineer::toString() const {
    return Officer::toString() +  ", Major: " + major;
}