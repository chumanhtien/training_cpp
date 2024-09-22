#ifndef TOWN_H
#define TOWN_H

#include <memory>
#include <string>
#include "Family.h"

class Town {
private:
    std::unique_ptr<Family>* families;
    uint familyCount;
    uint capacity;

    void resize();

public:
    Town();
    ~Town();

    void addFamily(std::unique_ptr<Family> family);
    void displayFamilies() const;
};

#endif
