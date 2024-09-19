#include <iostream>
using namespace std;

int main () {
    void *vptr, v;
    v = 0;
    vptr = &v;
    printf("%v", *vptr);
    getchar();
    return 0;
}