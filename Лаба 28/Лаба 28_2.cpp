#include <iostream>
#include <conio.h>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

bool per(int** a, int n, int col){
    for (int i = 0; i < n - 1; ++i)
        if (a[i][col] < a[i + 1][col])
            return false;
    return true;
}

int main(){
	srand(time(NULL));
	int n;
	cout << "Vedit rozmirnist matrix: ";
	cin >> n;
	int** a = new int*[n];
    for (int i = 0; i < n; ++i)
    a[i] = new int[n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			a[i][j] = rand() % 10;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	
	int kil = 0;
    for (int j = 0; j < n; ++j) {
        if (per(a, n, j)){
            kil++;
        }
    }
	
	cout << "Kilkist stovpciv de elementu za spadannam: " << kil;
	
	for (int i = 0; i < n; ++i)
    delete[] a[i];
    delete[] a; 
	
	return 0;
}
