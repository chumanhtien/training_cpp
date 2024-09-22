#ifndef CANDIDATE_MANAGER_H
#define CANDIDATE_MANAGER_H
#include <unordered_map>
#include <memory>
#include "Candidate.h"

class CandidateManager {
private:
    std::unordered_map<uint, std::shared_ptr<Candidate>> candidateList;

public:
    void add(std::shared_ptr<Candidate> candidate);
    void showListCandidate() const;
    std::shared_ptr<Candidate> findCandidateWithId(uint id) const;
};
#endif