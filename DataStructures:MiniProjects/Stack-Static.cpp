#include <iostream>
using namespace std;

//Static Stack Example

int top = -1;

void push (int stack[], int x, int n) {
    if (top == n-1) 
        cout << "Stack is full. Overflow condition!" << endl;
    else {
        top+=1;
        stack[top] = x;
    }
}

bool isEmpty() {
    if (top == -1)
        return true;
    else
        return false;
}

void pop () {
    if (isEmpty())
        cout << "Stack is empty. Underflow condition!" << endl;
    else
        top-=1;
}

int size() {
    return top+1;   
}

int topElement (int stack[]) {
    return stack[top];
}

int main() {
    int stack[3];
    push(stack, 5, 3);
    
    cout << "Current size of stack is " << size() << endl;
    
    push(stack, 10, 3);
    push(stack, 24, 3);
    pop();
    cout << "Current size of stack is " << size() << endl;
    
    push(stack, 12, 3);
    
    cout << "The current top element in stack is " << topElement(stack) << endl;
    
    for (int i = 0; i < 3; i++)
        cout << stack[i] << endl;
    
    for (int i = 0; i < 3; i++)
        pop();
        
    cout << "Current size of stack is " << size() << endl;
    
    pop();

	return 0;
}
