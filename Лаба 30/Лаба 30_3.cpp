#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
	srand(time(0));
    int a[12] = {13, 4, 2, 28, 34, 7, 10, 21, 43, 50, 37, 11};
    int n = 8;
    int b[n];
    for (int i = 0; i < n; i++) {
        int randI = rand() % 12;  // випадковий індекс від 0 до 11
        b[i] = a[randI];
    }
    cout << "New masuv b: ";
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    return 0;
}


