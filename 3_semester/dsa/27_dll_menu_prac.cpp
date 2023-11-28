#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void insertEnd(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void deleteNode(Node*& head, int value) {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete.\n";
        return;
    }
    Node* current = head;
    while (current != nullptr && current->data != value) {
        current = current->next;
    }
    if (current == nullptr) {
        cout << value << " not found in the list.\n";
        return;
    }
    if (current->prev != nullptr) {
        current->prev->next = current->next;
    }
    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }
    if (current == head) {
        head = head->next;
    }
    delete current;
    cout << value << " deleted from the list.\n";
}

void displayList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    cout << "Doubly Linked List: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int choice, value;
    insertEnd(head,12);
    insertEnd(head,18);
    insertEnd(head,13);
    displayList(head);
    do {
        cout << "1. Insert\t2. Delete\t3. Display\t0. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 0:
                break;
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insertEnd(head, value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteNode(head, value);
                break;
            case 3:
                displayList(head);
                break;
            default:
                cout << "Invalid choice. Please enter 0, 1, 2, or 3.\n";
        }
    } while (choice != 0);
    return 0;
}
