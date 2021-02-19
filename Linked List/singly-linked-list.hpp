#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#endif // LINKED_LIST
struct Node{
    const char *element;
    char *next;
    Node(const char *e = NULL, Node* n = NULL){
        element = e;
        next = n;
    }
};
struct SLinkedList{
    Node* head;
    long size;
    SLinkedList(){
        head = NULL;
        size = 0;
    }
    void addFirst();
    bool isEmpty();
    bool insertAfter(Node *node, char *element);
};
