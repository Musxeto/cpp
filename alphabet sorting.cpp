#include<iostream>
using namespace std;


void InsertionSort(int n, char array[]) {
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
void display(int n , char array[]){
	cout<<"Array: ";
	for(int i=0 ; i<n; i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int n = 8;
	char Array[n] = { 'g','a','b','d','c','f','h','e'};
	display(n , Array);
	cout<<"After Sorting: "<<endl;
	InsertionSort(n, Array);
	display(n , Array);
	return 0;
}
