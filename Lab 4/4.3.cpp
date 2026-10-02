#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int x[17]={4,2,10,5,1,3,6,8,12,18,20,24,26,22,100,90,11};
	 sort(x, x + 17);

    
    for (int i = 0; i < 17; i++) {
        cout << x[i] << " ";}
        
	    int find = 4;
    int left = 0;
    int right = 16;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (x[mid] == find) {
            cout << "\nthe numbr " << find<< endl;
            return 0;
        } else if (x[mid] < find) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << "number is " << find<< " not found in the array" << endl;
}