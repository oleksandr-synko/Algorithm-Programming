#include <iostream>
#include <conio.h>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

void sort(int* a, int n){
	for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if (a[i] < a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}

int main(){
	srand(time(NULL));
	int n;
	cout << "Vedit rozmirnist matrix: ";
	cin >> n;
	int a[n][n];
	cout << "Pochatkovui masuv:\n"; 
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			a[i][j] = rand() % 900 + 100;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Vidsortovanui masuv:\n ";
	for(int i = 0; i < n; ++i)
	sort(a[i], n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << a[i][j] << " ";
		}
			cout << endl;
	}
	
	ofstream fout("Rezultat 28_3.txt");
	fout << "Vidsortovana matrica:\n";
	for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            fout << a[i][j] << " ";
        fout << endl;
    }
    fout.close();
    
    for (int i = 0; i < n; ++i)
    delete[] a[i];
    delete[] a;
	
	return 0;
}
