#include<iostream>
using namespace std;

int partition(int A[],int lb, int ub){
	Pivot = A[lb];
	start = lb;
	end = lb;
	
	while(start < end){
		while(A[start] <= Pivot){
			start++;
		}
		while(A[end] > Pivot){
			end--;
		}
		
		if(start < end){
			swap(A[start] , A[end])
		}
	}
	swap(A[lb] , A[end])
	return end;
}

int QuickSort(A[], lb, ub){
	if(lb<ub){
		int Part = Partition(A,lb,ub);
		QuickSort(A,lb,Part-1);
		QuickSort(A,Part+1,ub);
	}
}
int main(){
	
}
