#ifndef MY_MANAGEROFFICER
#define MY_MANAGEROFFICER
#include "Officer.h"

class ManagerOfficer {
    private:
        Officer** officers;
        uint size;
        uint capacity;
    public:
        ManagerOfficer();
        ManagerOfficer(uint capacity);

        ~ManagerOfficer();

        // getter and setter
        uint getSize() const;
        void setSize(uint size);

        uint getCapacity() const;
        void setCapacity(uint capacity);

        void add(Officer* officer);
        void resize();
        Officer** searchByName(std::string name);
        void showListInfor();
};
#endif