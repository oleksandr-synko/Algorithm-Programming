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
	int a[n][n];
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			a[i][j] = rand() % 10;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	
	
	int maxG = a[0][0];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j){
				if(maxG < a[i][j]){
					maxG = a[i][j];
				}
			}
		}
	}
	
	int maxB = a[0][n-1];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i + j == n - 1){
				if(maxB < a[i][j]){
					maxB = a[i][j];
				}
			}
		}
	}
	cout << "Golovna max = " << maxG << endl;
	cout << "Bichna max = " << maxB << endl;
	int riz = maxG - maxB;
	cout << "Riznuca = " << riz;
	
	return 0;
}
