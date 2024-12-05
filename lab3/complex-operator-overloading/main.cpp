#include <iostream>
using namespace std;
class Complex
{
    signed int real, imag;

public:


    Complex(int real=0 , int imag=0)
    {
        this-> real = real;
        this-> imag = imag;
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
    Complex operator+(Complex c1){
    Complex temp;

    temp.real = this -> real+ c1.real;
    temp.imag = this -> imag+ c1.imag;

    return temp;
    }
    Complex* operator++(){
        (this->real)++;
        return this;
    }
    Complex* operator++(int uselesVar){
        this->real++;
        return this;
    }
    Complex* operator--(){
        (this->real)--;
        return this;
    }
    Complex* operator--(int uselesVar){
        (this->real)--;
        return this;
    }

    Complex operator+(int num){
        return this->real + num;
    }
    Complex operator-(int num){
        return this->real - num;
    }


    ~Complex()
    {
        cout << "Destructor Called On Object!" << endl;
    }
};

Complex addNumOnComplex(int num , Complex c){
Complex temp;
temp.setComplex(c.getReal() + num , c.getImag());
return temp;
}
Complex subNumOnComplex(int num , Complex c){
Complex temp;
temp.setComplex(c.getReal() - num , c.getImag());
return temp;
}



int main()
{
    Complex c1;
    Complex c2;
    Complex c3;

    c1.setComplex(20, 50);
    c2.setComplex(10, 30);
    c3.setComplex(60, 40);

    /*c1++;
    c2++;
    c3++;
    ++c1;
    ++c2;
    ++c3;*/
    cout << "Display for ++ postfix and prefix:" << endl;
    c1.display();
    c2.display();
    c3.display();
    cout << "--------------------------" <<endl;
    cout << "Display for 5+c and c+5:" << endl;
    Complex c4 = subNumOnComplex(30,c1);
    c4.display();

    return 0;
}
