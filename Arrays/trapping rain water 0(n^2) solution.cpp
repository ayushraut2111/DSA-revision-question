// in trapping rain water problem we can not collect water at the walls so we've to find the solution in between the first
//  and last bar, so at every point find the maximum in left and right and select the minimum from both and substract from
//  the current element and add in ans
#include <bits/stdc++.h>
using namespace std;
int traprain(int a[], int n)
{
    int water = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int lmax = a[i];
        for (int j = 0; j < i; j++)
        {
            lmax = max(lmax, a[j]);
        }
        int rmax = a[i];
        for (int j = i + 1; j < n; j++)
        {
            rmax = max(rmax, a[j]);
        }
        water += min(rmax, lmax) - a[i];
    }
    return water;
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
    cout << traprain(a, n);
}