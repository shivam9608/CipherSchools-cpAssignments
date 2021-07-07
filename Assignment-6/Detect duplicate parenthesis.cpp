//Ques.14) Detect duplicate parenthesis.
//Sol.
#include <iostream>
#include <stack>
using namespace std;
 
// Function to find duplicate parenthesis in an expression
void duplicateParenthesis(string exp)
{
    if (exp.length() <= 3) {
        return;
    }
 
    // take an empty stack of characters
    stack<char> stack;
 
    // traverse the input expression
    for (char c: exp)
    {
        // if the current char in the expression is not a closing parenthesis
        if (c != ')') {
            stack.push(c);
        }
        // if the current char in the expression is a closing parenthesis
        else {
            // if the stack's top element is an opening parenthesis,
            // the subexpression of the form ((exp)) is found
            if (stack.top() == '(')
            {
                cout << "The expression has duplicate parenthesis.";
                return;
            }
 
            // pop till `(` is found for current `)`
            while (stack.top() != '(') {
                stack.pop();
            }
 
            // pop `(`
            stack.pop();
        }
    }
 
    // if we reach here, then the expression does not have any
    // duplicate parenthesis
    cout << "The expression does not have duplicate parenthesis";
}
 
int main()
{
    string exp = "((x+y))";        // assumes valid expression
 
    duplicateParenthesis(exp);
 
    return 0;
}
