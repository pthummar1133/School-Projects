#include <iostream>
using namespace std;

//Dynamic Stack 

//Node defined
typedef struct Element {
    void *data;
    Element *next;
}Element;

//node to create stack and keep track of when it is empty
bool createStack(Element **top) {
    *top = NULL;
    return true;
}

//access top local pointer with double pointer to point to local top Node
//create new Node to push to the top of the Stack, and change top Node to point to
//new pushed Element
bool push (Element **top, void *data) {
    Element *elem = new Element;
    if (!elem) return false;
    
    elem->data = data;
    elem->next = *top;
    *top = elem;
    return true;
}

//want to pop the top element, so double pointer needed on node and data
//Trying to understand the first if statement
//top node and data is changed to point to next element so the first element can be deleted.
bool pop (Element **top, void **data) {
    Element *elem;
    if (!(elem = *top)) return false;
    
    *data = elem->data;
    *top = elem->next;
    delete elem;
    return true;
}

//while *top pointer is not NULL, have elem equal to next node
//delete the top node, and reassign top to be elem(which is already the next NULL)
bool deleteStack (Element **top) {
    Element *elem;
    while (*top) {
        elem = (*top)->next;
        delete *top;
        *top = elem;
    }
    return true;
}

//First checks to see if stack is already empty
//Assign cur to be equal to top for safety
//while cur is not NULL, print the data (which is undefined pointer)
//set the printed data to an int value by static_cast-ing it
void printStack (Element *top) {
    if (top == NULL) {
        cout << "Empty!" << endl;
    }
    Element *cur = top;
    while (cur){
        cout << *(static_cast<int *>(cur->data)) << " ";
        cur = cur->next;
    }
    cout << endl << endl;
}

int main() {
    
    Element *head;
    createStack(&head);
    int n1 = 10, n2 = 20, n3 = 30, n4 = 40, n5 = 50;
    push(&head, &n1);
    push(&head, &n2);
    push(&head, &n3);
    push(&head, &n4);
    push(&head, &n5);
    
    printStack(head);
    
    void *n;
    pop(&head, &n);
    cout << "popped " << *(static_cast<int *>(n)) << endl;
    pop(&head, &n);
    cout << "popped " << *(static_cast<int *>(n)) << endl;
    cout << endl;
    
    printStack(head);
    
    cout << "deleting stack..." << endl;
    deleteStack(&head);
    printStack(head);



	return 0;
}
