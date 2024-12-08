#include <iostream>

using namespace std;


class Base {

private:
int a ;
int b ;

public:
Base(){
cout << "Base Class Called!" << endl;
}
void sum(){
return a+b;
}




};

class Derived : public Base{

private:
int c ;

public:
Derived(){
cout << "Derived Class Called!" << endl;
}

void sum2(){
return a+b;
}

};

class secondeDerived{

private:

public:


}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
