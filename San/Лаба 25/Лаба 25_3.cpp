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
	cout << "Vedit rozmirnist masuva: ";
	cin >> n;
	cout << endl;
	int a[n];
	for(int i = 0; i < n; i++){
		a[i] = rand() % 10;
		cout << a[i] << " ";
	}
	cout << endl;
	int kil = 0;
	for(int i = 1; i < n; i++){
		if(a[i-1] < a[i]){
			cout << "Index de znaxodutsa chuslo bilshe vid svogo sysida zliva: " << i << endl;
			kil++;
		}
	}
	cout << "\nKilkist takux chusel: " << kil;
	
	return 0;
}
