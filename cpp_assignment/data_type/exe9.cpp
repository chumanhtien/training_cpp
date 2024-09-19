#include <iostream>
using namespace std;
int main () {
    float      x = 2.17f;
    double   y = 2.17;
    long double z = 2.17;
    printf("%f %lf %Lf \n",x,y,z);
    printf("%f %f %f \n",x,y,z);
    printf("%f %ff %fff \n",x,y,z); 
    printf("%f %lf %llf",x,y,z);
    return 0;
}