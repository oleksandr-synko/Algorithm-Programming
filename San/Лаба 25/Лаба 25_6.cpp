#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    srand(time(NULL));
    int n;
    cout << "Vedit rozmirnist masuva: ";
    cin >> n;
    cout << endl;
    int a[n];
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 10;
        cout << a[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i += 2){
        for(int j = i + 2; j < n; j += 2){
            if (a[i] > a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    for(int i = 1; i < n; i += 2){
        for(int j = i + 2; j < n; j += 2){
            if (a[i] < a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

