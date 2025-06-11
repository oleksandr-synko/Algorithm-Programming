#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_SIZE = 100;

void inputArray(int arr[], int& n, bool random) {
    if (random) {
        int minVal, maxVal;
        cout << "Vedit rozmir masuvy: ";
        cin >> n;
        cout << "Vedit mi ta max znachenna: ";
        cin >> minVal >> maxVal;
        srand(time(0));
        for (int i = 0; i < n; i++){
            arr[i] = rand() % (maxVal - minVal + 1) + minVal;
        }
    }else{
        cout << "Vedit rozmir masuvy: ";
        cin >> n;
        cout << "Vedit elementu masuvy: ";
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
    }
}

void printArray(int arr[], int n, bool columnOutput) {
    cout << "Masuv:\n";
    for (int i = 0; i < n; i++) {
        if (columnOutput){
        	cout << arr[i] << endl;
		}else{
			cout << arr[i] << " ";
		}
    }
    cout << endl;
}

void DeletePovtorku(int arr[], int& n) {
    int minVal = arr[0], maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];  //Знаходження мінімального та максимального елемента
    }

    bool minFound = false, maxFound = false;
    int newArr[MAX_SIZE], j = 0;                //Створю новий масив без повторок
    for (int i = 0; i < n; i++){
        if(arr[i] == minVal && !minFound){
            newArr[j++] = arr[i];
            minFound = true;
        }else if (arr[i] == maxVal && !maxFound){
            newArr[j++] = arr[i];
            maxFound = true;
        }else if (arr[i] != minVal && arr[i] != maxVal){
            newArr[j++] = arr[i];
        }
    }

    for (int i = 0; i < j; i++){
        arr[i] = newArr[i];
    }
    n = j;
}

void ZsyvMinElementa(int arr[], int n){
    int minIdx = 0;
    for (int i = 1; i < n; i++){
        if (arr[i] < arr[minIdx]) minIdx = i;  //Пошук індекса мінімального елемента
    }
    int minVal = arr[minIdx];
    for (int i = minIdx; i > 0; i--){    //Зсув мінімального елемента
        arr[i] = arr[i - 1];
    }
    arr[0] = minVal;
}

void DeleteMigMaxMin(int arr[], int& n){
    int minIdx = 0, maxIdx = 0;
    for (int i = 1; i < n; i++){
        if (arr[i] < arr[minIdx]) minIdx = i;
        if (arr[i] > arr[maxIdx]) maxIdx = i;  //Знаходження мінімального та максимального елементів
    }

    int from = min(minIdx, maxIdx);
    int to = max(minIdx, maxIdx);    //Визначення меж видалення 

    int newArr[MAX_SIZE], j = 0;
    for (int i = 0; i < n; i++){
        if (i <= from || i >= to){   //Копіюю елементи які не знаходяться між from та to
            newArr[j++] = arr[i];
        }
    }
    for (int i = 0; i < j; i++){
        arr[i] = newArr[i];
    }
    n = j;
}

void ParAboNePar(int arr[], int n){
    int even[MAX_SIZE], odd[MAX_SIZE];  //Допоміжні масиви
    int evenCount = 0, oddCount = 0;  //Лічильники
    for (int i = 0; i < n; i++){
        if (arr[i] % 2 == 0)
            even[evenCount++] = arr[i];  //Парний 
        else
            odd[oddCount++] = arr[i];  //Не парний
    }

    if (oddCount > evenCount){
        cout << "Masuv z neparnux elementiv:\n";
        for (int i = 0; i < oddCount; i++) cout << odd[i] << " ";
    }else{
        cout << "Masuv z parnux elementiv:\n";
        for (int i = 0; i < evenCount; i++) cout << even[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[MAX_SIZE], n;
    char choice;
    cout << "Generyvatu vupadkovo? (y/n): ";
    cin >> choice;
    inputArray(arr, n, choice == 'y');
    cout << "Vuvodutu y stovpec? (y/n): ";
    cin >> choice;
    printArray(arr, n, choice == 'y');
    DeletePovtorku(arr, n);
    cout << "Pisla vudalenna min/max sho povtoryytsa:\n";
    printArray(arr, n, false);
    ZsyvMinElementa(arr, n);
    cout << "Pisla zsyvy min elemenya na pochatok:\n";
    printArray(arr, n, false);
    DeleteMigMaxMin(arr, n);
    cout << "Pisla vudalenna elementiv mig min/max:\n";
    printArray(arr, n, false);

    ParAboNePar(arr, n);

    return 0;
}
