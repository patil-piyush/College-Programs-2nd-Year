#include <iostream>
#include <cstring> // For strlen
using namespace std;

class Stack {
public:
    int arr[100]; // Array to store stack elements
    int Top; // Index of the top element in the stack

    // Constructor to initialize the stack
    Stack() {
        Top = -1; // Stack is initially empty
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return (Top == -1);
    }

    // Function to push an element onto the stack
    void push(int value) {
        if (Top < 99) {
            arr[++Top] = value; // Increment Top and add the value
        } else {
            cout << "Stack overflow\n";
        }
    }

    // Function to pop an element from the stack
    int pop() {
        if (!isEmpty()) {
            return arr[Top--]; // Return the top value and decrement Top
        } else {
            cout << "Stack underflow\n";
            return -1; // Return an invalid value if the stack is empty
        }
    }

    // Function to get the top element of the stack without removing it
    int peek() {
        if (!isEmpty()) {
            return arr[Top]; // Return the top value
        } else {
            cout << "Stack is empty\n";
            return -1; // Return an invalid value if the stack is empty
        }
    }
};

class PostfixEvaluator {
private:
    Stack stack; // Stack to hold integer values
    char arr[100]; // Array to hold the postfix expression

public:
    // Function to read a postfix expression from the user
    void read() {
        cout << "Enter the Postfix Expression: ";
        cin >> arr;
    }

    // Function to evaluate the postfix expression
    int evaluate() {
        for (int i = 0; i < strlen(arr); i++) {
            char c = arr[i];

            // If the character is a digit, push it onto the stack
            if (isdigit(c)) {
                stack.push(c - '0'); // Convert char to int and push
            } 
            // If the character is an operator
            else if (isOperator(c)) {
                int b = stack.pop(); // Pop the top two elements
                int a = stack.pop();

                // Perform the operation and push the result onto the stack
                int result = performOperation(a, b, c);
                stack.push(result);
            }
        }

        return stack.pop(); // The final result will be the only value left in the stack
    }

    // Function to check if a character is an operator
    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '/' || c == '*');
    }

    // Function to perform the operation based on the operator
    int performOperation(int a, int b, char op) {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b; // Assumes b != 0
            default: return 0;
        }
    }
};

int main() {
    PostfixEvaluator evaluator; // Create an evaluator object
    evaluator.read(); // Read the postfix expression
    int result = evaluator.evaluate(); // Evaluate the expression
    cout << "The result of the postfix expression is: " << result << endl; // Display the result
    return 0;
}
