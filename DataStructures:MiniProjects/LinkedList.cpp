#include <iostream>
using namespace std;

typedef struct Node {
    int data;
    Node *next;
}Node;

void initNode(Node *head, int n) {
    head->data = n;
    head->next = NULL;
}

void insertFront(Node **head, int n) {
    Node *newNode = new Node;
    newNode->data = n;
    newNode->next = *head;
    *head = newNode;
}

void addNode (Node *head, int n) {
    Node *newNode = new Node;
    newNode->data = n;
    newNode->next = NULL;
    
    Node *cur = head;
    while (cur) {
        if (cur->next == NULL) {
            cur->next = newNode;
            return;
        }
        cur = cur->next;
    }
}

Node *searchNode(Node *head, int n) {
    Node *cur = head;
    while (cur) {
        if (cur->data == n) {
            return cur;
        }
        cur = cur->next;
    }
    cout << "Node " << n << " not found in this linked list";
}

bool deleteNode(Node **head, Node *ptrDel) {
    Node *cur = *head;
    if (ptrDel == cur) {
        *head = cur->next;
        delete ptrDel;
        return true;
    }
    
    while (cur) {
        if (cur->next == ptrDel) {
            cur->next = ptrDel->next;
            delete ptrDel;
            return true;
        }
        cur = cur->next;
    }
    return false;
}

Node *reverse(Node **head) {
    Node *parent = *head;
    Node *me = parent->next;
    Node *child = me->next;
    
    parent->next = NULL;
    while(child) {
        me->next = parent;
        parent = me;
        me = child;
        child = child->next;
    }
    
    me->next = parent;
    *head = me;
    return *head;
    
}

void display(Node *head) {
    Node *list = head;
    while(list) {
        cout << list->data << " ";
        list = list->next;
    }
    cout << endl;
    cout << endl;
}


int main() {
    Node *head = new Node;
    
    initNode(head, 2);
    display(head);
    
    addNode(head, 3);
    addNode(head, 4);
    addNode(head, 5);
    addNode(head, 6);
    
    display(head);
    
    insertFront(&head, 1);
    display(head);
    
    int nodeDel = 6;
    Node *ptrDelete = searchNode(head, nodeDel);
    deleteNode(&head, ptrDelete);
    
    display(head);
	
	cout << "Linked list will now be reversed: " << endl;
	reverse(&head);
	display(head);
	
	cout << "Linked list will be back in order with an extra node added: " << endl;
	reverse(&head);
	addNode(head, 6);
	display(head);
	
    
	return 0;
}
