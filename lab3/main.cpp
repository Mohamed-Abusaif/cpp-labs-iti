#include <iostream>
#include "Stack.h"
#include "String.h"
#include "Vector.h"

// Include your Stack, Vector, and String classes here

int main() {
    // Testing Stack
    Stack stack;
    std::cout << "Testing Stack:\n";
    stack.push(10);
    stack.push(20);
    stack.push(30);
    std::cout << "Top element: " << stack.top() << "\n"; // Expected: 30
    stack.pop();
    std::cout << "Top element after pop: " << stack.top() << "\n"; // Expected: 20
    std::cout << "Stack size: " << stack.size() << "\n"; // Expected: 2
    std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << "\n"; // Expected: No
    stack.pop();
    stack.pop();
    std::cout << "Is stack empty after popping all elements? " << (stack.isEmpty() ? "Yes" : "No") << "\n"; // Expected: Yes

    // Testing Vector
    Vector vector;
    std::cout << "\nTesting Vector:\n";
    vector.push_back(5);
    vector.push_back(15);
    vector.push_back(25);
    std::cout << "Element at index 0: " << vector[0] << "\n"; // Expected: 5
    std::cout << "Element at index 1: " << vector[1] << "\n"; // Expected: 15
    std::cout << "Element at index 2: " << vector[2] << "\n"; // Expected: 25
    std::cout << "Vector size: " << vector.size() << "\n"; // Expected: 3
    vector.pop_back();
    std::cout << "Vector size after pop_back: " << vector.size() << "\n"; // Expected: 2
    vector.clear();
    std::cout << "Vector size after clear: " << vector.size() << "\n"; // Expected: 0

    // Testing String
    String str("Hello");
    std::cout << "\nTesting String:\n";
    std::cout << "Initial string: " << str.c_str() << "\n"; // Expected: Hello
    str.append(" World");
    std::cout << "String after append: " << str.c_str() << "\n"; // Expected: Hello World
    std::cout << "String size: " << str.size() << "\n"; // Expected: 11
    str.clear();
    std::cout << "String after clear: " << (str.size() == 0 ? "Empty" : str.c_str()) << "\n"; // Expected: Empty

    return 0;
}
