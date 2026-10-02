#include <iostream>
using namespace std;
int binarySearch(int arr[], int left, int right, int target) 
{
    if (right>=left) 
	{
        int mid=left+(right-left)/2;
        if (arr[mid]==target)
            return mid;
        if (arr[mid]>target)
            return binarySearch(arr,left,mid - 1,target);
        return binarySearch(arr,mid+1,right,target);
    }
    return -1;
}
int main() 
{
    int n;
    cout<<"Enter the number of elements in the sorted array: ";
    cin>>n;
    int array[n];
    for (int i = 0; i < n; i++) {
        cout<<"Enter element "<<i<<": ";
       cin>>array[i];
    }

    int target;
    cout<<"Enter the element to search for: ";
    cin>>target;

    int result=binarySearch(array,0,n-1,target);

    if (result!=-1)
        cout<<"Element found at index "<<result<<endl;
    else
        cout<<"Element not found in the array."<<endl;

    return 0;
}
