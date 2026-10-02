#include <iostream>
#include <chrono>
#include <cstdlib> 
using namespace std;
void insertionSort(int arr[],int n) 
{
    for(int i=1;i<n;++i) 
	{
        int key=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>key) 
		{
            arr[j+1]=arr[j];
            --j;
        }
        arr[j+1]=key;
    }
}
void modifiedInsertionSort(int arr[],int n) 
{
    for(int i=1;i<n;++i) 
	{
        int key=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]<key) 
		{
            arr[j+1]=arr[j];
            --j;
        }
        arr[j+1]=key;
    }
}
void generateRandomArray(int arr[],int size) 
{
    for(int i=0;i<size;++i) 
	{
        arr[i]=rand()%1000;
    }
}
void measureTime(void(*sortingAlgorithm)(int[],int),int arr[],int size,const string& algorithmName) 
{
    auto start=chrono::high_resolution_clock::now();
    sortingAlgorithm(arr,size);
    auto end=chrono::high_resolution_clock::now();
    cout<<"Time taken by "<<algorithmName<<": "
              <<chrono::duration_cast<chrono::milliseconds>(end-start).count()<<" ms"<<endl;
}
int main() 
{
    const int minArraySize=10;
    const int maxArraySize=10000;
    const int stepSize=1000;
    for(int size=minArraySize;size<=maxArraySize;size+=stepSize) 
	{
        int* arrOriginal=new int[size];
        int* arrModified=new int[size];
        generateRandomArray(arrOriginal,size);
        copy(arrOriginal,arrOriginal+size,arrModified);
        cout<<"Array Size: "<<size<<endl;
        measureTime(insertionSort,arrOriginal,size,"Original Insertion Sort");
        measureTime(modifiedInsertionSort,arrModified,size,"Modified Insertion Sort");
        delete[] arrOriginal;
        delete[] arrModified;
    }
    return 0;
}
