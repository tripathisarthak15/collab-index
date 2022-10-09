#include <iostream>
using namespace std;

class solution
{
    public:
    int top2(int arr[], int n)
    {
        int i,j,max=arr[i];
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n-1;j++)

            if(arr[i]<arr[j])
            max=arr[j];

        }

        
    }

}