#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = newNode;  // Circular link to itself initially
    return newNode;
}

void insertEnd(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void deleteNode(Node*& head, int value) {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete.\n";
        return;
    }

    Node* current = head;
    Node* prev = nullptr;

    do {
        if (current->data == value) {
            if (prev == nullptr) {  // Deleting the head
                Node* lastNode = head;
                while (lastNode->next != head) {
                    lastNode = lastNode->next;
                }

                if (head == head->next) {  // Only one node in the list
                    delete head;
                    head = nullptr;
                } else {
                    lastNode->next = head->next;
                    delete head;
                    head = lastNode->next;
                }
                cout << value << " deleted from the list.\n";
                return;
            } else {
                prev->next = current->next;
                delete current;
                cout << value << " deleted from the list.\n";
                return;
            }
        }
        prev = current;
        current = current->next;
    } while (current != head);

    cout << value << " not found in the list.\n";
}

void displayList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    cout << "Singly Circular Linked List: ";
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int countNodes(Node* head) {
    if (head == nullptr) {
        return 0;
    }

    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}

bool searchNode(Node* head, int value) {
    if (head == nullptr) {
        return false;
    }

    Node* temp = head;
    do {
        if (temp->data == value) {
            return true;
        }
        temp = temp->next;
    } while (temp != head);

    return false;
}

int main() {
    Node* head = nullptr;
    int choice, value;
    insertEnd(head,12);
    insertEnd(head,21);
    insertEnd(head,37);
    displayList(head);
    do {
        cout << "1. Insert\t2. Delete\t3. Display\t4. Count\t5. Search\t0. Exit\nChoice: ";
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
            case 4:
                cout << "Number of nodes: " << countNodes(head) << endl;
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                if (searchNode(head, value)) {
                    cout << value << " found in the list.\n";
                } else {
                    cout << value << " not found in the list.\n";
                }
                break;
            default:
                cout << "Invalid choice. Please enter 0, 1, 2, 3, 4, or 5.\n";
        }
    } while (choice != 0);

    return 0;
}