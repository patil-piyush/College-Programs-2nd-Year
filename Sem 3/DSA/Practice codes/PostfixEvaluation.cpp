#include <iostream>
#include <string.h>
using namespace std;
#define size 10

class stack
{
public:
    char data[size]; // Array to store characters (operators/operands)
    int top;         // Index of the top of the stack

    stack()
    { // Constructor to initialize the top of the stack
        top = -1;
    }

    void push(char c)
    { // Push a character onto the stack
        data[++top] = c;
    }

    char pop()
    { // Pop a character from the stack
        return data[top--];
    }

    char peek()
    { // Peek at the top of the stack without popping it
        return data[top];
    }

    bool isempty()
    { // Check if the stack is empty
        return top == -1;
    }

    bool isFull()
    {
        return top == size - 1;
    }
};

bool Operator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedance(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '^')
        return 4;
    else
        return 0;
}

char *PostfixEvaluation(char *post)
{
    
}

int main()
{
    char postfix[] = "a+b*c-d/e";

    cout<<postfix;
    return 0;
}