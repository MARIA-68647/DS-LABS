#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int key, index = -1;

    cout << "Enter element to search: ";
    cin >> key;

    for (int i = 0; i < 5; i++) {
        if (arr[i] == key) {
            index = i;
            break;
        }
    }

    if (index != -1)
        cout << "Element found at index: " << index;
    else
        cout << "Element not found";
/*
#include <stdio.h>

int main() {
    int arr[100], n, index, value, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter index to update: ");
    scanf("%d", &index);

    printf("Enter new value: ");
    scanf("%d", &value);

    if (index >= 0 && index < n) {
        arr[index] = value;
    } else {
        printf("Invalid index\n");
        return 0;
    }

    printf("Updated array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
*/
    return 0;
}

  
