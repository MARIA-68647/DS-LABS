#include <iostream>
using namespace std;

struct User
{
    int id;
    string name;
    int age;
    User* next;
};

User* head = NULL;

// Create Profile
void createProfile()
{
    User* newNode = new User;

    cout << "Enter ID: ";
    cin >> newNode->id;
    cout << "Enter Name: ";
    cin >> newNode->name;
    cout << "Enter Age: ";
    cin >> newNode->age;

    newNode->next = head;
    head = newNode;

    cout << "Profile Created Successfully!\n";
}

// Search Profile
User* searchProfile(int id)
{
    User* temp = head;
    while(temp != NULL)
    {
        if(temp->id == id)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

// Update Profile
void updateProfile()
{
    int id;
    cout << "Enter ID to Update: ";
    cin >> id;

    User* user = searchProfile(id);

    if(user == NULL)
    {
        cout << "Profile Not Found!\n";
        return;
    }

    cout << "Enter New Name: ";
    cin >> user->name;
    cout << "Enter New Age: ";
    cin >> user->age;

    cout << "Profile Updated Successfully!\n";
}

// Delete Profile
void deleteProfile()
{
    int id;
    cout << "Enter ID to Delete: ";
    cin >> id;

    User* temp = head;
    User* prev = NULL;

    while(temp != NULL && temp->id != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
    {
        cout << "Profile Not Found!\n";
        return;
    }

    if(prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    delete temp;
    cout << "Profile Deleted Successfully!\n";
}

// View All Profiles
void viewProfiles()
{
    User* temp = head;
    if(temp == NULL)
    {
        cout << "No Profiles Available!\n";
        return;
    }

    while(temp != NULL)
    {
        cout << "ID: " << temp->id
             << " | Name: " << temp->name
             << " | Age: " << temp->age << endl;

        temp = temp->next;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n1. Create Profile\n";
        cout << "2. Update Profile\n";
        cout << "3. Delete Profile\n";
        cout << "4. Search Profile\n";
        cout << "5. View All Profiles\n";
        cout << "6. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: createProfile(); break;
            case 2: updateProfile(); break;
            case 3: deleteProfile(); break;
            case 4:
            {
                int id;
                cout << "Enter ID to Search: ";
                cin >> id;
                User* user = searchProfile(id);
                if(user)
                    cout << "Found: " << user->name << endl;
                else
                    cout << "Profile Not Found!\n";
                break;
            }
            case 5: viewProfiles(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid Choice!\n";
        }

    } while(choice != 6);

    return 0;
}
