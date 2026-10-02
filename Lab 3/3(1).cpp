#include <iostream>
using namespace std;
int constantTimeExample() 
{
    int constantValue1 = 797;
    int constantValue2 = 3777;
    int result = constantValue1 + constantValue2;
    cout << "Result: " << result <<endl;
    return 99;
}

int main() 
{
    int result = constantTimeExample();
    cout << "Returned constant value: " << result <<endl;

    return 0;
}
