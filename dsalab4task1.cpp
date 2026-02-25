#include <iostream>
using namespace std;

struct Mobile
{
    string brand;
    int units;
    float price;
    Mobile* next;
};

Mobile* head = NULL;

// Add Mobile
void addMobile()
{
    Mobile* newNode = new Mobile;

    cout << "Enter Brand Name: ";
    cin >> newNode->brand;
    cout << "Enter Units in Stock: ";
    cin >> newNode->units;
    cout << "Enter Price: ";
    cin >> newNode->price;

    newNode->next = NULL;

    if(head == NULL)
        head = newNode;
    else
    {
        Mobile* temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    cout << "Mobile Added Successfully!\n";
}

// Delete Mobile
void deleteMobile()
{
    if(head == NULL)
    {
        cout << "Inventory Empty!\n";
        return;
    }

    string brand;
    cout << "Enter Brand to Delete: ";
    cin >> brand;

    Mobile* temp = head;
    Mobile* prev = NULL;

    while(temp != NULL && temp->brand != brand)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        cout << "Mobile Not Found!\n";
        return;
    }

    if(prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    delete temp;
    cout << "Mobile Deleted Successfully!\n";
}

// Display Mobiles
void displayMobiles()
{
    if(head == NULL)
    {
        cout << "No Mobiles Available!\n";
        return;
    }

    Mobile* temp = head;
    while(temp != NULL)
    {
        cout << "Brand: " << temp->brand
             << " | Units: " << temp->units
             << " | Price: " << temp->price << endl;

        temp = temp->next;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n1. Add Mobile\n";
        cout << "2. Delete Mobile\n";
        cout << "3. Display Mobiles\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: addMobile(); break;
            case 2: deleteMobile(); break;
            case 3: displayMobiles(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid Choice!\n";
        }

    } while(choice != 4);

    return 0;
}
