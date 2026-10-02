#include <iostream>
using namespace std;
int binarySearch(int arr[],int left,int right,int target) 
{
    while (left<=right) 
	{
        int mid=left+(right-left)/2;
        if(arr[mid]==target)
            return mid;
        if(arr[mid]<target)
            left=mid+1;
        else
            right=mid-1;
    }
    return -1; 
}
int main() 
{
    int arr[]={10,20,30,11,16,24,100,50,80,21,33,60,65,71,90,99,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target;
    cout<<"Enter the element to search for: ";
    cin>>target;

    int result=binarySearch(arr,0,n-1,target);
    if (result!=-1)
        cout<<"Element found at index "<<result<<endl;
    else
        cout<<"Element not found in the array."<<endl;
    return 0;
}

