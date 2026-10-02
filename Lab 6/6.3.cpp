#include <iostream>
#include <ctime>
using namespace std;
void merge(int arr[],int left[],int leftSize,int right[],int rightSize) 
{
    int i=0,j=0,k=0;
    while(i<leftSize&&j<rightSize) 
	{
        if(left[i]<=right[j]) 
		{
            arr[k]=left[i];
            i++;
        } else 
		{
            arr[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<leftSize) 
	{
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<rightSize) 
	{
        arr[k]=right[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[],int size) 
{
    if(size<=1)
        return;
    int mid=size/2;
    int left[mid];
    int right[size-mid];
    for(int i=0;i<mid;i++)
        left[i]=arr[i];
    for(int i=mid;i<size;i++)
        right[i-mid]=arr[i];
    mergeSort(left,mid);
    mergeSort(right,size-mid);
    merge(arr,left,mid,right,size-mid);
}
int main() 
{
    int arr[12] = {76,62,75,91,99,33,89,77,45,67,90,43};
    int size=12;
    cout<<"Original array: ";
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    clock_t startTime=clock();
    mergeSort(arr, size);
    clock_t endTime=clock();
    cout<<"Sorted array: ";
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    double elapsedTime=double(endTime-startTime)/CLOCKS_PER_SEC;
    cout<<"Execution Time: "<<elapsedTime<<" seconds"<<endl;
    return 0;
}