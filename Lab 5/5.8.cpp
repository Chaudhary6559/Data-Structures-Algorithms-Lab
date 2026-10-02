#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>   
using namespace std;
void selectionSort(vector<int>&arr) 
{
    int n=arr.size();
    for(int i=0;i<n-1;++i) 
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
    srand(time(0));
    vector<int>myVector;
    const int size=10;
    for(int i=0;i<size;++i) 
	{
        myVector.push_back(rand()%100);
    }
    cout<<"Original List: ";
    for(int num:myVector) 
	{
        cout<<num<<" ";
    }
    cout<<endl;
    selectionSort(myVector);
    cout<<"Sorted List: ";
    for (int num:myVector) 
	{
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}
