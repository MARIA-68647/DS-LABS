#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void addAtBeginning(Node*& head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    if (head != NULL) head->prev = newNode;
    head = newNode;
}

// Insert after node with value 45
void addAfterValue(Node*& head, int valueToInsert, int targetValue) {
    Node* temp = head;
    while (temp != NULL && temp->data != targetValue) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Value " << targetValue << " not found.\n";
        return;
    }
    Node* newNode = createNode(valueToInsert);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) temp->next->prev = newNode;
    temp->next = newNode;
}

// Delete at beginning
void deleteAtBeginning(Node*& head) {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    delete temp;
}

// Delete after node with value 45
void deleteAfterValue(Node*& head, int targetValue) {
    Node* temp = head;
    while (temp != NULL && temp->data != targetValue) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        cout << "No node exists after value " << targetValue << ".\n";
        return;
    }
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    if (nodeToDelete->next != NULL) nodeToDelete->next->prev = temp;
    delete nodeToDelete;
}

// Display the list
void displayList(Node* head) {
    Node* temp = head;
    cout << "Doubly Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    int n, value;

    cout << "Enter number of marks to input: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter mark " << i + 1 << ": ";
        cin >> value;
        addAtBeginning(head, value); // Initial insert at beginning
    }

    displayList(head);

    // Add at beginning
    cout << "Adding 100 at beginning...\n";
    addAtBeginning(head, 100);
    displayList(head);

    // Add after 45
    cout << "Adding 90 after 45...\n";
    addAfterValue(head, 90, 45);
    displayList(head);

    // Delete at beginning
    cout << "Deleting node at beginning...\n";
    deleteAtBeginning(head);
    displayList(head);

    // Delete after 45
    cout << "Deleting node after 45...\n";
    deleteAfterValue(head, 45);
    displayList(head);

    return 0;
}
