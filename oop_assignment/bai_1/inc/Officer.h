#ifndef OFFICER_H
#define OFFICER_H
#include <iostream>
#include <string>

typedef unsigned uint;
class Officer {
    protected:
        std::string fullName; 
        uint age;
        std::string gender;
        std::string address;
    
    public:
        // Constructor
        Officer();
        Officer(std::string fullName, uint age, std::string gender, std::string address);

        // Destructor
        virtual ~Officer();

        // getters and setters
        std::string getFullName() const;
        void setFullName(std::string fullName);

        uint getAge() const;
        void setAge(uint age);

        std::string getGender() const;
        void setGender(std::string gender);

        std::string getAddress() const;
        void setAddress(std::string address);

        virtual std::string toString() const;
};
#endif