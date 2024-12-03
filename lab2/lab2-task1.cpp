#include <iostream>
using namespace std;
class Complex
{
    signed int real, imag;

public:
    Complex(int imag)
    {
        this->real = 0;
        this->imag = imag;
    }

    Complex(int real)
    {
        this->real = real;
        this->imag = 0;
    }

    Complex()
    {
        real = 0;
        imag = 0;
    }
    void setComplex(int r, int im)
    {
        this->real = r;
        this->imag = im;
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
            if (imag > 0)
            {
                cout << real << " + " << imag << "j" << endl;
            }
            else
            {
                cout << real << imag << "j" << endl;
            }
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
    ~Complex()
    {
        cout << "Destructor Called On Object!" << endl;
    }
};

int main()
{
    Complex c1;
    Complex c2;
    Complex c3;

    c1.setComplex(20, 50);
    c2.setComplex(10, 30);
    c3 = c1.addImaginaryNumber(c2);
    c1.display();
    c2.display();
    c3.display();

    return 0;
}
