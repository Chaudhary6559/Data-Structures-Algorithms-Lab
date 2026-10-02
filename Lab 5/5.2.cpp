#include <iostream>
#include <chrono>
#include <cstdlib> 
using namespace std;
void bubbleSort(int arr[],int n) 
{
    for (int i=0;i<n-1;++i) 
	{
        for (int j=0;j<n-i-1;++j) 
		{
            if (arr[j]>arr[j+1]) 
			{
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void Sortedarray(int arr[], int size) 
{
    for (int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main() 
{
    int smallArray[]={64,34,25,12,22,11,90};
    int smallArraySize=sizeof(smallArray)/sizeof(smallArray[0]);
    cout<<"Original small array: ";
    Sortedarray(smallArray,smallArraySize);
    bubbleSort(smallArray,smallArraySize);
    cout<<"Sorted small array: ";
    Sortedarray(smallArray,smallArraySize);
    int sizes[]={100,500,1000,5000,10000}; 
    for (int size:sizes)
	{
        int* arr=new int[size];
        for(int i=0;i<size;++i) 
		{
            arr[i]=rand()%1000;
        }
        auto start=chrono::high_resolution_clock::now();
        bubbleSort(arr, size);
        auto end=chrono::high_resolution_clock::now();
        cout<<"Time taken for size "<<size<<": " 
                  <<chrono::duration_cast<std::chrono::milliseconds>(end-start).count()<<" ms"<<endl;
        delete[] arr;
    }
    return 0;
}
