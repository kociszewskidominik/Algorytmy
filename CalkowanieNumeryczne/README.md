# Algorytm 10

## Treść zadania
Bohaterem ostatniego opowiadania jest nauczyciel chemii o imieniu pochodzącym jeszcze ze średniowiecznej Polski, Walcerz. Walcerz Czarny mieszka w województwie małopolskim i zajmuje się edukacją młodzieży. Niestety u naszego bohatera zostaje zdiagnozowany rak w trzecim stadium, a lekarze rokują, że pozostały mu jedynie dwa lata życia. Naszego bohatera życie nie oszczędza, a złe rzeczy doświadczają go na każdym kroku. Mimo wszystko, po usłyszeniu prognoz od lekarzy, mężczyzna wyzbywa się wszelkich lęków i pragnąc zabezpieczyć swoją rodzinę finansowo decyduje się wkroczyć do niebezpiecznego świata napojów chłodzących (bezalkoholowych rzecz jasna 🙂). Nasz bohater zaczyna produkować napoje, w których skład wchodzi między innymi C10H15N. Z całą inicjatywą pomaga mu jego najlepszy student Jensen Różowy.


Aby napoje sprzedawały się, jak najlepiej należy zapewnić im najlepszy smak. Waclerz wraz z Jensem sprzedają w końcu napoje chłodzące, a jak mówi psychologia smaku temperatura jest jednym z czynników, który wpływa na doznania smakowe. W związku z powyższym student wpadł na pomysł, że należy dopasować proporcje substancji tak, aby napój smakował najlepiej schłodzony.


Utrzymywanie tworzonych napoi w odpowiednio niskiej temperaturze jest ogromnym wyzwaniem. W szczególności, że są to początki biznesu i nasi bohaterowie nie mają środków na zaangażowanie osób trzecich lub na zakup profesjonalnych lodówek. W wyniku tego, Czarny decyduje się wykorzystać do tego swoje stare akwarium. Chcąc utrzymywać napoje w optymalnej temperaturze wypełnił je częściowo lodowatą wodą i wkłada do niego butelki. Waclerz często sięga po napoje, pobiera z nich próbki i odkłada je z powrotem. Skutkiem czego nie wszystkie butelki są pełne. Pojemność akwarium nie jest jednak nieskończona. W pewnym momencie woda się przeleje. Nasz bohater boi się, że wtedy jego żona Bogumiła zrobi straszną awanturę i nakryje jego proceder. Mężczyzna jest w stanie łatwo stwierdzić ile centymetrów od dna znajduje się napój w butelce jednak w żaden sposób nie wie jak przeliczyć to na objętość. Utrudniają mu to również nieregularne kształty butelki. Z pomocą przyszedł mu producent butelek, który na etykiecie opisał matematyczną funkcją kształt pojemnika. Jest to połowa jego przekroju. Pomóż naszemu bohaterowi oszacować po której butelce woda w akwarium się przeleje.


## Wejście:
W pierwszej linii wejścia program otrzymuje trzy liczby naturalne x, y oraz z będące rozmiarami akwarium w cm. Następnie wczytywana jest wartość p będąca stopniem wypełnienia akwarium wodą. W kolejnym kroku program wczytuje liczbę n a potem n liczb zmiennoprzecinkowych j opisujących wypełnienie butelki. Zakładamy, że butelka ma pomijalnie cienkie ścianki i jest pomijalnie lekka. Do sprawdzenia promienia butelki w dowolnej odległości od podstawy wykorzystaj funkcję wbudowaną double butelka(double cm). Podstawa butelki zawsze znajduje się w punkcie 0.

## Wyjście:
Na wyjściu program powinien wypisać po której butelce akwarium się przepełni. Butelki są numerowane od 1. Jeżeli nie dojdzie do przelania wody wyświetlany jest komunikat "NIE".


**0 < x, y, z < 100**


**0 < p < 1**


**0 < n <= 150**


## Przykładowe wejście:
30 30 20


0.9


5


2.1


3.0


4.1


5.7


1.1


## Przykładowe wyjście:


3




Funkcja w przykładzie jest zdefiniowana następująco
```cpp
  double butelka(double cm) {
	return 10 - (cm-2) * (cm-2);
}
```
Uwaga:


Program powinien wykorzystywać samodzielnie zaimplementowane całkowanie numeryczne.


