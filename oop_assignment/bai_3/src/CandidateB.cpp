#include "../inc/CandidateB.h"

CandidateB::CandidateB(uint id, string name, string address, uint priority) : 
    Candidate(id, name, address, priority) {}

string CandidateB::toString() const {
    return "CandidateA {id = " + 
            std::to_string(id) + 
            ", name = " + name + 
            ", address = " + address + 
            ", priority = "  + std::to_string(priority) + 
            ", Subject: Toan - Hoa - Sinh}";
}
