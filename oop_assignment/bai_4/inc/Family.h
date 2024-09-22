#ifndef FAMILY_H
#define FAMILY_H
#include <memory>
#include "Person.h"

class Family {
private:
    std::unique_ptr<Person>* members;
    uint memberCount;
    uint capacity;
    uint houseNumber;

    void resize();

public:
    Family(uint memberCount, uint houseNumber);
    ~Family();

    // Getters
    uint getMemberCount() const; // Getter cho số thành viên
    uint getHouseNumber() const; // Getter cho số thành viên

    // Setters 
    void setMemberCount(uint memberCount);
    void setHouseNumber(uint houseNumber);


    void addMember(std::unique_ptr<Person> person);
    std::string toString() const;

};
#endif