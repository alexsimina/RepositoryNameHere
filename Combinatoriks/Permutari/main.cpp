#include <bits/stdc++.h>

using namespace std;

int n, elems[10], a, b;
int main()
{

    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        elems[i - a + 1] = i;
    }
    n = b - a + 1;
    do
    {
        for (int i = 1; i <= n; i++)
        {
            cout << elems[i] << ' ';
        }
        cout << '\n';

    }while (next_permutation(elems + 1, elems + n + 1));

    return 0;
}