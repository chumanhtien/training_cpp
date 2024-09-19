#include <iostream>

// move constructoe
class MyClass {
    public:
        MyClass(MyClass&& other) noexcept {
            // Chuyển tài nguyên từ 'other' sang đối tượng mới
            data = other.data;
            other.data = nullptr; // 'other' không còn sở hữu tài nguyên
        }
    private:
        int* data;
};

void func() {
    std::cout<<"ASDS";
}
void func2() {
    std::cout<<"ASDS";
}
int main()
{
    
    int *p;
    *p = 1000;
    void (*f)() = &func2;
    std::cout<<f<<'\n'<<*f << '\n';
    std::cout<<p<<'\n'<<*p;

    return 0;    
}
