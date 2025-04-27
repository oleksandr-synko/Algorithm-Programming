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
	cout << "Vedit rozmirnist matrix: ";
	cin >> n;

	double a[n][n];

	
	cout << "Pochatkova matryx:\n";
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			a[i][j] = rand() % 10;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	for(int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i][i] > a[j][j]) {
				double t = a[i][i];
				a[i][i] = a[j][j];
				a[j][j] = t;
			}
		}
	}

	cout << "\nVidsortovana matrix:\n";
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

