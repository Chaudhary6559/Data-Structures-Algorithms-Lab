#include <iostream>
using namespace std;
int main() {
    int n;
    cout<<"Enter the number of elements in the array: "<<endl;
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
        for (int j=0;j<n;j++) 
		{
            sum+=array[i]+array[j];
        }
    }
    cout<<"Sum of all pairs of elements: "<<sum<<endl;
    return 0;
}
