#include <iostream>
using namespace std;
int main() 
{
    int num;
    cout<<"Enter a number: ";
    cin>>num;

    for (;num!=1;) 
	{
        if (num%2==0) 
		{
            num=num/2;
            cout<<"Divided by 2: "<<num<<endl;
        }
		 else 
		{
            num=num*3+1;
            cout<<"Multiplied by 3 and added 1: "<<num<<endl;
        }
    }

    cout<<"The number is now 1."<<endl;

}