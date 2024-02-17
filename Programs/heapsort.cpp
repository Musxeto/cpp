#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void minHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void maxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

int main() {
    int size;
    cout << "Enter Size of Array: ";
    cin >> size;

    int myarray[size];
    cout << "Enter Elements of the Array: ";
    for (int i = 0; i < size; i++)
        cin >> myarray[i];


    heapSort(myarray, size);

    cout << "Sorted Array (Ascending Order): ";
    for (int i = 0; i < size; i++)
        cout << myarray[i] << " ";


    minHeap(myarray, size);

    cout << "\nMin Heap: ";
    for (int i = 0; i < size; i++)
        cout << myarray[i] << " ";

    maxHeap(myarray, size);

    cout << "\nMax Heap: ";
    for (int i = 0; i < size; i++)
        cout << myarray[i] << " ";

    return 0;
}

