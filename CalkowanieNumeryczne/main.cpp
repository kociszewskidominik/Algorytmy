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