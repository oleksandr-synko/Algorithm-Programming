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
	
	cout << "Peretvorena matrix: " << endl;
	for(int i = 0; i < n; i++){
		if(i % 2 == 0){
			for(int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		}else{
			for(int j = n - 1; j >= 0; j--){
				cout << a[i][j] << " ";
			}
		}
		cout << endl;
	}
	
	
	return 0;
}
