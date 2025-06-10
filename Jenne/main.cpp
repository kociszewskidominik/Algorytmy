#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool porownanie(char szablon, char tekst) {
    if (szablon == 'a') {
        return (tekst >= 'a' && tekst <= 'z');
    }
    if (szablon == 'A') {
        return (tekst >= 'A' && tekst <= 'Z');
    }
    if (szablon == '0') {
        return (tekst >= '0' && tekst <= '9');
    }
    if (szablon == '.') {
        return (tekst == '.' || tekst == '?' || tekst == '!' || tekst == ',' || tekst == ';' || tekst == ':' || tekst == '-');
    }
    return (szablon == ' ' && tekst == ' ');
}

vector<int> dasdas(const string& szablon) {
    int dlugosc = szablon.size();
    vector<int> pi(dlugosc);
    int prefiks = 0;

    for (int i = 1; i < dlugosc; ++i) {
        while (prefiks > 0 && !porownanie(szablon[prefiks], szablon[i])) {
            prefiks = pi[prefiks - 1];
        }
        if (porownanie(szablon[prefiks], szablon[i])) {
            ++prefiks;
        }

        pi[i] = prefiks;
    }

    return pi;
}

bool czypasuja(const string& szablon) {
    int dlugosc = szablon.size();
    vector<int> pi = dasdas(szablon);
    int prefiks = 0;
    char temp;

    while (cin.get(temp) && temp != '\n') {
        while (prefiks > 0 && !porownanie(szablon[prefiks], temp)) {
            prefiks = pi[prefiks - 1];
        }
        if (porownanie(szablon[prefiks], temp)) {
            ++prefiks;
        }
        if (prefiks == dlugosc) {
            return true;
        }
    }

    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    string szablon;

    if (!getline(cin, szablon)) {
        return 0;
    }

    bool ok = czypasuja(szablon);

    if(ok) {
        cout << "T";
    }
    else {
        cout << "N";
    }

    return 0;
}