// WAP to perform Creation, Counting, Insertion and Deletion in LL

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void displayLL(Node* head)
{
    if (head == nullptr)    {
        cout<<"List is Empty";
        return;
    }
    Node* temp = head;
    while (temp!=nullptr)   {
        cout<<temp->data<<"  ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* createNode(int value) 
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void insertEnd(Node*& head, int value) 
{
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteNode(Node*& head, int value) 
{
    if (head == nullptr) {
        cout << "List is empty, can't del\n";
        return;
    }
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* current = head;
    Node* prev = nullptr;
    while (current != nullptr && current->data != value) {
        prev = current;
        current = current->next;
    }
    if (current == nullptr) {
        cout << value << " not found in the list.\n";
        return;
    }
    prev->next = current->next;
    delete current;
}

void countNodes(Node* head) 
{
    Node* current = head;
    int count = 0;
    while (current!=nullptr)   {
        count+=1;
        current = current->next;
    }
    cout<<"Number of Nodes: "<<count<<endl;
}

int main()
{
    Node* head = nullptr;
    insertEnd(head,5);
    insertEnd(head,12);
    insertEnd(head,23);

    int choice;
    while (true)    {
        displayLL(head);
        cout<<"1. Insert   2. Deletion   3. Counting   0. Exit\nchoose:";
        cin>>choice;
        switch(choice)  {
            case 0: {
                displayLL(head);
                return 0;
            }
            case 1: {
                int x;
                cout<<"enter value to insert: ";
                cin>>x;
                insertEnd(head,x);
                break;
            }
            case 2: { 
                int y;
                cout<<"enter value to delete: ";
                cin>>y;
                deleteNode(head,y);
                break;
            }
            case 3: {
                countNodes(head);
                break;
            }
            default:    {
                cout<<"enter 0,1,2 or 3"<<endl;
            }
        }
    }
    return 0;
}