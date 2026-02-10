#include <iostream>
#include <string>
using namespace std;

struct Product {
    string name;
    int code;
    float price;
};

int main() {
    int n;
    cout << "Enter number of products: ";
    cin >> n;

    Product* products = new Product[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details of product: " << i + 1 << endl;
        cout << "Name: ";
        cin >> products[i].name;
        cout << "Code: ";
        cin >> products[i].code;
        cout << "Price: ";
        cin >> products[i].price;
    }
    cout << "\n________________________________\n";
    cout << "\n**** Product List *****\n";
    for (int i = 0; i < n; i++) {
        cout << "Product " << i + 1 << ": ";
        cout << products[i].name << ", ";
        cout << products[i].code << ", ";
        cout << products[i].price << endl;
    }

delete[] products;
products = NULL;


    return 0;
}

