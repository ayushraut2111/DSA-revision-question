#include <bits/stdc++.h>
using namespace std;
void nextpermutation(int a[], int n)
{
    if (n == 1)
    {
        return;
    }
    int i, j;
    for (i = n - 2; i >= 0; i--) // find the number from last which is just smallest from its right one  eg. in 123 2 is the first element from last which is just smallest from its right one
    {
        if (a[i] < a[i + 1]) // stop where we found the nmber which is just smallest than its right one
            break;
    }
    if (i < 0) // if there is no such number then simply reverse the array
    {
        reverse(a, a + n);
    }
    else
    {
        for (j = n - 1; j >= i; j--) // int this step we check if it is the very first element of the array which is just smallest so in this case we have to change the whole number
        {
            if (a[j] > a[i]) // eg. 132 we have to change it to 213 so start searching from the last again and when we find the first number which is greater than the prev found number
                break;       // thens stop
        }
    }
    swap(a[i], a[j]);          // swap the both number
    reverse(a + i + 1, a + n); // reverse from leftmost smallest swapped +1 to last element ............ // reverse all the next element from the first swapped index because the min is at the last
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
    nextpermutation(a, n);
    for (auto x : a)
        cout << x << endl;
}