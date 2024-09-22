#include "../inc/CandidateManager.h"
#include <iostream>

void CandidateManager::add(std::shared_ptr<Candidate> candidate) {
    uint id = candidate->getId();
    if (candidateList.find(id) != candidateList.end()) {
        std::cout << "Candidate ID is exist!\n";
        return;
    }
    candidateList[id] = candidate;
}

void CandidateManager::showListCandidate() const {
    for (const auto& item: candidateList) {
        std::cout << item.second->toString() << '\n';
    }
}

std::shared_ptr<Candidate> CandidateManager::findCandidateWithId(uint id) const {
    auto it = candidateList.find(id);
    if (it != candidateList.end()) {
        return it->second;
    } else {
        std::cout << "Can't find candidate with Id = : " << id << std::endl;
        return nullptr;
    }
}