## ROZWIĄZANIE
```cpp
#include <iostream>
#include <cmath>

using namespace std;

int objetosc(int x, int y, int z) {
    int V = x * y * z;

    return V;
}

double wypelnienie(int V, double p) {
    return p * V;
}

double objetoscbutelki(double j) {
    double dh = 0.01;
    int N = (int)ceil(j/dh);
    double V = 0.0;

    for(int i = 0; i < N; i++) {
        double h0 = i * dh;
        double h1 = (i + 1) * dh;

        if(h1 > j) {
            h1 = j;
        }

        double r0 = butelka(h0);
        if(r0 < 0) {
            r0 = 0;
        }

        double r1 = butelka(h1);
        if(r1 < 0) {
            r1 = 0;
        }

        V += ((r0 * r0 + r1 * r1) / 2) * (h1 - h0);
    }

    V *= M_PI;

    return V;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int x, y, z, n;
    double p;

    cin >> x >> y >> z;
    cin >> p;
    cin >> n;

    double obj = objetosc(x, y, z);
    double woda = wypelnienie(obj, p);

    for(int i = 0; i < n; i++) {
        double j;
        cin >> j;

        double Vb = objetoscbutelki(j);
        woda += Vb;

        if(woda > obj) {
            cout << (i + 1) << '\n';
            return 0;
        }
    }

    cout << "NIE";
    return 0;
}
```
W funkcji `objetosc()` liczymy za pomocą wzoru objętość akwarium, by wiedzieć ile maksymalnie wody się zmieści.
```cpp
int objetosc(int x, int y, int z) {
    int V = x * y * z;

    return V;
}
```
Funkcja `wyplenienie()` zwraca ile teraz faktycznie wody **jest** w akwarium.
```cpp
double wypelnienie(int V, double p) {
    return p * V;
}
```
Funkcja `objetoscbutelki()` przyjmuje `j` - wysokość do której butelka jest wypełniona, `dh` to warstwa na którą dzielimy przedział od 0 do `j`.


`N` to liczba kroków, zaokrąglamy do góry za pomocą `ceil()` żeby pokryć cały zakres.


`V` - sumator objętości.


W pętli przechodzimy po wszystkich warstwach, `h0` to dolna krawędź warstwy, a `h1` górna. Gdy górna warstwa wyjdzie poza `j` to skracamy ją do `j`.


`r0` i `r1` to promienie przekroju obu warstw.


Jeżeli kształt butelki kończy się wcześniej, traktujemy promień jako 0.


`V` to wynik całkowania, na koniec mnożymy przez stałą pi - `M_PI`, aby otrzymać faktyczną objętość i zwracamy wynik
```cpp
double objetoscbutelki(double j) {
    double dh = 0.01;
    int N = (int)ceil(j/dh);
    double V = 0.0;

    for(int i = 0; i < N; i++) {
        double h0 = i * dh;
        double h1 = (i + 1) * dh;

        if(h1 > j) {
            h1 = j;
        }

        double r0 = butelka(h0);
        if(r0 < 0) {
            r0 = 0;
        }

        double r1 = butelka(h1);
        if(r1 < 0) {
            r1 = 0;
        }

        V += ((r0 * r0 + r1 * r1) / 2) * (h1 - h0);
    }

    V *= M_PI;

    return V;
}
```
- `x`, `y`, `z` - wymiary akwarium.
- `p` - stopień jego wypełnienia.
- `n` - liczba butelek.

`obj` - cała objętość akwarium, `woda` - w jakim stopniu jest wypełnione.


Iterujemy po ilości butelek, za każdym razem wczytując `j`, czyli wysokość słupa napoju w butelce. Wywołujemy funkcje `objetoscbutelki()`, która za pomocą numerycznej całki wyznacz objętość cieczy do wysokości `j` i wynik zapisujemy w `Vb`.


Do dotychczasowej ilości wody dodajemy objętość butelki. Gdy objętości mamy więcej niż dostępnej w akwarium wypisujemy natchmiast numer butelki i zwracamy 0.
```cpp
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int x, y, z, n;
    double p;

    cin >> x >> y >> z;
    cin >> p;
    cin >> n;

    double obj = objetosc(x, y, z);
    double woda = wypelnienie(obj, p);

    for(int i = 0; i < n; i++) {
        double j;
        cin >> j;

        double Vb = objetoscbutelki(j);
        woda += Vb;

        if(woda > obj) {
            cout << (i + 1) << '\n';
            return 0;
        }
    }

    cout << "NIE";
    return 0;
}
```


## ZŁOŻONOŚĆ:
W najgorszym przypadku, gdy będziemy musieli przejść przez wszystkie butelki - O(n), gdzie `n` to liczby butelek.
W najlepszy, gdy pierwsza butelka spowoduje przepełnienie - O(1).
