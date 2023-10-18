#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next,*prev;
};

node* createNode(int value)
{
    node* newNode = new node;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void displayLL(node* head) 
{
    node* current = head;
    while (current != nullptr)  {
        cout<<current->data<<"  ";
        current = current->next;
    }
}

int main()
{
    int num_nodes;

    cout<<"enter number of nodes: ";
    cin>> num_nodes;
    cout<<endl;

    node* head = nullptr;
    node* tail = nullptr;

    for (int i=0;i<num_nodes;i++)   {
        int value;
        cout<<"enter value for node "<<i+1<<": ";
        cin>>value;

        node* new_node = createNode(value);

        if (head == nullptr)    {
            head = new_node;
            tail = new_node;
        }   else    {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }

    displayLL(head);

    return 0;
}