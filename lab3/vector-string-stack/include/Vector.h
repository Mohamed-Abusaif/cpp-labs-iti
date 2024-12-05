#ifndef VECTOR_H
#define VECTOR_H

class Vector {
private:
    int* data;
    int currentSize;
    int capacity;

    void resize() {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < currentSize; ++i) newData[i] = data[i];
        delete[] data;
        data = newData;
    }

public:
    Vector() : currentSize(0), capacity(10) { data = new int[capacity]; }

    ~Vector() { delete[] data; }

    void push_back(int value) {
        if (currentSize == capacity) resize();
        data[currentSize++] = value;
    }

    void pop_back() {
        if (currentSize > 0) --currentSize;
    }

    int& operator[](int index) {
        return data[index];
    }

    int size() const {
        return currentSize;
    }

    int getCapacity() const {
        return capacity;
    }

    void clear() {
        currentSize = 0;
    }
};



#endif // VECTOR_H
