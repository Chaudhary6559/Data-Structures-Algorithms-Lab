#include <iostream>
using namespace std;
int binarySearch(int arr[],int low,int high,int x) 
{
    if (high>=low) 
	{
        int mid=low+(high-low)/2;
        if(arr[mid]==x)
            return mid; 
        if(arr[mid]>x)
            return binarySearch(arr,low,mid-1,x); 
        return binarySearch(arr,mid+1,high,x);
    }
    return -1;
}

int main() 
{
    int arr[]={10,20,30,40,50,40,60,70,80,90,100,110,120,130,140}; 
    int x=130; 
    int n=sizeof(arr)/sizeof(arr[0]);
    int result=binarySearch(arr,0,n-1,x);
    if (result==-1)
        cout<<"Element is not present in the array";
    else
        cout<<"Element is present at index "<<result;
    return 0;
}
