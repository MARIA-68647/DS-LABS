#include <iostream>
using namespace std;


void swap(int *a, int *b) {
	
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
	
    int x = 8, y = 6;

    cout << "Before swapping:" << endl;
    cout << "NUM 1 = " << x << ", NUM 2 = " << y << endl;

    swap(&x, &y);   

    cout << "After swapping:" << endl;
    cout << "NUM 1 = " << x << ", NUM 2 = " << y << endl;

    return 0;
}

