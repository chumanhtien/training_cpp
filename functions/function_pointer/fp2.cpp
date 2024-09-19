
#include<iostream>
using namespace std;

void swapValue(int &value1, int &value2) {
    int temp = value1;
    value1 = value2;
    value2 = temp;
}

bool ascending(int left, int right) {
    return left > right;
}

bool descending(int left, int right) {
    return left < right;
}

void selectionSort(int *arr, int length, bool (*compareFunc)(int, int)) {
    for(int i = 0; i < length; i++) {
        int minIndex = i;
        for(int j = i + 1; j < length; j++) {
            if (compareFunc(arr[minIndex], arr[j])) {
                minIndex = j;
            }
        }
        swapValue(arr[i], arr[minIndex]);
    }
}

void printArray(int *arr, int length) {
    for(int i = 0; i < length; i++) {
        cout << arr[i] << ", ";
    }
    cout << '\n';
}

int main() {
    int arr[] = {1, 4, 2, 3, 6, 5, 7, 9, 8};
    int length = sizeof(arr) / sizeof(int);
    cout << "Before sort: ";
    printArray(arr, length);
    
    selectionSort(arr, length, ascending);
    cout << "After ascending sorted: ";
    printArray(arr, length);

    selectionSort(arr, length, descending);
    cout << "After descending sorted: ";
    printArray(arr, length);
    return 0;
}
