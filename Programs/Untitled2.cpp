#include <iostream>
using namespace std;
int main() {

int arr[] = {1, 3,5,7,9, 11};

int *pl = arr;

int *p2 = &arr[4];


cout << *(p2--) - *(++pl) << endl;

cout << (*pl)++ + *(--p2) << endl;

cout << *(++pl) - *(--p2) << endl;
return 0; }
