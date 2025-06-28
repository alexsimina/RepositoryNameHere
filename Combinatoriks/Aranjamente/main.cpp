#include <bits/stdc++.h>
using namespace std;
/** aranjamente
n = 3, k = 2;
1 2
1 3
2 1
2 3
3 1
3 2
**/

int a[20], n, k, folosit[20];

void aranjamente(int p)
{
    if (p == k + 1)
    {
        for (int j = 1; j <= k; j++)
        {
            cout << a[j] << " ";
        }
        cout << '\n';
    }

    else for (int j = 1; j <= n; j++)
    {
        if (folosit[j] == 0)
        {
            folosit[j] = 1;
            a[p] = j;
            aranjamente(p + 1);
            folosit[j] = 0;
        }
    }
}

int main()
{
    cin >> n >> k;
    aranjamente(1);
}