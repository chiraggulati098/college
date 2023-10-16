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

void insert(node* head, int x, int pos)
{
    struct node* current = head;
    for (int i = 1; i<pos-1;i++) {
        current = current->next;
    }
    node* newNode = new node{x,current->next};
    current->next = newNode;

}

int main()
{  
    node* head = new node {1,nullptr};
    node* n2 = new node {2,nullptr};
    node* n3 = new node {3,nullptr};

    head->next = n2;
    n2->next = n3;

    insert(head,4,2);
    printLinkedList(head);

    cout<<endl;
    return 0;
}