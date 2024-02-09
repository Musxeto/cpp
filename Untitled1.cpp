#include <iostream>

using namespace std;
int searches = 0;
int BinarySearch(int A[], int n, int e) {
    int start = 0, end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
		searches++;
        if (e == A[mid]) {
            return mid;
        } else if (e > A[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n;
    cout << "Enter the size of the array:\n";
    cin >> n;

    int A[n], e, arr_index;

    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << "Enter the element to be found:\n";
    cin >> e;

    arr_index = BinarySearch(A, n, e);

    if (arr_index == -1)
        cout << "Element not found\n";
    else
        cout << "Found at index: " << arr_index << "\n";
	cout<<"Searches:"<<searches<<endl;
    return 0;
}

