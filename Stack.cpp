#include <iostream>
#include <string>
#include <cstring>
#include <conio.h>
#define SIZE 300

using namespace std;

/*
Implementation of Stack class
*/
class Stack
{
    // index of the top value
    int top;

public:
    // no-arg constructor
    Stack()
    {
        top = -1;
    }

    char arr[SIZE];

    /*
        To check if the stack is empty
        */
    bool isEmpty()
    {
        return top < 0;
    }

    /*
        To check if the stack is full
        */
    bool isFull()
    {
        return top >= (SIZE - 1);
    }

    /*
        To insert an element into the stack
        */
    void push(char element)
    {
        // if stack is full, return
        if (isFull())
        {
            return;
        }

        // if stack is not full, placing element at the top
        arr[++top] = element;
    }

    /*
        To delete & return the last value
        */
    char pop()
    {
        // if stack is empty, return
        if (isEmpty())
        {
            return ' ';
        }

        // if stack is not empty, return last value & delete
        return arr[top--];
    }

    /*
        To display the peak of stack
        */
    void peak()
    {
        // if stack is empty, return
        if (isEmpty())
        {
            return;
        }

        // if not, display the top value
        cout << "Peak of the stack: "
             << arr[top]
             << endl;
    }

    /*
        To empty the stack
        */
    void clear()
    {
        // keep deleting until empty
        while (!isEmpty())
        {
            pop();
        }
    }
}; // end of Stack class

/*
Testing the Stack class
*/
int main()
{
    // Stack object, user's expression, & top element variables
    Stack *stack = new Stack();
    string expression;
    char last;

    // taking user input
    cout << "\nEnter your algebraic expression: ";

    // for spaces in algebraic expression
    cin.ignore();
    getline(cin, expression);

    // finding opening & closing brackets
    for (int i = 0; i < expression.length(); i++)
    {

        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            stack->push(expression[i]);
        }

        else if (expression[i] == ')')
        {
            // top value
            last = stack->pop();

            // if matching bracket found, continue the loop
            if (last == '(')
            {
                continue;
            }

            // if not, placing last back & stopping iteration
            stack->push(last);
            break;
        }

        else if (expression[i] == ']')
        {
            // top value
            last = stack->pop();

            // if matching bracket found, continue the loop
            if (last == '[')
            {
                continue;
            }

            // if not, placing last back & stopping iteration
            stack->push(last);
            break;
        }

        else if (expression[i] == '}')
        {
            // top value
            last = stack->pop();

            // if matching bracket found, continue the loop
            if (last == '{')
            {
                continue;
            }

            // if not, placing last back & stopping iteration
            stack->push(last);
            break;
        }

    }

    if (stack->isEmpty())
    {
        cout << "\nExpression Valid.\n";
    }

    else
    {
        cout << "\nExpression Invalid.\n";
    }
}