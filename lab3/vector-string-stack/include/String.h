#ifndef STRING_H
#define STRING_H

class String {
private:
    char* data;
    int length;

    void resize(int newLength) {
        char* newData = new char[newLength + 1];
        for (int i = 0; i < length; ++i) newData[i] = data[i];
        delete[] data;
        data = newData;
    }

public:
    String() : data(new char[1]{ '\0' }), length(0) {}

    String(const char* str) {
        length = 0;
        while (str[length] != '\0') ++length;
        data = new char[length + 1];
        for (int i = 0; i <= length; ++i) data[i] = str[i];
    }

    ~String() { delete[] data; }

    void append(const char* str) {
        int newLength = length;
        while (str[newLength - length] != '\0') ++newLength;
        resize(newLength);
        for (int i = 0; str[i] != '\0'; ++i) data[length + i] = str[i];
        length = newLength;
        data[length] = '\0';
    }

    int size() const {
        return length;
    }

    const char* c_str() const {
        return data;
    }

    void clear() {
        delete[] data;
        data = new char[1]{ '\0' };
        length = 0;
    }
};



#endif // STRING_H
