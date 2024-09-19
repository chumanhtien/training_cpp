#ifndef OFFICER_H
#define OFFICER_H
#include <iostream>
#include <string>

typedef unsigned uint;
class Officer {
    private:
        std::string fullName; 
        uint age;
        std::string gender;
        std::string address;
    
    public:
        // Constructor
        Officer();
        Officer(std::string fullName, uint age, std::string gender, std::string address);

        // Destructor
        ~Officer();

        // getters and setters
        std::string getFullName() {
            return fullName;
        }
        void setFullName(std::string name) {
            this->fullName = name;
        }
        uint getAge() {
            return age;
        }
        void setAge(uint age) {
            this->age = age;
        }
        std::string getGender() {
            return gender;
        }
        void setGender(std::string gender) {
            this->gender = gender;
        }
        std::string getAddress() {
            return address;
        }
        void setAddress(std::string address) {
            this->address = address;
        }
};

#endif