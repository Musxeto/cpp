#include <iostream>
using namespace std;

int comparison = 0;

void BubbleSort(int A[], int n) {
    int flag, k, i, temp;

    for (k = 1; k < n; k++) {
        flag = 0;
        for (i = 0; i < n - k; i++) {
            if (A[i] > A[i + 1]) {
                temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
                flag = 1;
                comparison++;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}

void displayArray(int A[], int n) {
    cout << "{ ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << ",";
    }
    cout << "\b }";
}

int main() {
    int n = 8;
    int array[n] = {9,8,7,6,5,4,3,2};

    BubbleSort(array, n);
    displayArray(array, n);
    
    cout << "\n Comparisons: " << comparison;
    return 0;
}

