#include <iostream>
#include <functional>

using namespace std;

void printMessage() {
    cout << "Hello from callback!" << endl;
}

void executeCallback(void (*callback)()) {
    callback();
}

void executeCallback2(const function<void()> &callback) {
    callback();
}

class MyFunctor {
public:
    void operator()() const {
        std::cout << "Hello from functor callback!" << std::endl;
    }
};

void executeCallback3(const MyFunctor &callback) {
    callback();
}

int main() {
    // Callback with function pointer
    executeCallback(printMessage);

    // Callback with lambda function
    executeCallback2([]() {
        cout << "Hello from lambda callback!" << endl;
    });

    // Callback with functor
    MyFunctor functor;
    executeCallback3(functor);

    return 0;
}
