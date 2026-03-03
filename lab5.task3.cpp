#include <iostream>
#include <string>
using namespace std;

struct Player {
    string name;
    int score;
    Player* prev;
    Player* next;
};

// Create node
Player* createPlayer(string name, int score) {
    Player* newPlayer = new Player();
    newPlayer->name = name;
    newPlayer->score = score;
    newPlayer->prev = NULL;
    newPlayer->next = NULL;
    return newPlayer;
}

// Insert in sorted order (ascending by score)
void addPlayer(Player*& head, string name, int score) {
    Player* newPlayer = createPlayer(name, score);
    if (!head || score < head->score) {
        newPlayer->next = head;
        if (head) head->prev = newPlayer;
        head = newPlayer;
        return;
    }
    Player* temp = head;
    while (temp->next && temp->next->score <= score) temp = temp->next;
    newPlayer->next = temp->next;
    if (temp->next) temp->next->prev = newPlayer;
    newPlayer->prev = temp;
    temp->next = newPlayer;
}

// Delete player by name
void deletePlayer(Player*& head, string name) {
    Player* temp = head;
    while (temp && temp->name != name) temp = temp->next;
    if (!temp) { cout << "Player not found.\n"; return; }
    if (temp->prev) temp->prev->next = temp->next;
    else head = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    delete temp;
    cout << "Player deleted.\n";
}

// Display all players
void displayAll(Player* head) {
    Player* temp = head;
    cout << "Players list:\n";
    while (temp) {
        cout << temp->name << " - " << temp->score << endl;
        temp = temp->next;
    }
}

// Display player with lowest score
void displayLowest(Player* head) {
    if (!head) return;
    cout << "Lowest score: " << head->name << " - " << head->score << endl;
}

// Display players with same score
void displaySameScore(Player* head, int score) {
    Player* temp = head;
    bool found = false;
    while (temp) {
        if (temp->score == score) {
            cout << temp->name << " ";
            found = true;
        }
        temp = temp->next;
    }
    if (!found) cout << "No player with score " << score << endl;
    else cout << "have score " << score << endl;
}

// Display backward from a player
void displayBackwardFrom(Player* head, string name) {
    Player* temp = head;
    while (temp && temp->name != name) temp = temp->next;
    if (!temp) { cout << "Player not found.\n"; return; }
    cout << "Backward from " << name << ": ";
    while (temp) {
        cout << temp->name << "(" << temp->score << ") ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    Player* head =NULL;
    int choice;
    string name;
    int score;

    do {
        cout << "\n1.Add Player\n2.Delete Player\n3.Display All\n4.Display Lowest Score\n5.Display Same Score\n6.Display Backward From Player\n0.Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter name: "; cin >> name;
                cout << "Enter score: "; cin >> score;
                addPlayer(head, name, score);
                break;
            case 2:
                cout << "Enter name to delete: "; cin >> name;
                deletePlayer(head, name);
                break;
            case 3:
                displayAll(head);
                break;
            case 4:
                displayLowest(head);
                break;
            case 5:
                cout << "Enter score to search: "; cin >> score;
                displaySameScore(head, score);
                break;
            case 6:
                cout << "Enter player name: "; cin >> name;
                displayBackwardFrom(head, name);
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
