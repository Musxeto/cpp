#include<iostream>
using namespace std;
int main()
{
	int arr[5][3]={ {3000, 4000,3500}, {2000, 2500, 1800},{3500, 3800, 4000},{2800, 3200, 2900},{3900, 4500, 4100}};
    int i,j,k,highest;
    for(int i=0;i<5;i++)
    {
		if(arr[i][0] >=arr[i][2]  && arr[i][0] >= arr[i][2])
           cout << "Departement " << i<<" Employee 1 : "<<arr[i][0]<<endl;

        else if (arr[i][1] >=arr[i][0]  && arr[i][1] >= arr[i][2])
           cout << "Departement " << i<<" Employee 2: "<<arr[i][1]<<endl;
    
        else 
          cout << "Departement: " << i<<" Employee 3: "<<arr[i][2]<<endl;
	}





 return 0;
}
