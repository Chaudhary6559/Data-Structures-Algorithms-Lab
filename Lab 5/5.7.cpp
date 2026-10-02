#include <iostream>
#include <vector>
using namespace std;
void hybridSort(vector<int>&arr) 
{
    int n=arr.size();
    for(int i=0;i<n/2;++i) 
	{
        for(int j=0;j<n/2-i-1;++j) 
		{
            if(arr[j]>arr[j+1]) 
			{
                swap(arr[j],arr[j+1]);
            }
        }
    }
    for(int i=n/2;i<n-1;++i) 
	{
        int min_index=i;
        for(int j=i+1;j<n;++j) 
		{
            if(arr[j]<arr[min_index]) 
			{
                min_index=j;
            }
        }
        swap(arr[i],arr[min_index]);
    }
}
int main() 
{
    vector<int>myVector={64,87,34,98,56,90,100,99,94,34,44,49,67,74,50,52,66};
    hybridSort(myVector);
    cout<<"Sorted Vector: ";
    for(int num:myVector) 
	{
        cout<<num<< " ";
    }
    cout<<endl;
    return 0;
}
