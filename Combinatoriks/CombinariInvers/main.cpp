#include <bits/stdc++.h>

using namespace std;

const int MOD = 20173333;
int cerinta, k, n, add, rez, fact[100008], inv[100008], sir[100009];

int combinari(int n1, int k1)
{
    if(k1 == 0) return 1;
    return 1ll * fact[n1] * inv[k1] % MOD * inv[n1 - k1] % MOD;
}

int pw(int baza, int exp)
{
    int rez = 1;
    while(exp > 0)
    {
        if(exp % 2 == 1) rez = 1ll * rez * baza % MOD;
        baza = (1ll * baza * baza) % MOD;
        exp /= 2;
    }

    return rez;
}

int main()
{
    cin >> n >> k;

    fact[1] = 1;
    for(int i = 2; i <= n; i++)
        fact[i] = 1ll * fact[i - 1] * i % MOD;
    inv[n] = pw(fact[n], MOD - 2);
    for(int i = n - 1; i >= 1; i--)
        inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;

    cout << combinari(n, k);

    return 0;
}