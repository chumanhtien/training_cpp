#ifndef WORKER_H
#define WORKER_H
#include <iostream>
#include <string>
#include "Officer.h"

class Worker : public Officer {
    private:
        uint level;
    
    public:
        // Constructor
        Worker();
        Worker(std::string fullName, uint age, std::string gender, std::string address, uint level);

        // Destructor
        ~Worker();

        // getter and setter
        uint getLevel() const;
        void setLevel(uint level);

        std::string toString() const override;
};

#endif