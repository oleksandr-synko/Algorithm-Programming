#include <iostream>

using namespace std;

void fec(int a[], int indexes[], int kilI){
    cout << "Vubrani elementu: ";
    for (int i = 0; i < kilI; i++){
        int index = indexes[i];
        cout << a[index] << " ";
    }
    cout << endl;
}

int main() {
    int a[12] = {13, 4, 2, 28, 34, 7, 10, 21, 43, 50, 37, 11};

    int indexes[] = {4, 10};
    int kilI = 2;

    fec(a, indexes, kilI);

    return 0;
}

