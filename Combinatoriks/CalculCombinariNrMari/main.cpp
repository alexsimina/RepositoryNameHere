#include <bits/stdc++.h>
#pragma GCC optimize "trapv"
using namespace std;

struct intMare
{
    int nrCifre, cifre[1002];
};

void afisIntMare(const intMare a)
{
    for (int i = a.nrCifre - 1; i >= 0; i--)
    {
        cout << a.cifre[i];
    }
}

intMare intTointMare(int i)
{
    intMare rez{};
    do
    {
        rez.cifre[rez.nrCifre] = i % 10;
        rez.nrCifre++;
        i /= 10;
    }while (i);

    return rez;
}
intMare operator*(const intMare &a, const intMare b)
{
    intMare rez{};
    rez.nrCifre = a.nrCifre + b.nrCifre;

    for (int i = 0; i < a.nrCifre; i++)
    {
        for (int j = 0; j < b.nrCifre; j++)
        {
            rez.cifre[i + j] += a.cifre[i] * b.cifre[j];
        }
    }

    int rest{};
    for (int i = 0; i < rez.nrCifre; i++)
    {
        rez.cifre[i] += rest;
        rest = rez.cifre[i] / 10;
        rez.cifre[i] %= 10;
    }

    int i = rez.nrCifre - 1;
    while (i > 0 && rez.cifre[i] == 0)
    {
        rez.nrCifre--;
        i--;
    }
    return rez;
}

long long int n, k, factori[502];
intMare aranj = {1, {1}};

int main()
{
    cin >> n >> k;

    for (int i = 1; i <= k; i++)
    {
        int x = i, d = 2;
        while (x > 1)
        {
            int putere{};
            while (x % d == 0)
            {
                putere++;
                x /= d;
            }
            factori[d] += putere;
            d++;

            if (d * d > x)
            {
                factori[x]++;
                x = 1;
            }
        }
    }

    for (int i = n; i >= n - k + 1; i--)
    {
        long long int factorii[502]{};
        int x = i, d = 2;
        while (x > 1)
        {
            int putere{};
            while (x % d == 0)
            {
                putere++;
                x /= d;
            }

            factorii[d] += putere;
            d++;
            if (d * d > x)
            {
                factorii[x]++;
                x = 1;
            }
        }

        for (int j = 2; j < 502; j++)
        {
            if (factorii[j] && factori[j])
            {
                int deScazut = min(factorii[j], factori[j]);
                factori[j] -= deScazut;
                factorii[j] -= deScazut;
            }
        }

        int newi = 1;
        for (int j = 2; j < 502; j++)
        {
            while (factorii[j])
            {
                factorii[j]--;
                newi *= j;
            }
        }

        aranj = aranj * intTointMare(newi);
    }

    afisIntMare(aranj);

    return 0;
}