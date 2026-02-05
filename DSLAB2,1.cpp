#include <iostream>
using namespace std;

int main() {
	
    int arr[5] = {15, 25, 30, 45, 55};
    
    int *p = arr;  

    cout << "Array elements are:" << endl;
    
    for (int i = 0; i < 5; i++) {
    	
        cout << *(p + i) << endl;
    }

    return 0;
}


