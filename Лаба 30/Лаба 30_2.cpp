#include <iostream>

using namespace std;

double formula(double length, double width = 1, double height = 1) {
    double area;
    area = 2 * (length * width + width * height + height * length);
    return area;
}

int main(){
    double a, b, c;

    a = 2;
    cout << "Plosha poverxni kolu dovguna 2, shuruna ta vusota 1: ";  //Відомо тільки довгину
    cout << formula(a) << endl;

    a = 2;
    b = 3;
    cout << "Plosha poverxni kolu dovguna 2, shuruna 3, vusota 1: ";  //Відомо тільки довгину та ширину
    cout << formula(a, b) << endl;

    a = 2;
    b = 3;
    c = 4;
    cout << "Plosha poverxni kolu dovguna 2, shuruna 3, vusota 4: ";  //Відомо все
    cout << formula(a, b, c) << endl;

    return 0;
}

