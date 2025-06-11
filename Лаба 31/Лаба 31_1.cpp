#include <iostream>
#include <string>
#include <vector>
#include <limits> //Для cin.ignore()

using namespace std;

class flat {
private:
    string adresa;
    int poverx;
    int room;
    double plosha;

public:
    flat() {  //Конструктор за замовчуванням
        adresa = "Nevidoma adresa";
        poverx = 1;
        room = 2;
        plosha = 55.0;
        cout << "Stvoreno kvarturu za zamovchuvannyam\n";
    }

    flat(string addr, int fl) {  //Параматрезований конструктор
        adresa = addr;
        poverx = fl;
        room = 2;
        plosha = 55.0;
        cout << "Stvoreno kvarturu z parametramy\n";
    }

    ~flat() {
        cout << "Znyshcheno kvarturu: " << adresa << endl;
    }

    //Метод для введення даних
    void input() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очищення буфера
        cout << "Vvedit adresu: ";
        getline(cin, adresa);
        cout << "Vvedit poverx: ";
        cin >> poverx;
        cout << "Vvedit kilkist kimnat: ";
        cin >> room;
        cout << "Vvedit ploshchu: ";
        cin >> plosha;
    }

    //Для виведення даних
    void output() const {
        cout << "Adresa: " << adresa << ", poverx: " << poverx
             << ", kilkist kimnat: " << room << ", plosha: "
             << plosha << " m2" << endl;
    }

    //Гетери
    int getRoom() const { return room; }
    double getPlosha() const { return plosha; }
    int getPoverx() const { return poverx; }
};

void filterRoom(const vector<flat>& flats, int roomCount) {
    cout << "\nKvartury z " << roomCount << " kimnatamy:\n";
    for (size_t i = 0; i < flats.size(); ++i) {
        if (flats[i].getRoom() == roomCount) {
            flats[i].output();
        }
    }
}

void filterPlosha(const vector<flat>& flats, double maxArea, int minFloor, int maxFloor) {
    cout << "\nKvartury z ploshcheyu do " << maxArea << " m2 i poverxamy vid "
         << minFloor << " do " << maxFloor << ":\n";
    for (size_t i = 0; i < flats.size(); ++i) {
        if (flats[i].getPlosha() <= maxArea &&
            flats[i].getPoverx() >= minFloor &&
            flats[i].getPoverx() <= maxFloor) {
            flats[i].output();
        }
    }
}

int main() {
    const int size = 3;
    vector<flat> flats;

    flat flat1("vul. Rivnenska 12A", 3);
    flat flat2;

    flats.push_back(flat1);
    flats.push_back(flat2);

    flat flat3;
    cout << "\nVvedennya danykh dlya 3-yi kvartury(adresa, poverx, kilkist kimnat, plosha):\n";
    flat3.input();
    flats.push_back(flat3);

    filterRoom(flats, 2);
    filterPlosha(flats, 40.0, 2, 5);

    return 0;
}
