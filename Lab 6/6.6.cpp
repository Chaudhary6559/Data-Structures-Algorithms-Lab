#include <iostream>
#include <ctime>
using namespace std;
int partition(int arr[],int low,int high) 
{
    int pivot=arr[high];  
    int i=low-1;      
    for(int j=low;j<high;j++) 
	{
        if(arr[j]<=pivot) 
		{
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;  
}
void quickSort(int arr[],int low,int high) 
{
    if(low<high) 
	{
        int pivotIndex=partition(arr,low,high);
        quickSort(arr,low,pivotIndex-1);
        quickSort(arr,pivotIndex+1,high);
    }
}

int main() 
{
    int arr[]={79,32,75,21,99,63,67,24,87,78,90,71,77,100};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<"Original array: ";
    for(int i=0;i<size;i++) 
	{
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    clock_t startTime=clock();
    quickSort(arr,0,size-1);
    clock_t endTime=clock();
    cout<<"Sorted array: ";
    for(int i=0;i<size;i++) 
	{
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    double elapsedTime=double(endTime-startTime)/CLOCKS_PER_SEC;
    cout<<"Execution Time: "<<elapsedTime<<" seconds"<<endl;
    return 0;
}