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
	cout << "Vedit rozmirnist masuvy: ";
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		a[i] = rand() % 6 - 2;
		cout << a[i] << " ";
	}
	cout << endl;
	
	int New = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < 0 && i > 0) New++;
    }
	int b[n + New];//Новий масив з урахуванням вставок
	int bI = 0;
	for (int i = 0; i < n; ++i){
		if (a[i] < 0 && i > 0){
			int minVal = a[0];
            int maxVal = a[0];
            for (int j = 1; j < i; ++j){
            	if (a[j] < minVal) minVal = a[j];
                if (a[j] > maxVal) maxVal = a[j];
			}
			b[bI++] = minVal + maxVal;
		}
		b[bI++] = a[i];
	}
	
	cout << "Rezyltat:\n";
    for (int i = 0; i < bI; ++i){
        cout << b[i] << " ";
    }
    cout << endl;
	return 0;
}
