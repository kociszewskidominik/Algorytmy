# Algorytm 11

## Treść zadania


Loptr, używając swoich zdolności do podróżowania w czasie, postanawia przewidzieć własną lokalizację w różnych momentach historycznych i alternatywnych rzeczywistościach. Jego celem jest zrozumienie, w jakich okresach czasowych i wymiarach jest najbardziej prawdopodobne, że będzie mógł zostać odnaleziony lub zlokalizowany przez inne postacie, takie jak Siekiera, analityk Suibom czy agenci YBS.


Loptr przypisał numery wymiarom i epokom, w których może się znaleźć:
- 0 - starożytny Rzym,
- 1 - Boski dwór,
- 2 - nowoczesna Ziemia,
- 3 - alternatywna linia czasowa,
- 4 - królestwo ognistych karłów,
- 5 - YBS.


## WEJŚCIE


Program na wejście otrzymuje dwie godziny w formacie HH:mm, które mówią o przedziale czasowym do zweryfikowania, a następnie przyjmuje numer wymiaru lub epoki, w której Loptr może się znaleźć.


0 < HH <= 24


0 <= mm < 60

## WYJŚCIE


Należy wypisać jakie jest prawdopodobieństwo pojawienia się Loptra, w wybranym wymiarze w danym przedziale czasowy. Wynik powinien być podany z dokładnością do dwóch miejsc po przecinku.


## PRZYKŁADOWE DANE WEJŚCIOWE


8:00
22:00
0


## PRZYKŁADOWA FUNKCJA:
```cpp
int Loptr(int HH, int mm){
	if(HH >= 8 && HH < 15) return 0;
	else if(HH >= 15 && HH < 22) return 1;
	return 2;
}
```

## PRZYKŁADOWE DANE WYJŚCIOWE


0.50


### UWAGA


Zadanie powinno być rozwiązane metodą Monte Carlo, która idealnie nadaje się do symulacji prawdopodobieństw w złożonych, niepewnych scenariuszach, takich jak wielowymiarowe podróże w czasie i przestrzeni, gdzie tradycyjne metody mogą nie być wystarczające.


## ROZWIĄZANIE
```cpp
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
```


Wczytanie danych na potrzeby zadania.


Przedziały czasowe:
- `godzina1`
- `godzina2`


Epoka w której Loptr może się znaleźć - `epoka`.
```cpp
    string godzina1, godzina2;
    int epoka;
    cin >> godzina1 >> godzina2 >> epoka;
```

Pobranie z całej godziny, godzin i minut za pomocą `substr()`, zmiana na int `stoi()` i przypisanie do zmiennych.
```cpp
    int hh1 = stoi(godzina1.substr(0,2));
    int mm1 = stoi(godzina1.substr(3,2));
    int hh2 = stoi(godzina2.substr(0,2));
    int mm2 = stoi(godzina2.substr(3,2));
```
Zamieniamy godziny na minuty.
```cpp
    int start = hh1 * 60 + mm1;
    int koniec = hh2 * 60 + mm2;
```
Zmienna `N` oznacza liczbę prób w metodzie Monte Carlo, im więcej tym prawdopodobieństwo będzie dokładniejsze.


`licznik` pokazuje ile razy wylosowany czas pasował do wybranej epoki.
```cpp
    int N = 1000000;
    int licznik = 0;
```
Pętla wykonuje się `N` razy. Losujemy losową liczbę z przedziału **[start, koniec)**, dodając do tego `start` upewniamy się, że nie zaczynamy od północy, tylko faktycznie od pierwszej godziny. Zamieniamy wymiar na godziny i minuty. Jeśli funkcja `Loptr()` zwróci liczbę równą epoce to licznik się zwiększa. 
```cpp
for(int i = 0; i < N; ++i){
        int wymiar = start + rand() % (koniec - start);
        int HH = wymiar / 60;
        int mm = wymiar % 60;

        if(Loptr(HH, mm) == epoka) {
            licznik++;
        }
    }
```
`licznik` dzielimy przez `N` by uzyskać zbliżone prawdopodobieństwo, zamieniamy na typ **double** i przypisujemy do zmiennej `wynik`.
Następnie ustawiamy precyzję na dwa miejsca po przecinku i wypisujemy rozwiązanie.
```cpp
    double wynik = (double)licznik / N;
    cout << fixed << setprecision(2) << wynik << endl;
```
