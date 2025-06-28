#include <bits/stdc++.h>
using namespace std;
/// submultimi
/*
n = 3> 1, 2, 3
{1}, {2}, {3}
{1,2} {1,3} {2,3}
{1, 2, 3}

2^n-1
*/
int a[20], n, i, j, k;
int main()
{
    cin >> n;
    k = 1 << n;
    for (int i = 1; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j)) cout << j + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}