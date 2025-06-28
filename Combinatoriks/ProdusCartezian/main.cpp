#include <bits/stdc++.h>
using namespace std;
/** produs cartezian
3 multimi
multimea 1: 3 elemente 1, 2, 3
multimea 2: 2 elemente 1, 2
multimea 3: 2 elemente 1, 2
Produsul cartezian
1 1 1
1 1 2
1 2 1
1 2 2
2 1 1
2 1 2
2 2 1
2 2 2
3 1 1
3 1 2
3 2 1
3 2 2
**/

void afis(int arr[], int& n)
{
    for (int i = 1; i <= n; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}

int currElemProdus[120000];
void ProdusCartezian(int nrElem[], int& n, int p)
{
    for (int i = 1; i <= nrElem[p]; i++)
    {
        currElemProdus[p] = i;
        if (p != n) ProdusCartezian(nrElem, n, p + 1);
        else afis(currElemProdus, n);
    }
}

int n, nrElem[8];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nrElem[i];
    }
    ProdusCartezian(nrElem, n, 1);
    return 0;
}