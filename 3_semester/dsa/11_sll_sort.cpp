#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};

void printLL(node* head)    
{
    node* current = head;
    while (current!=nullptr)    {
        cout<<current->data<<"  ";
        current = current->next;
    }
}

void sortLL(node* head)
{
    if (head == nullptr || head->next == nullptr)   {
        return;
    }

    int temp;
    bool swapped;

    do  {
        swapped = false;
        node *current = head;

        while (current->next!=nullptr)  {
            if (current->data > current->next->data)    {
                temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }

    }   while (swapped);
}

int main()
{
    node* head = new node {13,nullptr};
    node* n2 = new node {15,nullptr};
    node* n3 = new node {9,nullptr};
    node* n4 = new node {5,nullptr};
    node* n5 = new node {11,nullptr};

    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    sortLL(head);
    printLL(head);

    return 0;
}