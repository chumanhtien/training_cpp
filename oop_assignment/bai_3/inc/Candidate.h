#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <string>
#include <iostream>
using namespace std;
typedef unsigned int uint;

class Candidate {
protected:
    string id;
    string name;
    string address;
    uint priotiry;

public: 
    Candidate();
    Candidate(string id, string name, string address, uint priority);

    virtual ~Candidate();

    // getter & setter
    string getId() const;
    void setId(string id);

    string getName() const;
    void setName(string name);

    string getAddress() const;
    void setAddress(string address);

    uint getPriority() const;
    void setPriority(uint priority);

    virtual string toString() const;
};
#endif