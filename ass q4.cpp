#include <iostream>
using namespace std;
int main() 
{

int arr[2][3] = {{1, 2, 3}, {4, 5, 6} };

int i, j, sum = 0;

for(i=0;i<=2; i++)
 {

for (j=0; j <=3; j++)
 {
sum += arr[i][j];
}

 }
cout << "The sum of all elements in the array is: " << sum << endl;

return 0; 
}

