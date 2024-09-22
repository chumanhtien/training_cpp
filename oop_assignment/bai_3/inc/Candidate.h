#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <string>
#include <iostream>
using namespace std;
typedef unsigned int uint;

class Candidate {
protected:
    uint id;
    string name;
    string address;
    uint priority;

public: 
    Candidate();
    Candidate(uint id, string name, string address, uint priority);

    virtual ~Candidate();

    // getter & setter
    uint getId() const;
    void setId(uint id);

    string getName() const;
    void setName(string name);

    string getAddress() const;
    void setAddress(string address);

    uint getPriority() const;
    void setPriority(uint priority);

    virtual string toString() const = 0;
};

#endif