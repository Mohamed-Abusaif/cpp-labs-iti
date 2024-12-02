// References in C++
// Example Swap and comparison between it and the new version using reference

#include <iostream>
using namespace std;

void swapByReference(int &num1, int &num2)
{

    int temp = 0;
    temp = num1;
    num1 = num2;
    num2 = temp;
}
void swapByAddress(int *num1, int *num2)
{

    int temp = 0;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
void swapByValue(int num1, int num2)
{

    int temp = 0;
    temp = num1;
    num1 = num1;
    num2 = temp;
}

int main()
{

    int x = 0;
    int y = 0;
    cout << "Enter x and y :" << endl;
    cin >> x >> y;

    cout << "Before swap x = " << x << endl;
    cout << "Before swap y = " << y << endl;

    swapByAddress(&x, &y);
    cout << "After swap x By Address = " << x << endl;
    cout << "After swap y By Address = " << y << endl;
    cout << "-----------------" << endl;

    swapByValue(x, y);
    cout << "After swap x By Value= " << x << endl;
    cout << "After swap y By Value= " << y << endl;
    cout << "-----------------" << endl;

    swapByReference(x, y);
    cout << "After swap x = " << x << endl;
    cout << "After swap y = " << y << endl;
    cout << "-----------------" << endl;

    return 0;
}

// swap using pointers and references
// then swap with value