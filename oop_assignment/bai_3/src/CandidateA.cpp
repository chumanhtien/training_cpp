#include "../inc/CandidateA.h"

CandidateA::CandidateA(uint id, string name, string address, uint priority) : 
    Candidate(id, name, address, priority) {}

string CandidateA::toString() const {
    return "CandidateA {id = " + 
            std::to_string(id) + 
            ", name = " + name + 
            ", address = " + address + 
            ", priority = "  + std::to_string(priority) + 
            ", Subject: Toan - Ly - Hoa}";
}
