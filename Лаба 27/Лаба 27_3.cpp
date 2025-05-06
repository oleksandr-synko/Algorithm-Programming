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
	int b[n];
	int m = 0;
	for (int i = 0; i < n; ++i){
        int p = a[i];
        if (p % 2 == 0){
            int j = m - 1;
            while (j >= 0 && b[j] > a[i]){
                b[j + 1] = b[j];
                j--;
            }
            b[j + 1] = a[i];
            m++;
        }
    }
	cout << "Masuv de tilki elementu z parnoi ciloi chastunoi ta vidsortovani za zrostanam:\n ";
	for (int i = 0; i < m; ++i){
        cout << b[i] << " ";
    }
	
	delete[] a;
	delete[] b;
	return 0;
}
