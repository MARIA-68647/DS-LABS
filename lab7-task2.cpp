#include <iostream>
using namespace std;

class Inventory {
public:
    int serialNum;
    int manufactYear;
    int lotNum;
    Inventory* next;

    Inventory(int s, int y, int l) {
        serialNum = s; manufactYear = y; lotNum = l;
        next = NULL;
    }
};

class InventoryStack {
    Inventory* top;
public:
    InventoryStack() { top = NULL; }

    void push(int s, int y, int l) {
        Inventory* newNode = new Inventory(s, y, l);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (!top) { cout << "Inventory empty.\n"; return; }
        cout << "Removing Part #" << top->serialNum << " (Year: " << top->manufactYear << ")\n";
        Inventory* temp = top;
        top = top->next;
        delete temp;
    }

    void displayAll() {
        Inventory* temp = top;
        while (temp) {
            cout << "Serial: " << temp->serialNum << ", Year: " << temp->manufactYear << ", Lot: " << temp->lotNum << endl;
            temp = temp->next;
        }
    }
};

int main() {
    InventoryStack stack;
    int choice, s, y, l;

    do {
        cout << "\n1. Add Part\n2. Take Part\n3. Finish\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Serial, Year, Lot: ";
            cin >> s >> y >> l;
            stack.push(s, y, l); // [cite: 322]
        } else if (choice == 2) {
            stack.pop(); // [cite: 323]
        }
    } while (choice != 3); // [cite: 321]

    cout << "\nRemaining Inventory:\n";
    stack.displayAll(); // [cite: 324]
    return 0;
}
