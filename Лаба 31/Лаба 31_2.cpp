#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class People {
private:
    string prizvyshche;
    string kraina;
    string stat;
    string osvita;
    int rikNar;
    int vik;

public:
    People() {
        prizvyshche = "Nevidomo";
        kraina = "Ukraina";
        stat = "Nevidoma";
        osvita = "Srednya";
        rikNar = 2006;
        obchyslytyVik();
        cout << "Stvoreno osoby za zamovchuvannyam\n";
    }

    People(const People& other) {
        prizvyshche = other.prizvyshche;
        kraina = other.kraina;
        stat = other.stat;
        osvita = other.osvita;
        rikNar = other.rikNar;
        vik = other.vik;
        cout << "Stvoreno osoby kopiyuvannyam\n";
    }

    ~People() {
        cout << "Znyshcheno osoby: " << prizvyshche << endl;
    }

    void obchyslytyVik() {
        time_t t = time(0);
        tm* now = localtime(&t);
        int potochniyRik = now->tm_year + 1900;
        vik = potochniyRik - rikNar;
    }

    void input() {
        cin.ignore();
        cout << "Vvedit prizvyshche: ";
        getline(cin, prizvyshche);
        cout << "Vvedit krainu: ";
        getline(cin, kraina);
        cout << "Vvedit stat (cholovik/zhinka): ";
        getline(cin, stat);
        cout << "Vvedit osvit? (visha/srednya/insha): ";
        getline(cin, osvita);
        cout << "Vvedit rik narodzhennya: ";
        cin >> rikNar;
        obchyslytyVik();
    }

    void output() const {
        cout << "Prizvyshche: " << prizvyshche
             << ", Kraina: " << kraina
             << ", Stat: " << stat
             << ", Osvita: " << osvita
             << ", Rik narodzhennya: " << rikNar
             << ", Vik: " << vik << endl;
    }

    string getOsvita() const { return osvita; }
    int getVik() const { return vik; }
    string getStat() const { return stat; }
};

void vyshchaOsvita(const vector<People>& people, int minVik) {
    cout << "\nHromadyany z vyshchoyu osvitoyu i viko? > " << minVik << ":\n";
    for (vector<People>::const_iterator it = people.begin(); it != people.end(); ++it){
        if (it->getOsvita() == "visha" && it->getVik() > minVik){
            it->output();
        }
    }
}

bool porivnyatyStat(const People& p, const string& stat) {
    return p.getStat() == stat;
}

void vydalytyStat(vector<People>& people, const string& stat) {
    vector<People>::iterator it = people.begin();
    while (it != people.end()) {
        if (porivnyatyStat(*it, stat)) {
            it = people.erase(it);
        } else {
            ++it;
        }
    }
}

int main() {
    vector<People> peopleList;

    People p1;
    p1.input();
    People p2;
    p2.input();
    peopleList.push_back(p1);
    peopleList.push_back(p2);

    People pCopy(p1);
    peopleList.insert(peopleList.begin(), pCopy);

    cout << "\nVsi osoby:\n";
    for (size_t i = 0; i < peopleList.size(); ++i) {
    peopleList[i].output();
    }

    vyshchaOsvita(peopleList, 18);

    string targetStat;
    cout << "\nVvedit stat dlya vydalennya (cholovik/zhinka): ";
    cin.ignore();
    getline(cin, targetStat);

    vydalytyStat(peopleList, targetStat);

    cout << "\nSpysok pislya vydalennya osib zi stattyu '" << targetStat << "':\n";
    for (size_t i = 0; i < peopleList.size(); ++i){
        peopleList[i].output();
    }
    return 0;
}
