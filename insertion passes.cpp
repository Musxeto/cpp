#include<iostream>
#include<algorithm>
using namespace std;

int pass = 1;
void display(int n , int array[]) {
    cout << "{ ";
    for(int i = 0; i < n; i++) {
        cout << array[i] << " , ";
    }
    cout << "\b\b}" << endl;
}
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
        cout<<"Pass "<<pass<<": ";
        display(n,array);
        pass++;
    }
}




int main() {
    int n = 4;
    int array[] = {54,37,39,32};

    cout << "Before Sorting: " << endl;
    display(n, array);
	
	cout << "After Insertion Sort Passes: " << endl;
    InsertionSort(n, array);
    cout<<"FINAL Sorted Array for Ammad Gandu:"<<endl;
    display(n, array);


    return 0;
}

