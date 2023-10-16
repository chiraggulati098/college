#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};

void printLinkedList(node* head)
{
    node* current = head;
    while (current!=nullptr)    {
        cout<<current->data<<"   ";
        current = current->next;
    }
}

node* insert_beginning(node* head, int x)
{
    node* newNode = new node{x,head};
    head = newNode;
    return head;
}

int main()
{  
    node* head = new node {1,nullptr};
    node* n2 = new node {2,nullptr};
    node* n3 = new node {3,nullptr};

    head->next = n2;
    n2->next = n3;

    head = insert_beginning(head,0);
    printLinkedList(head);

    cout<<endl;
    return 0;
}