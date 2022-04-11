#include <bits/stdc++.h>
using namespace std;
int maxdiff(int a[], int n)
{
    int minval = a[0];
    int res = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        res = max(res, a[i] - minval); // at every index keep checking if this index is giving the max difference
        minval = min(minval, a[i]);    // always remember the min element from left while moving right by checking at every index whether we are getting min element from prev or not
    }
    return res;
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
    cout << maxdiff(a, n);
}