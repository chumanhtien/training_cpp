#include <iostream>
using namespace std;

class Musician {
public: 
    virtual void play() {
        cout << "Play an instrument\n";
    }
};

class Guitarist : public Musician {
public:
    void play() override {
        cout << "Play a guitar\n";
    }
};

int main () {
    Musician armstrong;
    Guitarist steve; 
    Musician* m = &armstrong; 
    m->play(); 
    m = &steve; 
    m->play();
    
    return 0;
}