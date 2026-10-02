#include <iostream>
using namespace std;
int search(int arr[],int n,int x) {
    for (int i=0;i<n;i++) 
	{
        if (arr[i]==x)
            return i; 
    }
    return -1;
}

int main() {
    int arr[] = {10,20,30,11,16,24,100,50,80,21,33,60,65,71,90,99,1};
    int x = 71;
    int n = sizeof(arr) / sizeof(arr[0]); 

    int result = search(arr, n, x);
    if (result == -1)
        cout << "Element is not present in the array";
    else
        cout << "Element is present at index " << result;

    return 0;
}
