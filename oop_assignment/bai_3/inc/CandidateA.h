#ifndef CANDIDATE_A_H
#define CANDIDATE_A_H

#include "Candidate.h"

class CandidateA : public Candidate {
public:
    CandidateA(uint id, string name, string address, uint priority);
    string toString() const override;
};

#endif