#include<iostream>
using namespace std;

void display(int n , char array[]){
	cout<<"Array: ";
	for(int i=0 ; i<n; i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
}
void InsertionSort(int n, char array[]) {
    int key, j;
    display(n,array);
    for(int i = 1; i <= n-1; i++) {
        key = array[i];
        j = i - 1;

        while(j >= 0 && array[j] > key) {
            array[j + 1] = array[j]; 
            j--;
        }
        array[j + 1] = key;
        display(n,array);
    }
}


int main(){
	int n = 8;
	char Array[n] = { 'E', 'X', 'A', 'M' ,'P', 'L' ,'E'};
	display(n , Array);
	cout<<"After Sorting: "<<endl;
	InsertionSort(n, Array);
	display(n , Array);
	return 0;
}
