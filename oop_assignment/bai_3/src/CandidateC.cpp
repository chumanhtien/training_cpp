#include "../inc/CandidateC.h"

CandidateC::CandidateC(uint id, string name, string address, uint priority) : 
    Candidate(id, name, address, priority) {}

string CandidateC::toString() const {
    return "CandidateC {id = " + 
            std::to_string(id) + 
            ", name = " + name + 
            ", address = " + address + 
            ", priority = "  + std::to_string(priority) + 
            ", Subject: Van - Su - Dia}";
}
