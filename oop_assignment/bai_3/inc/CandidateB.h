#ifndef CANDIDATE_B_H
#define CANDIDATE_B_H

#include "Candidate.h"

class CandidateB : public Candidate {
public:
    CandidateB(uint id, string name, string address, uint priority);
    string toString() const override;
};

#endif