#include <iostream>
#include <conio.h>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main(){
	srand(time(NULL));
	int n;
	cout << "Vedit rozmirnist masuvy: ";
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		a[i] = rand() % 10;
		cout << a[i] << " ";
	}
	cout << endl;
	int m = 0;
    for (int i = 0; i < n; ++i) {
        if ((i + 1) % 2 == 1 && a[i] % 2 == 0) {
            m++;
        }
    }  
	int b[m];
    int index = 0;
    for (int i = 0; i < n; ++i) {
        if ((i + 1) % 2 == 1 && a[i] % 2 == 0) {
            b[index++] = a[i];
        }
    }
	for(int i = 0; i < m; i++){
		cout << b[i] << " ";
	}
	
	delete[] a;
	delete[] b;
	return 0;
}
