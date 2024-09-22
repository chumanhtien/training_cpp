#ifndef CANDIDATE_C_H
#define CANDIDATE_C_H

#include "Candidate.h"

class CandidateC : public Candidate {
public:
    CandidateC(uint id, string name, string address, uint priority);
    string toString() const override;
};

#endif