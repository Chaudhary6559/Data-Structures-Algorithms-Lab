#include <iostream>
#include <vector>
using namespace std;
void performConstantTimeOperation(int value) 
{
    cout << "Element: " << value <<endl;
}

void linearTimeExample(const vector<int>& array) {
    for (int i = 0; i < array.size(); ++i) {
        performConstantTimeOperation(array[i]);
    }
    cout << "Total elements: " << array.size() <<endl;
}

int main() 
{    
    vector<int> inputArray = {1, 2, 3, 4, 5,5,6,7,8,9,867,45,34,3,45,656,76,768,545343,44,76,87,324,37,67,3457,6,265,23,45,67,78,23,456,76,23,87,54,95,23,56,98,23,56,45,67,778,23,45,679809,21,34,5,56,7,78,98,9766,54,4565,534,32,45,7,8,745,46,8,8754,87,54,88,12};
    linearTimeExample(inputArray);

    return 0;
}
