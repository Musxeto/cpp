#include<iostream>
#include<algorithm>
using namespace std;

void InsertionSort(int n, int array[]) {
    int key, j;
    for(int i = 1; i <= n-1; i++) {
        key = array[i];
        j = i - 1;

        while(j >= 0 && array[j] > key) {
            array[j + 1] = array[j]; 
            j--;
        }
        array[j + 1] = key;
    }
}
void SelectionSort(int n, int array[]) {
	int j, min;
	for(int i=0;i<n;i++){
		min = i;
		for(j=i+1;j<n;j++){
			if(array[min]>array[j]){
				min = j;
			}
		}
		swap(array[min] , array[i]);
	}
}
void BubbleSort(int n, int array[]) {
    int unsorted = n;
    while (unsorted > 0) {
        for (int i = 0; i < unsorted - 1; i++) {
            if (array[i] > array[i + 1]) {
                swap(array[i], array[i + 1]);
            }
        }
        unsorted--;
    }
}


void display(int n , int array[]) {
    cout << "{ ";
    for(int i = 0; i < n; i++) {
        cout << array[i] << " , ";
    }
    cout << "\b\b}" << endl;
}

int main() {
    int n = 6;
    int array[] = {55, 0, -34, 34, 77, 1};

    cout << "Before Sorting: " << endl;
    display(n, array);
	
	cout << "After Insertion Sort: " << endl;
    InsertionSort(n, array);
    display(n, array);
    
    cout << "After Bubbly Sort: " << endl;
    BubbleSort(n, array);
    display(n, array);

    return 0;
}

