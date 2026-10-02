#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>&arr,int left,int mid,int right) 
{
    int f=mid-left+1;
    int g=right-mid;
    vector<int>left_arr(f);
    vector<int>right_arr(g);
    for(int i=0;i<f;i++)
        left_arr[i]=arr[left+i];
    for(int j=0;j<g;j++)
        right_arr[j]=arr[mid+1+j];
    int i=0;
    int j=0;  
    int k=left;
    while(i<f&&j<g) 
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
    while(i<f) 
	{
        arr[k]=left_arr[i];
        i++;
        k++;
    }
    while(j<g) 
	{
        arr[k]=right_arr[j];
        j++;
        k++;
    }
}
void merge_sort(vector<int>&arr,int left,int right)
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
    vector<int>my_vector={83,72,34,30,90,28,100};
    int size=my_vector.size();
    merge_sort(my_vector,0,size-1);
    cout<<"Sorted array: ";
    for(int i=0;i<size;i++) 
	{
        cout<<my_vector[i]<<" ";
    }
    cout<<endl;
    return 0;
}
