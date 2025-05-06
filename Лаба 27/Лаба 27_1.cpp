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
	cout << "Vedit rozmirnist masuviv: ";
	cin >> n;
	int m = n;
	int a[n], b[m];
	
	cout << "Masuv a[" << n << "]: ";
	for(int i = 0; i < n; i++){
		a[i] = rand() % 100;
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "Masuv b[" << m << "]: ";
	for(int i = 0; i < m; i++){
		b[i] = rand() % 100;
		cout << b[i] << " ";
	}
	cout << endl;
	int aI = 0, bI = 0;
	for(int i = 0; i < n; i++){
		if(a[i] % 3 == 0){
			aI++;
		}
	}
	for(int i = 0; i < m; i++){
		if(b[i] % 3 == 0){
			bI++;
		}
	}
	if(aI > bI){
		for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	}else if(aI < bI){
		for(int i = 0; i < n; i++){
		cout << b[i] << " ";
	}
	}else if(aI == bI){
		cout << "Y dvox masuvax ix odnakovo";
	}
	
	delete[] a;
	delete[] b;

	return 0;
}
