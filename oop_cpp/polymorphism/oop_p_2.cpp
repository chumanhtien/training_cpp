#include <iostream>
class Animal {
public:
    // Khai báo hàm ảo
    virtual void sound() {
        std::cout << "Animal makes a sound." << std::endl;
    }
    void run() {
        std::cout << "Animal run\n";
    }
};

class Dog : public Animal {
public:
    void sound() const {
        std::cout << "Dog barks." << std::endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        std::cout << "Cat meows." << std::endl;
    }
};

int main() {
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();
    Animal animal3;

    animal1->sound();  // Output: Dog barks.
    animal2->sound();  // Output: Cat meows.
    animal3.sound();  // Output: Animal makes a sound.
    animal2->run();   // Output: Animal run

    delete animal1;
    delete animal2;
}
