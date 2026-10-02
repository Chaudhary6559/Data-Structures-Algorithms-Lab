#include <iostream>
using namespace std;
int main() {
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int array[n];
    
    for (int i=0;i<n;i++) 
	{
        cout<<"Enter element "<<i<<": ";
        cin>>array[i];
    }
    int sum=0;
    for (int i=0;i<n;i++) 
	{
        sum+=array[i];
    }
	cout<<"Sum of elements: "<<sum<<endl;

    return 0;
}
