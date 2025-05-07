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
	
	int sum = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			sum += a[i][j];
		}
	}
	int ser = sum / (n * n);
	cout << "Seredne: " << ser << endl;
	int MenZaSer = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[i][j] < ser) MenZaSer++;
		}
	}
	cout << "Chusel menshux za seredne: " << MenZaSer;
	
	ofstream fout("Rezultat28_1.txt");
	fout << "Seredne: " << ser << endl;
	fout << "Kilkist chusel menshux za seredne: " << MenZaSer;
	fout.close();
	
	for (int i = 0; i < n; ++i)
        delete[] a[i];
    delete[] a;
	
	return 0;
}
