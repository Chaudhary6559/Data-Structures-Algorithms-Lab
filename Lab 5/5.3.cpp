#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
void selectionSort(int arr[],int n) 
{
    for (int i=0;i<n-1;++i) 
	{
        int minIndex=i;
        for (int j=i+1;j<n;++j) 
		{
            if (arr[j]<arr[minIndex]) 
			{
                minIndex=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;
    }
}
void printArray(int arr[],int size) 
{
    for (int i=0;i<size;i++)
        cout<<arr[i]<<" ";
        cout<<endl;
}
int main() 
{
    int smallArray[]={49,77,78,32,46,20,9};
    int smallArraySize=sizeof(smallArray)/sizeof(smallArray[0]);
    cout<<"Original small array: ";
    printArray(smallArray,smallArraySize);
    selectionSort(smallArray,smallArraySize);

    cout<<"Sorted small array: ";
    printArray(smallArray,smallArraySize);
    int sizes[]={100,500,1000,5000,10000}; 
    for (int size:sizes) 
	{
        int* arr=new int[size];
        for (int i=0;i<size;++i) 
		{
            arr[i]=rand()%1000;
        }
        auto start=chrono::high_resolution_clock::now();
        selectionSort(arr,size);
        auto end=chrono::high_resolution_clock::now();
        cout<<"Time taken for size "<<size<<": " 
        <<chrono::duration_cast<chrono::milliseconds>(end-start).count()<<" ms"<<endl;
        delete[] arr;
    }
    return 0;
}
