#include <iostream>
using namespace std;
int main() 
{
    const int numRows =150;
    const int a = 8;
    const int b = 7;

    for (int i = 1; i <= numRows; ++i) 
	{
        int result = a * b;
        cout<<"Row "<<i<<": "<<a<<" * "<<b<<" = "<<result<<endl;
    }
    return 0;
}
