#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main(){
    string godzina1, godzina2;
    int epoka;
    cin >> godzina1 >> godzina2 >> epoka;

    int hh1 = stoi(godzina1.substr(0,2));
    int mm1 = stoi(godzina1.substr(3,2));
    int hh2 = stoi(godzina2.substr(0,2));
    int mm2 = stoi(godzina2.substr(3,2));

    int start = hh1 * 60 + mm1;
    int koniec = hh2 * 60 + mm2;

    int N = 1000000;
    int licznik = 0;


    for(int i = 0; i < N; ++i){
        int wymiar = start + rand() % (koniec - start);
        int HH = wymiar / 60;
        int mm = wymiar % 60;

        if(Loptr(HH, mm) == epoka) {
            licznik++;
        }
    }

    double wynik = (double)licznik / N;
    cout << fixed << setprecision(2) << wynik << endl;

    return 0;
}