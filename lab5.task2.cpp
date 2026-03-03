#include <iostream>
using namespace std;

struct Node {
    int rainfall;
    Node* prev;
    Node* next;
};

// Create node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->rainfall = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Display list
void displayList(Node* head) {
    Node* temp = head;
    int day = 1;
    while (temp) {
        cout << "Day " << day << ": " << temp->rainfall << " mm" << endl;
        temp = temp->next;
        day++;
    }
}

int main() {
    Node* head = NULL;
    int value;

    cout << "Enter rainfall for 7 days (no negative numbers):\n";
    for (int i = 0; i < 7; i++) {
        do {
            cout << "Day " << i + 1 << ": ";
            cin >> value;
            if (value < 0) cout << "Invalid input! Enter a non-negative number.\n";
        } while (value < 0);
        insertEnd(head, value);
    }

    // Display rainfall
    displayList(head);

    // Calculate total and average
    Node* temp = head;
    int total = 0;
    int maxRain = -1, minRain = 1000000;
    int dayMax = 0, dayMin = 0, dayCount = 1;
    while (temp) {
        total += temp->rainfall;
        if (temp->rainfall > maxRain) { maxRain = temp->rainfall; dayMax = dayCount; }
        if (temp->rainfall < minRain) { minRain = temp->rainfall; dayMin = dayCount; }
        temp = temp->next;
        dayCount++;
    }
    cout << "Total rainfall: " << total << " mm\n";
    cout << "Average rainfall: " << total / 7.0 << " mm\n";
    cout << "Highest rainfall on Day " << dayMax << ": " << maxRain << " mm\n";
    cout << "Lowest rainfall on Day " << dayMin << ": " << minRain << " mm\n";

    // Rainfall after 5th node
    temp = head;
    for (int i = 1; i <= 5; i++) temp = temp->next;
    if (temp) cout << "Rainfall on day after 5th node: " << temp->rainfall << " mm\n";
    else cout << "Less than 6 days entered.\n";

    return 0;
}
