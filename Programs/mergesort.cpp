#include<iostream>
using namespace std;

void merge(int a[], int lb, int mid, int ub) {
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int b[ub - lb + 1];

    while (i <= mid && j <= ub) {
        if (a[i] <= a[j]) {
            b[k - lb] = a[i];
            i++;
        } else {
            b[k - lb] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        b[k - lb] = a[i];
        i++;
        k++;
    }

    while (j <= ub) {
        b[k - lb] = a[j];
        j++;
        k++;
    }

    for (int x = lb; x <= ub; x++) {
        a[x] = b[x - lb];
    }
}

void mergeSort(int A[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        mergeSort(A, lb, mid);
        mergeSort(A, mid + 1, ub);
        merge(A, lb, mid, ub);
    }
}
//void merge(int arr[],int lb,int mid,int ub)
//{
//	int i=lb;
//	int j=mid+1;
//	int k=lb;
//	int b[lb+ub];
//	
//	while(i<=mid&&j<=ub)
//	{
//		if(arr[i]<=arr[j])
//		{
//			b[k]=arr[i];
//			i++;
//		}
//		else
//		{
//			b[k]=arr[j];
//			j++;
//		}
//		k++;
//	}
//	if (i>=lb)
//	{
//		while(j<=ub)
//		{
//			b[k]=arr[j];
//			j++;k++;
//		}
//	}
//	if(j>=ub)
//	{
//		while(i<=mid)
//		{
//			b[k]=arr[i];
//			i++;k++;
//		}
//	}
//}

int main() {
    int arr[] = {0, 9, 4, 35, 36, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int lb = 0;
    int ub = size - 1;

    mergeSort(arr, lb, ub);

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    return 0;
}

