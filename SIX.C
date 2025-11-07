/*
In any language program mostly syntax error occurs due to unbalancing delimiter such as
(), {}, []. Write a program using stack to check whether a given expression is well
parenthesized or not.
Implement a program for expression conversion as infix to postfix and its evaluation
using stack based on given conditions:
1. Operands and operators, both must be single characters.
2. Input Postfix expression must be in a desired format.
3. Only ”,”,” and operators are expected.
*/

#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

// Function to push a character onto the stack
void push(char c) {
    stack[++top] = c;
}

// Function to pop a character from the stack
char pop() {
    return stack[top--];
}

// Function to peek the top of the stack
char peek() {
    return stack[top];
}

// Check if character is an operator
int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Check if character is a letter (operand)
int is_letter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// Return operator precedence
int precedence(char op) {
    if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

// Function to convert infix to postfix
void infix_to_postfix(char infix[], char postfix[]) {
    int k = 0;
    int len = strlen(infix);

    for (int i = 0; i < len; i++) {
        char ch = infix[i];

        // If operand → directly add to postfix
        if (is_letter(ch)) {
            postfix[k++] = ch;
        }

        // If '(' → push to stack
        else if (ch == '(') {
            push(ch);
        }

        // If ')' → pop until '('
        else if (ch == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '(' from stack
        }

        // If operator → pop operators of higher or equal precedence
        else if (is_operator(ch)) {
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    // Pop any remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0'; // null-terminate the postfix string
}

// Main function
int main() {
    char infix[100], postfix[100];

    printf("Enter infix expression (e.g. A+B*C): ");
    fgets(infix, sizeof(infix), stdin);

    // Remove newline character from input
    size_t len = strlen(infix);
    if (len > 0 && infix[len - 1] == '\n')
        infix[len - 1] = '\0';

    // Convert and print
    infix_to_postfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}

