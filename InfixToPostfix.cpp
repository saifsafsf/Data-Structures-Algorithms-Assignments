#include <iostream>
#include <string>
#include <cstring>
#include <conio.h>
#include <map>
#include <math.h>
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

    string arr[SIZE];

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
    void push(string element)
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
    string pop()
    {
        // if stack is empty, return
        if (isEmpty())
        {
            return "";
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
converts infix to postfix
returns postfix expression & postfix stack
*/
string infix_to_postfix(string expression, Stack *postfix)
{
    // stacks to store temp stacks & output stack
    Stack *stack = new Stack();
    Stack *output = new Stack();

    /* precedences of the operators
    brackets' prec is 0 because
    when operator is found in expression
    all operators with higher or equal prec are removed
    but it must not go beyond any open bracket
    0 prec does NOT mean brackets are solved at last */
    map<string, int> preced = 
    {
        {"[", 0},
        {"(", 0},
        {"{", 0},
        {"+", 10},
        {"-", 10},
        {"*", 20},
        {"/", 20},
        {"%", 20},
        {"^", 30}
    };

    // operating on each chraacter
    for (int i = 0; i < expression.length(); i++)
    {
        // when digit found
        if (isdigit(expression[i]))
        {
            // converting char to string
            string integer(1, expression[i]);

            // when consecutive digits found, concatenating all the digits of a number
            // even works for the floating point numbers
            while(i < expression.length()-1 && (isdigit(expression[i+1]) || expression[i+1] == '.'))
            {
                integer += expression[++i];
            }

            // sending the whole number into the stack instead of single digits
            output->push(integer);
        }

        // any open bracket found
        else if (expression[i] == '{' || expression[i] == '[' || expression[i] == '(')
        {
            // converted into string, sent to temp stack
            stack->push(string(1, expression[i]));
        }

        // closing curly bracket found
        else if (expression[i] == '}')
        {
            string popped = stack->pop();

            // popping until its corresponding closing found or end of stack
            while (popped != "{" && popped != "")
            {
                // all elements to output stack
                output->push(popped);
                popped = stack->pop();
            }
        }

        // closing square bracket found
        else if (expression[i] == ']')
        {
            string popped = stack->pop();
            
            // popping until its corresponding closing found or end of stack
            while (popped != "[" && popped != "")
            {
                // all elements to output stack
                output->push(popped);
                popped = stack->pop();
            }
        }

        // closing parenthesis found
        else if (expression[i] == ')')
        {
            string popped = stack->pop();

            // popping until its corresponding closing found or end of stack
            while (popped != "(" && popped != "")
            {
                // all elements to output stack
                output->push(popped);
                popped = stack->pop();
            }
        }

        // any operator found
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*'
        || expression[i] == '/' || expression[i] == '%' || expression[i] == '^')
        {
            string popped = stack->pop();

            // popping until an operator with lower prec found
            // or an open bracket found or end of stack found
            while (popped != ""
            && preced.at(popped) >= preced.at(string(1, expression[i])))
            {
                // sent to the output
                output->push(popped);
                popped = stack->pop();
            }

            // if temp stack becomes empty, dont push last popped back
            if (popped == "")
            {
                goto empty;
            }

            // sentinel value found, pushing it back into stack
            // sentinel value i.e. an open bracket or an operator with lower prec
            stack->push(popped);

            empty:
            // pushing value found into stack, after necessary pops
                stack->push(string(1, expression[i]));
        }

        // Invalid Character encountered, a symbol etc
        else
        {
            cout << "Invalid Character encountered...\n\n";
            break;
        }
    }

    // empty the temp stack at the end
    string popped = stack->pop();

    while(popped != "")
    {
        // pushing all into output
        output->push(popped);
        popped = stack->pop();
    }

    // output stack ready but with reverse postfix expression

    popped = output->pop();
    

    // pushing into postfix stack, also, making a string expression postfix_str
    if (popped != "")
    {
        string postfix_str = popped;
        postfix->push(popped);

        // updating popped value
        popped = output->pop();

        while(popped != "")
        {
            // postfix stack storing postfix expression in right order
            postfix->push(popped);

            // postfix_str for string postfix expression
            postfix_str = popped + " " + postfix_str;

            popped = output->pop();
        }

        return postfix_str;
    }
}

/*
computes on last 2 operands from the stack
pushes result back into stack
*/
void compute(Stack *nums, string oper1, string oper2, string oper)
{
    // operating last 2 numbers with corresponding operator
    // converting string operands to double
    // coverting value to string
    if (oper == "+")
    {
        nums->push(to_string(stod(oper1)+stod(oper2)));
    }

    else if (oper == "-")
    {
        nums->push(to_string(stod(oper1)-stod(oper2)));
    }

    else if (oper == "*")
    {
        nums->push(to_string(stod(oper1)*stod(oper2)));
    }

    else if (oper == "/")
    {
        nums->push(to_string(stod(oper1)/stod(oper2)));
    }

    else if (oper == "%")
    {
        nums->push(to_string(stoi(oper1)%stoi(oper2)));
    }

    else if (oper == "^")
    {
        nums->push(to_string(pow(stod(oper1), stod(oper2))));
    }
}

/*
takes postfix stack & returns the evaluated answer
*/
double eval_postfix(Stack *nums, Stack *postfix)
{
    string popped = postfix->pop();

    // iterating thru postfix stack to evaluate it
    while (popped != "")
    {
        // multi-digit or single-digit number found
        if (isdigit(popped[0]))
        {
            // pushing into the eval stack
            nums->push(popped);

            popped = postfix->pop();
        }

        // operator found
        else if (popped == "+" || popped == "-" || popped == "*"
        || popped == "^" || popped == "/" || popped == "%")
        {
            // assigning first to right & second to left
            string oper2 = nums->pop();
            string oper1 = nums->pop();

            // if stack goes empty before popping 2 integers
            if (oper1 == "")
            {
                cout << "Invalid Postfix Expression...\n\n";
                break;
            }

            // compute() idea here
            compute(nums, oper1, oper2, popped);

            // updating value
            popped = postfix->pop();
        }

        // invalid symbol found in postfix
        else
        {
            cout << "Invalid Postfix Expression...\n\n";
            break;
        }
    }

    // converted string (final answer) to double
    double ans = stod(nums->pop());

    // this pop should return empty str, nums should have only one final ans
    popped = nums->pop();

    // if not empty
    if (popped != "")
    {
        cout << "Invalid Postfix Expression...\n\n";
    }

    return ans;
}

/*
Testing the Stack class
*/
int main()
{
    // to store infix expression
    string expression;

    // to store postfix expression
    Stack *postfix = new Stack();

    // to store postfix string
    string postfix_str;

    // taking user input
    cout << "\nEnter your algebraic expression (without spaces): ";

    // for spaces in algebraic expression
    getline(cin, expression);

    // converting infix to postfix
    postfix_str = infix_to_postfix(expression, postfix);

    // displaying postfix expression
    cout << "\nPostfix Expression: " << postfix_str << endl;

    // stack to store & evaluate numbers from postfix
    Stack *nums = new Stack();

    // evaluated answer of postfix
    double ans = eval_postfix(nums, postfix);

    // displaying evaluated answer
    cout << "\nAnswer: " << ans << endl << endl;
}
