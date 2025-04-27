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
	double a[n][n];
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			a[i][j] = rand() % 21 - 10;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	
	double plus = 0, plusI = 0, minys = 0, minysI = 0, nyl = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[i][j] > 0){
				plus += a[i][j];
				plusI++;
			}else if(a[i][j] < 0){
				minys += a[i][j];
				minysI++;
			}else{
				nyl++;
			}
		}
	}
	cout << "Syma dodatnix: " << plus << endl << "Syma videmnux: " << minys << endl << endl;
	cout << "Seredne dodatnix: " << plus / plusI << endl << "Seredne videmnux: " << minys / minysI << endl << "Kilkist nyliv: " << nyl;
	
	return 0;
}
