// in max consecutive flip groups the max no of difference between group is 1 it is either only 0 and 1( 101 int his eg is both last digits
// are same then the max diff is 1 either in 1010 when last digits are different it is same)
// and the 2nd group is minimum times so in any case flip the second group(0 or 1)

#include <bits/stdc++.h>
using namespace std;
void maxflips(int a[], int n)
{
    int x = -1;
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] != a[i])
        {
            x = a[i];
            break;
        }
    }

    if (x == -1)
        cout << 0 << endl;
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] != a[i + 1] && a[i] != x)
            {
                cout << "from " << i + 1 << " to ";
            }
            else if (a[i] != a[i + 1] && a[i] == x)
            {
                cout << i << endl;
            }
        }
        if (a[n - 1] == x)
            cout << n - 1 << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    maxflips(a, n);
}