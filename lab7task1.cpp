#include <iostream>
#include <string>
using namespace std;

class BookNode {
public:
    string title;
    float price;
    int edition;
    int pages;
    BookNode* next;

    BookNode(string t, float p, int e, int pg) {
        title = t; price = p; edition = e; pages = pg;
        next = NULL;
    }
};

class BookStack {
    BookNode* top;
public:
    BookStack() { top = NULL; }

    void push(string t, float p, int e, int pg) {
        BookNode* temp = new BookNode(t, p, e, pg);
        temp->next = top;
        top = temp;
    }

    void pop() {
        if (!top) { cout << "Stack Underflow\n"; return; }
        BookNode* temp = top;
        top = top->next;
        delete temp;
    }

    void peek() {
        if (!top) { cout << "Stack is empty\n"; return; }
        cout << "Top Book: " << top->title << " (Edition: " << top->edition << ")\n";
    }

    void display() {
        BookNode* temp = top;
        while (temp) {
            cout << "Title: " << temp->title << " | Pages: " << temp->pages << endl;
            temp = temp->next;
        }
    }
};

int main() {
    BookStack s;
    // 1. Push 5 books [cite: 312]
    s.push("Data Structures", 500, 1, 300);
    s.push("C++ Basics", 400, 2, 250);
    s.push("Java Guide", 600, 3, 400);
    s.push("Python Tips", 450, 1, 150);
    s.push("AI Intro", 700, 4, 500);

    // 2. Find top element [cite: 313]
    s.peek();

    // 3. Pop 2 books [cite: 313]
    s.pop();
    s.pop();

    // 4. Display remaining [cite: 314]
    cout << "\nRemaining Books:\n";
    s.display();
    return 0;
}
