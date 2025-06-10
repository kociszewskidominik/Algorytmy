#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

struct Punkt {
    double x;
    double y;
};

bool porownaj(const Punkt &a, const Punkt &b) {
    if (a.x != b.x) {
        return a.x < b.x;
    }

    return a.y < b.y;
}

double iloczyn(const Punkt &O, const Punkt &A, const Punkt &B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

bool wczytaj(int ilosc, vector<Punkt> &punkty) {
    punkty.resize(ilosc);

    for (int i = 0; i < ilosc; i++) {
        if (scanf("%lf %lf", &punkty[i].x, &punkty[i].y) != 2) {
            return false;
        }
    }

    return true;
}

vector<Punkt> otoczka(vector<Punkt> &punkty) {
    sort(punkty.begin(), punkty.end(), porownaj);
    vector<Punkt> otoczka;
    int temp;

    for (int i = 0; i < (int)punkty.size(); i++) {
        Punkt pkty = punkty[i];

        while ((int)otoczka.size() >= 2) {
            temp = (int)otoczka.size();

            if (iloczyn(otoczka[temp-2], otoczka[temp-1], pkty) <= 0) {
                otoczka.pop_back();
            }

            else break;
        }

        otoczka.push_back(pkty);
    }

    int rozmiar = (int)otoczka.size() + 1;
    for (int i = (int)punkty.size() - 2; i >= 0; i--) {
        Punkt pkty = punkty[i];

        while ((int)otoczka.size() >= rozmiar) {
            temp = (int)otoczka.size();

            if (iloczyn(otoczka[temp-2], otoczka[temp-1], pkty) <= 0) {
                otoczka.pop_back();
            }

            else break;
        }

        otoczka.push_back(pkty);
    }

    otoczka.pop_back();

    return otoczka;
}

double pole(const vector<Punkt> &otoczka) {
    double suma = 0.0;
    int rozmiar = (int)otoczka.size();

    for (int i = 0; i < rozmiar; i++) {
        int j = (i + 1) % rozmiar;

        suma += otoczka[i].x * otoczka[j].y - otoczka[j].x * otoczka[i].y;
    }

    return fabs(suma) * 0.5;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int N;

    if (scanf("%d", &N) != 1) {
        return 0;
    }

    if (N < 3) {
        printf("0.000\n");
        return 0;
    }

    vector<Punkt> punkty;

    if (!wczytaj(N, punkty)) {
        return 0;
    }

    vector<Punkt> o = otoczka(punkty);

    double p = pole(o);
    printf("%.3f\n", p);

    return 0;
}