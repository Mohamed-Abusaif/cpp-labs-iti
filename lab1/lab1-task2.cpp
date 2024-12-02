#include <iostream>
using namespace std;
class Complex
{
    signed int real, imag;

public:
    void setReal(int r)
    {
        real = r;
    }
    void setImag(int i)
    {
        imag = i;
    }
    int getReal()
    {
        return real;
    }
    int getImag()
    {
        return imag;
    }
    void display()
    {
        if (real == 0 && imag != 0)
        {
            cout << imag << "j" << endl;
        }
        else if (real != 0 && imag != 0)
        {
            cout << real << " + " << imag << "j" << endl;
        }
        else if (imag == 0 && real != 0)
        {
            cout << real << imag << "j" << endl;
        }
        else
        {
            cout << "No Data" << endl;
        }
    }
    Complex addImaginaryNumber(Complex complexNumToAdd)
    {
        Complex tempComplex;
        tempComplex.real = this->real + complexNumToAdd.real;
        tempComplex.imag = this->imag + complexNumToAdd.imag;
        return tempComplex;
    }
    Complex subtractImaginaryNumber(Complex complexNumToSubtract)
    {
        Complex tempComplex;
        tempComplex.real = this->real - complexNumToSubtract.real;
        tempComplex.imag = this->imag - complexNumToSubtract.imag;
        return tempComplex;
    }
};

int main()
{
    Complex c1;
    Complex c2;
    Complex c3;

    c1.setImag(5);
    c1.setReal(10);
    c2.setImag(20);
    c2.setReal(30);
    c1.display();
    // c3 = c1.addImaginaryNumber(c2);
    c3 = c1.subtractImaginaryNumber(c2);
    cout << c3.getImag() << endl;
    cout << c3.getReal() << endl;

    c3.display();

    return 0;
}

// add and subtract methods
// optimization to the logic (code) for the display function

// Notes about complex numbers:
/*

we have z(imaginary number) = a(real part) + b(imaginary part)i(imaginary unit)
addition -> if we have 2 imaginary numbers z1,z2 the addition is -> z1(a+bi) + z2(c+di) = (a+c) + (b+d)i
subtraction -> if we have 2 imaginary numbers z1,z2 the addition is -> z1(a+bi) - z2(c+di) = (a-c) - (b-d)i
imaginary numbers are not negative nor positive 


*/