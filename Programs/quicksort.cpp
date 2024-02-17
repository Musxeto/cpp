#include<iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int A[], int lb, int ub) {
    int Pivot = A[lb];
    int start = lb;
    int end = ub;

    while (start < end) {
        while (A[start] <= Pivot) {
            start++;
        }
        while (A[end] > Pivot) {
            end--;
        }

        if (start < end) {
            swap(A[start], A[end]);
        }
    }
    swap(A[lb], A[end]);
    return end;
}

void QuickSort(int A[], int lb, int ub) {
    if (lb < ub) {
        int Part = partition(A, lb, ub);
        QuickSort(A, lb, Part - 1);
        QuickSort(A, Part + 1, ub);
    }
}

int main() {
    int size = 0;
    cout << "Enter Size of Array: " << endl;
    cin >> size;
    int myarray[size];

    for (int i = 0; i < size; i++) {
        cout << "\nEnter Element at index " << i << " :";
        cin >> myarray[i];
    }
    QuickSort(myarray, 0, size - 1);

    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++) {
        cout << myarray[i] << " ";
    }

    return 0;
}

