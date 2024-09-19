#ifndef WORKER_H
#define WORKER_H
#include <iostream>
#include <string>
#include "Officer.h"

typedef unsigned uint;
class Worker : public Officer {
    private:
        uint rank;
    
    public:
        // Constructor
        Worker();
        Worker(std::string fullName, uint age, std::string sex, std::string address, uint rank);

        // Destructor
        ~Worker();
};

#endif