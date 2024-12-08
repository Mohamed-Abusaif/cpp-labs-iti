#include <iostream>

using namespace std;

class Base
{

protected:
    int x;
    int y;

public:
    Base()
    {
        x = 0;
        y = 0;
        cout << "Parent no parameterize constractor \n";
    }
    Base(int x, int y)
    {
        cout << "Parent Parameterize constractor \n";
        this->x = x;
        this->y = y;
    }

    virtual int sum()
    {
        return x + y;
    }
    void display()
    {
        cout << "X = " << x << " " << "Y = " << y << endl;
    }
};

class Derived : public Base
{
protected:
    int z;

public:
    Derived() : Base()
    {
        cout << "Drived non parameterized constractor \n";
        // z=1;
    }
    Derived(int x, int y, int z) : Base(x, y)
    {
        this->z = z;
        cout << "Drived  parameterized constractor\n";
    }
    int sum()
    {

        return x + y + z;
    }
    void display()
    {
        cout << "X = " << x << " " << "Y = " << y << " " << "Z = " << z << endl;
    }
};
class Second_Derived : public Derived
{
private:
    int zz;

public:
    Second_Derived() : Derived()
    {
        zz = 0;
        cout << "Second_Derived non parameterized constractor\n";
    }
    Second_Derived(int x, int y, int z, int zz) : Derived(x, y, z)
    {
        this->zz = zz;
        cout << "Second_Derived  parameterized constractor\n";
    }
    int sum()
    {
        return x + y + z + zz;
    }
    void display()
    {
        cout << "X = " << x << " " << "Y = " << y << " " << "Z =" << z << " " << "ZZ = " << zz << endl;
    }
};

int main()
{

    int sum;

    cout << "NON PARAMETER TEST FOR DERIVED \n";
    Derived test1;
    test1.display();
    sum = test1.sum();
    cout << "sum= " << sum << endl;
    cout << "================================================== \n";
    cout << "PARAMETER TEST FOR DERIVED \n";
    Derived test2(5, 10, 15);
    test2.display();
    sum = test2.sum();
    cout << "sum= " << sum << endl;
    cout << "================================================== \n";
    cout << "NON PARAMETER TEST FOR Second_Derived  \n";
    Second_Derived test3;
    test3.display();
    sum = test3.sum();
    cout << "sum= " << sum << endl;
    cout << "================================================== \n";
    cout << "PARAMETER TEST FOR Second_Derived  \n";
    Second_Derived test4(5, 10, 15, 20);
    test4.display();
    sum = test4.sum();
    cout << "sum= " << sum << endl;

    return 0;
}