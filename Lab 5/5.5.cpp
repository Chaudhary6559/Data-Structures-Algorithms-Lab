#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
void bubbleSort(int arr[],int n) 
{
    for(int i=0;i<n-1;++i) 
	{
        for(int j=0;j<n-i-1;++j) 
		{
            if(arr[j]<arr[j+1]) 
			{
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void selectionSort(int arr[],int n) 
{
    for(int i=0;i<n-1;++i) 
	{
        int maxIndex=i;
        for(int j=i+1;j<n;++j) 
		{
            if (arr[j]>arr[maxIndex]) 
			{
                maxIndex=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[maxIndex];
        arr[maxIndex]=temp;
    }
}
void generateRandomArray(int arr[],int size) 
{
    for(int i=0;i<size;++i) 
	{
        arr[i]=rand()%1000;
    }
}
void measureTime(void(*sortingAlgorithm)(int[],int),int arr[],int size,const std::string&algorithmName) 
{
    auto start=chrono::high_resolution_clock::now();
    sortingAlgorithm(arr,size);
    auto end=chrono::high_resolution_clock::now();
    cout<<"Time taken by "<<algorithmName<<": "
              <<chrono::duration_cast<chrono::milliseconds>(end-start).count()<<"ms"<<endl;
}
int main() 
{
    const int minArraySize=10;
    const int maxArraySize=10000;
    const int stepSize=1000;
    for(int size=minArraySize;size<=maxArraySize;size+=stepSize) 
	{
        int* arrBubbleSort=new int[size];
        int* arrSelectionSort=new int[size];
        generateRandomArray(arrBubbleSort,size);
        copy(arrBubbleSort,arrBubbleSort+size,arrSelectionSort);
        cout<<"Array Size: "<<size<<endl;
        measureTime(bubbleSort,arrBubbleSort,size,"Modified Bubble Sort");
        measureTime(selectionSort,arrSelectionSort,size,"Modified Selection Sort");
        delete[] arrBubbleSort;
        delete[] arrSelectionSort;
    }
    return 0;
}
