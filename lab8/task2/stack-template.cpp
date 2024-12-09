#include <iostream>

using namespace std;

template <typename T>
class Stack {
private:
    T* data;         
    int topIndex;    
    int capacity;    

    void resize() {
        capacity *= 2;
        T* newData = new T[capacity]; 
        for (int i = 0; i <= topIndex; ++i) 
            newData[i] = data[i];
        delete[] data; 
        data = newData;
    }

public:
    Stack() : topIndex(-1), capacity(10) { data = new T[capacity]; }

    ~Stack() { delete[] data; }

    void push(const T& value) {
        if (topIndex + 1 == capacity) resize();
        data[++topIndex] = value;
    }

    void pop() {
        if (topIndex >= 0) --topIndex;
    }

    T top() const {
        if (isEmpty()) throw runtime_error("Stack is empty");
        return data[topIndex];
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    int size() const {
        return topIndex + 1;
    }
};

int main() {
    Stack<int> intStack;    
    intStack.push(10);
    intStack.push(20);
    cout << "Top of intStack: " << intStack.top() << endl; 
    intStack.pop();
    cout << "Top of intStack after pop: " << intStack.top() << endl; 

    Stack<string> stringStack; 
    stringStack.push("Hello");
    stringStack.push("World");
    cout << "Top of stringStack: " << stringStack.top() << endl; 
    stringStack.pop();
    cout << "Top of stringStack after pop: " << stringStack.top() << endl; 

    return 0;
}
