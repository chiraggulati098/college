#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
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
    }
}

void displayList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    cout << "Linked List: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* mergeLists(Node* list1, Node* list2) {
    Node* mergedList = nullptr;
    Node* current = nullptr;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data < list2->data) {
            if (mergedList == nullptr) {
                mergedList = current = list1;
            } else {
                current->next = list1;
                current = current->next;
            }
            list1 = list1->next;
        } else {
            if (mergedList == nullptr) {
                mergedList = current = list2;
            } else {
                current->next = list2;
                current = current->next;
            }
            list2 = list2->next;
        }
    }

    if (list1 != nullptr) {
        current->next = list1;
    }

    if (list2 != nullptr) {
        current->next = list2;
    }

    return mergedList;
}

Node* unionLists(Node* list1, Node* list2) {
    Node* result = nullptr;
    Node* current = nullptr;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data < list2->data) {
            if (result == nullptr || current->data != list1->data) {
                Node* newNode = createNode(list1->data);
                if (result == nullptr) {
                    result = current = newNode;
                } else {
                    current->next = newNode;
                    current = current->next;
                }
            }
            list1 = list1->next;
        } else if (list1->data > list2->data) {
            if (result == nullptr || current->data != list2->data) {
                Node* newNode = createNode(list2->data);
                if (result == nullptr) {
                    result = current = newNode;
                } else {
                    current->next = newNode;
                    current = current->next;
                }
            }
            list2 = list2->next;
        } else {
            if (result == nullptr || current->data != list1->data) {
                Node* newNode = createNode(list1->data);
                if (result == nullptr) {
                    result = current = newNode;
                } else {
                    current->next = newNode;
                    current = current->next;
                }
            }
            list1 = list1->next;
            list2 = list2->next;
        }
    }

    while (list1 != nullptr) {
        if (result == nullptr || current->data != list1->data) {
            Node* newNode = createNode(list1->data);
            if (result == nullptr) {
                result = current = newNode;
            } else {
                current->next = newNode;
                current = current->next;
            }
        }
        list1 = list1->next;
    }

    while (list2 != nullptr) {
        if (result == nullptr || current->data != list2->data) {
            Node* newNode = createNode(list2->data);
            if (result == nullptr) {
                result = current = newNode;
            } else {
                current->next = newNode;
                current = current->next;
            }
        }
        list2 = list2->next;
    }

    return result;
}

Node* intersectionLists(Node* list1, Node* list2) {
    Node* result = nullptr;
    Node* current = nullptr;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data < list2->data) {
            list1 = list1->next;
        } else if (list1->data > list2->data) {
            list2 = list2->next;
        } else {
            if (result == nullptr || current->data != list1->data) {
                Node* newNode = createNode(list1->data);
                if (result == nullptr) {
                    result = current = newNode;
                } else {
                    current->next = newNode;
                    current = current->next;
                }
            }
            list1 = list1->next;
            list2 = list2->next;
        }
    }

    return result;
}

int main() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;

    insertEnd(list1, 1);
    insertEnd(list1, 3);
    insertEnd(list1, 5);

    insertEnd(list2, 2);
    insertEnd(list2, 3);
    insertEnd(list2, 4);

    int choice;

    do {
        cout << "1. Display Lists\t2. Merge Lists\t3. Union Lists\t4. Intersection Lists\t0. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 0:
                break;
            case 1:
                cout << "List 1: ";
                displayList(list1);
                cout << "List 2: ";
                displayList(list2);
                break;
            case 2:
                cout << "Merged List: ";
                displayList(mergeLists(list1, list2));
                break;
            case 3:
                cout << "Union List: ";
                displayList(unionLists(list1, list2));
                break;
            case 4:
                cout << "Intersection List: ";
                displayList(intersectionLists(list1, list2));
                break;
            default:
                cout << "Invalid choice. Please enter 0, 1, 2, 3, or 4.\n";
        }
    } while (choice != 0);

    return 0;
}