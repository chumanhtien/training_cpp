#ifndef ENGINEER_H
#define ENGINEER_H
#include <iostream>
#include <string>
#include "Officer.h"

class Engineer : public Officer {
    private:
        std::string major;
    
    public:
        // Constructor
        Engineer();
        Engineer(std::string fullName, uint age, uint gender, std::string address, std::string major);

        // Destructor
        ~Engineer();

        // getters & setters
        std::string getMajor() const;
        void setMajor(std::string major);

        std::string toString() const override;

};

#endif