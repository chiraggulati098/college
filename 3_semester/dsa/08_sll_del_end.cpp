#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};

void printLinkedList(node* head)
{
    node* temp = head;
    while (temp!=nullptr)   {
        cout<<temp->data<<"   ";
        temp = temp->next;
    }
}

int main()
{   
    node* n3 = new node {3,nullptr};
    node* n2 = new node {2,n3};
    node* head = new node {1,n2};

    cout<<"original linked list:   ";
    printLinkedList(head);
    cout<<endl;

    struct node* temp = head;
    while (temp->next->next!=nullptr)   {
        temp = temp->next;
    }
    temp->next = nullptr;

    cout<<"updated linked list:   ";
    printLinkedList(head);

    cout<<endl;
    return 0;
}