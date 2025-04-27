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
		a[i] = rand() % 21-10;
		cout << a[i] << " ";
	}
	cout << endl;
	int kil = 0;
	for(int i = 0; i < n; i++){
		if(a[i] < 0){
			cout << "index chusla menshe za 0: " << i << endl;
			kil++;
		}
	}
	cout << "Takux elementiv v masuvi: " << kil;
	
	return 0;
}
