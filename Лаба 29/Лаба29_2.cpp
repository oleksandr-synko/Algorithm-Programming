#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

bool isVowel(char c){
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

char randPrugolosni(){
    string cons = "bcdfghjklmnpqrstvwxyz";
    return cons[rand() % cons.length()];
}

char randomGolosni(){
    string vowels = "aeiou";
    return vowels[rand() % vowels.length()];
}

int main(){
    srand(time(0));

    int n = 5;
    vector<vector<char> > matrix(n, vector<char>(n));

    // заповненн€ матриц≥
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j || i + j == n - 1){
                matrix[i][j] = randomGolosni();
            }else{
                matrix[i][j] = randPrugolosni();
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }

    cout << "Vedit slovo dla poshyky: ";
    string word;
    cin >> word;
    int len = word.length();

    //ѕошук слова
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= n - len; j++){
            bool found = true;
            for(int k = 0; k < len; k++){
                if(matrix[i][j + k] != word[k]){
                    found = false;
                    break;
                }
            }
            if(found){
                cout << "Znaideno v radku: " << i+1 << ", " << j+1 << " - " << i+1 << ", " << j+len << endl;
            }
        }
    }

    // пошук в стовпц€х
    for(int j = 0; j < n; j++){
        for(int i = 0; i <= n - len; i++){
            bool found = true;
            for(int k = 0; k < len; k++){
                if(matrix[i + k][j] != word[k]){
                    found = false;
                    break;
                }
            }if(found){
                cout << "Znaideno v stovpcax: " << i + 1 << ", " << j + 1 << " - " << i + len << ", " << j + 1 << endl;
            }
        }
    }
    return 0;
}

