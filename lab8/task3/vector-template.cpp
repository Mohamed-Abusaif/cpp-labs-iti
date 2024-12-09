#include <iostream>

template <typename T>
class Vector
{
private:
    T *data;
    int currentSize;
    int capacity;

    void resize()
    {
        capacity *= 2;
        T *newData = new T[capacity];
        for (int i = 0; i < currentSize; ++i)
            newData[i] = data[i];
        delete[] data;
        data = newData;
    }

public:
    Vector() : currentSize(0), capacity(10)
    {
        data = new T[capacity];
    }

    ~Vector()
    {
        delete[] data;
    }

    void push_back(const T &value)
    {
        if (currentSize == capacity)
            resize();
        data[currentSize++] = value;
    }

    void pop_back()
    {
        if (currentSize > 0)
            --currentSize;
    }

    T &operator[](int index)
    {
        if (index < 0 || index >= currentSize)
            throw std::out_of_range("Index out of bounds");
        return data[index];
    }

    int size() const
    {
        return currentSize;
    }

    int getCapacity() const
    {
        return capacity;
    }

    void clear()
    {
        currentSize = 0;
    }
};

using namespace std;

int main()
{
    // Vector for integers
    Vector<int> intVector;
    intVector.push_back(10);
    intVector.push_back(20);
    intVector.push_back(30);

    cout << "Integer Vector:" << endl;
    for (int i = 0; i < intVector.size(); ++i)
    {
        cout << intVector[i] << " ";
    }
    cout << "\nSize: " << intVector.size() << ", Capacity: " << intVector.getCapacity() << endl;

    // Vector for strings
    Vector<string> stringVector;
    stringVector.push_back("Hello");
    stringVector.push_back("World");
    stringVector.push_back("!");

    cout << "\nString Vector:" << endl;
    for (int i = 0; i < stringVector.size(); ++i)
    {
        cout << stringVector[i] << " ";
    }
    cout << "\nSize: " << stringVector.size() << ", Capacity: " << stringVector.getCapacity() << endl;

    // Test clearing the vector
    stringVector.clear();
    cout << "\nAfter clearing, string vector size: " << stringVector.size() << endl;

    return 0;
}
