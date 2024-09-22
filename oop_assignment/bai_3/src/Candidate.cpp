#include "../inc/Candidate.h"

Candidate::Candidate(uint id, string name, string address, uint priority) :
    id(id), name(name), address(address), priority(priority) {}

Candidate::~Candidate() {}

uint Candidate::getId() const {
    return id;
}

void Candidate::setId(uint id) {
    this->id = id;
}

string Candidate::getName() const {
    return name;
}

void Candidate::setName(string name) {
    this->name = name;
}

string Candidate::getAddress() const {
    return address;
}

void Candidate::setAddress(string address) {
    this->address = address;
}

uint Candidate::getPriority() const {
    return priority;
}

void Candidate::setPriority(uint priority) {
    this->priority = priority;
} 
