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
		a[i] = rand() % 50;
		cout << a[i] << " ";
	}
	cout << endl;
	
	int c = n;
	for(int i = 0; i < c; i++){
		if(a[i] % 5 == 0){
			n++;
			int sym = 0;
			for(int j = 0; j < i; j++){
				sym += a[j];
			}
			for(int j = c; j > i + 1; j--){
                a[j] = a[j - 1];
            }
            a[i + 1] = sym;
            c++;
            i++;
		}
	}
	
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	
	return 0;
}
