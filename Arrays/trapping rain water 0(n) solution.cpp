#include <bits/stdc++.h>
using namespace std;
int traprain(int a[], int n)
{
    int water = 0;
    int lmax[n], rmax[n];
    lmax[0] = a[0];
    rmax[n - 1] = a[n - 1];
    for (int i = 1; i < n; i++) // finding the max element from the left side by traversing from the left side
    {
        lmax[i] = max(a[i], lmax[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) // finding the max element from the rights side by traversing from the right side
    {
        rmax[i] = max(a[i], rmax[i + 1]);
    }
    for (int i = 1; i < n - 1; i++)
    {
        water += min(rmax[i], lmax[i]) - a[i];
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