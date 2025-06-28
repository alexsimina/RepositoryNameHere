#include <bits/stdc++.h>

using namespace std;

struct NrMare
{
    int nrCif, cif[4000];
};

ostream& operator<<(ostream& out, const NrMare& a)
{
    for (int i = a.nrCif - 1; i >= 0; i--)
    {
        out << a.cif[i];
    }
    out << '\n';

    return out;
}

istream& operator>>(istream& in, NrMare& a)
{
    string s;
    in >> s;
    a.nrCif = s.length();
    for (int i = 0; i < a.nrCif; i++)
    {
        a.cif[i] = s[a.nrCif - 1 - i] - '0';
    }

    return in;
}

NrMare operator*(const NrMare &a, const NrMare &b)
{
    NrMare rez;
    memset(&rez, 0, sizeof(rez));
    rez.nrCif = a.nrCif + b.nrCif;
    for (int i = 0; i < a.nrCif; i++)
    {
        for (int j = 0; j < b.nrCif; j++)
        {
            rez.cif[i + j] += a.cif[i] * b.cif[j];
        }
    }

    int inPlus{}, index{};
    while (index < rez.nrCif)
    {
        rez.cif[index] += inPlus;
        inPlus = rez.cif[index] / 10;
        rez.cif[index] %= 10;
        index++;
    }

    while (rez.nrCif > 1 && rez.cif[rez.nrCif - 1] == 0)
        rez.nrCif--;

    return rez;
}

NrMare operator+(const NrMare &a, const NrMare &b)
{
    NrMare rez;
    memset(&rez, 0, sizeof(rez));
    rez.nrCif = max(a.nrCif, b.nrCif) + 1;

    for (int i = 0; i < rez.nrCif; i++)
    {
        rez.cif[i] += a.cif[i] + b.cif[i];
        rez.cif[i + 1] += rez.cif[i] / 10;
        rez.cif[i] %= 10;
    }

    while (rez.nrCif > 1 && rez.cif[rez.nrCif - 1] == 0)
        rez.nrCif--;

    return rez;
}

NrMare operator/(const NrMare &a, const int b)
{
    //if (b == 0) return {};
    NrMare rez;
    memset(&rez, 0, sizeof(rez));

    int rest = 0, index = a.nrCif - 1;
    while (index >= 0 && b > rest)
    {
        rest = rest * 10 + a.cif[index];
        index--;
    }
    rez.cif[index + 1] = rest / b;
    rez.nrCif = index + 2;
    rest %= b;
    for (int i = index; i >= 0; i--)
    {
        rest = rest * 10 + a.cif[i];
        rez.cif[i] = rest / b;
        rest %= b;
    }
    return rez;
}

NrMare operator-(const NrMare &a, const NrMare &b)
{
    NrMare rez;
    memset(&rez, 0, sizeof(rez));
    rez.nrCif = max(a.nrCif, b.nrCif);

    for (int i = 0; i < rez.nrCif; i++)
    {
        rez.cif[i] = a.cif[i] - b.cif[i];
        if (rez.cif[i] < 0)
        {
            rez.cif[i] += 10;
            rez.cif[i + 1]--;
        }
    }

    while (rez.nrCif > 0 && rez.cif[rez.nrCif - 1] == 0)
        rez.nrCif--;

    return rez;
}

bool operator<(const NrMare &a, const NrMare &b)
{
    if (a.nrCif != b.nrCif)
        return a.nrCif < b.nrCif;

    for (int i = a.nrCif - 1; i >= 0; i--)
    {
        if (a.cif[i] != b.cif[i])
            return a.cif[i] < b.cif[i];
    }

    return false;
}

bool operator==(const NrMare &a, const NrMare &b)
{
    if (a.nrCif != b.nrCif)
        return false;

    for (int i = a.nrCif - 1; i >= 0; i--)
    {
        if (a.cif[i] != b.cif[i])
            return false;
    }

    return true;
}

NrMare sqrt(const NrMare &a)
{
    NrMare rez;
    memset(&rez, 0, sizeof(rez));
    rez.nrCif = a.nrCif;
    NrMare unu = {1, {1}};
    NrMare s = unu, d = a;
    while (s - unu < d) // s <= d
    {
        NrMare mij = (s + d) / 2;
        if (mij * mij == a) return mij;
        if (mij * mij < a) s = mij + unu;
        else d = mij - unu;
    }

    return s - unu;
}
NrMare a;
NrMare toZecimale = {23, {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}};
bool esteMinus;

int main()
{
    cin >> a;
    if(a.cif[a.nrCif - 1] == -3)
    {
        esteMinus = true;
        a.nrCif--;
        a.cif[a.nrCif] = 0;
    }

    NrMare rez = sqrt(toZecimale * a);
    for (int i = rez.nrCif - 1; i >= 11; i--)
        cout << rez.cif[i];
    cout << '.';
    for (int i = 10; i >= 3; i--)
        cout << rez.cif[i];
    if(esteMinus)
        cout << 'i';

    return 0;
}
