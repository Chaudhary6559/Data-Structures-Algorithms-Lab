#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
void merge(vector<int>&arr,int left,int mid,int right) 
{
    int n1=mid-left+1;
    int n2=right-mid;
    vector<int>left_arr(n1);
    vector<int>right_arr(n2);
    for(int i=0;i<n1;i++)
        left_arr[i]=arr[left+i];
    for(int j=0;j<n2;j++)
        right_arr[j]=arr[mid+1+j];
    int i=0;
    int j=0; 
    int k=left;
    while(i<n1&&j<n2) 
	{
        if(left_arr[i]<=right_arr[j]) 
		{
            arr[k]=left_arr[i];
            i++;
        } 
		else 
		{
            arr[k]=right_arr[j];
            j++;
        }
        k++;
    }
    while(i<n1) 
	{
        arr[k]=left_arr[i];
        i++;
        k++;
    }
    while(j<n2) 
	{
        arr[k]=right_arr[j];
        j++;
        k++;
    }
}
void merge_sort(vector<int>& arr,int left,int right) 
{
    if(left<right) 
	{
        int mid=left+(right-left)/2;
        merge_sort(arr,left,mid);
        merge_sort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
int main() 
{
    srand(time(0));
    const int array_size=10;
    vector<int>my_vector(array_size);
    cout<<"Original array: ";
    for(int i=0;i<array_size;++i) 
	{
        my_vector[i]=rand()%100;
        cout<<my_vector[i]<<" ";
    }
    cout<<endl;
    merge_sort(my_vector,0,array_size-1);
    cout<<"Sorted array: ";
    for(int i=0;i<array_size;++i) 
	{
        cout<<my_vector[i]<<" ";
    }
    cout<<endl;
    return 0;
}
