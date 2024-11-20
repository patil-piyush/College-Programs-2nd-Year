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

char *InfixToPostfix(char *inf)
{
    stack s;
    int i = 0, j = 0;
    char x;
    char *postfix = new char[strlen(inf)];
    while (inf[i] != '\0')
    {
        x = inf[i];
        if (x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z'){
            postfix[j++] = x;
        }
        else if(Operator(x)){
            while(!s.isempty() && precedance(s.peek())>=precedance(x)){
                postfix[j++] = s.pop();
            }
            s.push(x);
        }
        else if(x == '('){
            s.push(x);
        }
        else if(x==')'){
            while(s.peek()!='('){
                postfix[j++] = s.pop();
            }
            s.pop();
        }
        i++;
    }
    while(!s.isempty()){
        postfix[j++] = s.pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char infix[] = "a+b*c-d/e";
    char* postfix = InfixToPostfix(infix);
    cout<<postfix;
    return 0;
}