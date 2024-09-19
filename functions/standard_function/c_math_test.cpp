#include<iostream>
#include<cmath>
#include<ctime>

using namespace std;

// user defined function
double power (double base, int exp) {
    double result = 1.0;
    
    if (exp == 0) {
        if (base == 0) {
            return 1;
        }
        return result;
    }

    if (exp > 0) {
        for (int i = 0; i < exp; i++) {
            result *= base;
        }
    } else {
        for (int i = exp; i < 0; i++) {
            result /= base;
        }
    }
    return result;
}



int main () {
    double base = 2.0;
    int exp = 10;
    const int ITERATIONS = 10000000;
    // NOTE: tu 100M vong lap => Tu viet tay nhanh hon
    double result1 = 0;
    double result2 = 0;

    clock_t start_time = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        result1 = power(base, exp);
    }
    clock_t end_time = clock();
    double custom_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

    start_time = clock();
    for (int i = 0; i < ITERATIONS; ++i) {
        double result = pow(base, exp);
    }
    end_time = clock();
    double cmath_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

    // In ra kết quả so sánh thời gian
    cout << "Time taken by custom power function: " << custom_time << " seconds" << endl;
    cout << "Time taken by cmath pow function: " << cmath_time << " seconds" << endl;
    return 0;
}