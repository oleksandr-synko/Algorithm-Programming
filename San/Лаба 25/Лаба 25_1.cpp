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
		a[i] = rand() % 101 - 50;
		cout << a[i] << " ";
	}
	int min = a[0];
	for(int i = 0; i < n; i++){
		if(a[i] % 2 == 0){
			if(min > a[i]){
				min = a[i];
			}
		}
	}
	
	cout << "Minimalmui element parnui: " << min;
	
	return 0;
}
