#ifndef STACK_H
#define STACK_H
class Stack {
private:
    int* data;
    int topIndex;
    int capacity;

    void resize() {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i <= topIndex; ++i) newData[i] = data[i];
        delete[] data;
        data = newData;
    }

public:
    Stack() : topIndex(-1), capacity(10) { data = new int[capacity]; }

    ~Stack() { delete[] data; }

    void push(int value) {
        if (topIndex + 1 == capacity) resize();
        data[++topIndex] = value;
    }

    void pop() {
        if (topIndex >= 0) --topIndex;
    }

    int top() const {
        return data[topIndex];
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    int size() const {
        return topIndex + 1;
    }
};



#endif // STACK_H
