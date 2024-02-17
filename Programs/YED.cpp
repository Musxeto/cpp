#include <iostream>
using namespace std;
int main()
{
    int array[7]={1,3,3,6,9,10,1};
    int i,j,k,n=7;
    
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(array[i]==array[j])
            {
                for(k=j;k<n;k++)
                {
                    array[k]=array[k+1];
                }
                n--;
                j--;
            }
            
        }
    }
    cout<<"AFTER REMOVAL OF DUPLICATION:";
    for(i=0;i<n;i++)
    {
        cout<<array[i]<<" ";
    }
    return 0;
}
