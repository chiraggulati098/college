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

void insert_end(node* head, int x)
{
    node* newNode = new node{x,nullptr};
    struct node* current = head;
    while (current->next!=nullptr)  {
        current = current->next;
    }
    current->next = newNode;
}

int main()
{  
    node* head = new node {1,nullptr};
    node* n2 = new node {2,nullptr};
    node* n3 = new node {3,nullptr};

    head->next = n2;
    n2->next = n3;

    insert_end(head,4);
    printLinkedList(head);

    cout<<endl;
    return 0;
}