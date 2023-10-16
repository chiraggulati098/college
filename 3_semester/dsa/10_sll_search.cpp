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

bool search(node* head, int x)   
{
    struct node* temp = head;
    while (temp!=nullptr)   {
        if (temp->data == x)    {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main()
{   
    node* n3 = new node {3,nullptr};
    node* n2 = new node {2,n3};
    node* head = new node {1,n2};

    cout<<"original linked list:   ";
    printLinkedList(head);
    cout<<endl;

    bool answer = search(head,2);
    cout<<answer;

    cout<<endl;
    return 0;
}