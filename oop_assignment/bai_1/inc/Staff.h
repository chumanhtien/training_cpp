#ifndef STAFF_H
#define STAFF_H
#include <iostream>
#include <string>
#include "Officer.h"
class Staff : public Officer {
    private:
        std::string task;
    
    public:
        // Constructor
        Staff();
        Staff(std::string fullName, uint age, uint gender, std::string address, std::string task);

        // Destructor
        ~Staff();

        // getter and setter
        std::string getTask() const;
        void setTask(std::string task);

        std::string toString() const override;
};

#endif