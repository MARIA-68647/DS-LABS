#include <iostream>
using namespace std;

int main() {
    int arr[3] = {10, 20, 30};
    int index, value;

    cout << "Enter index to update: ";
    cin >> index;

    cout << "Enter new value: ";
    cin >> value;

    arr[index] = value;

    cout << "Updated array: ";
    for (int i = 0; i < 3; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}


